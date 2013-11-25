// Created by Samvel Khalatyan on Nov 24, 2013
// Copyright (c) 2013 Samvel Khalatyan. All rights reserved
//
// Use of this source code is governed by a MIT-style license that can be
// found in the LICENSE file.

#include <future>
#include <iostream>
#include <memory>
#include <thread>
#include <vector>

#include "interface/tools.h"

using std::cout;
using std::endl;
using std::future;
using std::packaged_task;
using std::thread;
using std::unique_ptr;
using std::vector;

template<typename Fn, typename R>
    class Task
        // wrapper for a task, future and thread
    {
        public:
            // create task for given function
            //
            // the future is automatically extracted from the task
            //
            Task(Fn &&function):
                _task{&function},
                _future{_task.get_future()}
            {}

            // Prevent copy
            //
            Task(const Task &) = delete;
            Task &operator =(const Task &) = delete;
            
            // Prevent move
            //
            Task(Task &&) = delete;
            Task &operator =(Task &&) = delete;

            template<typename... Tail>
                void run(Tail&&... tail)
                    // run task with arguments if there are any
                {
                    if (!_thread)
                        _thread.reset(new thread{std::move(_task), tail...});
                }

            void join()
                // let thread finish its job
            {
                if (_thread)
                    _thread->join();
            } 

            R get()
            {
                return _future.get();
            }

        private:
            packaged_task<Fn> _task;    // task for given function
            future<R> _future;          // task's future
            unique_ptr<thread> _thread; // thread where task will be run
    };

int main(int argc, char *argv[])
{
    const long size {10000};  // array size
    const int threads_num {7};  // number of threads to be created

    // fill array with data (linear function)
    //
    long collection[size];
    for(long i {0}; size > i; ++i)
        collection[i] = i + 1;

    // alias to Task and pointer: tired of typing
    //
    using ITask = Task<long(const long *, const long &, long),
                       long>;
    using ITaskP = unique_ptr<ITask>;

    // create threads
    //
    vector<ITaskP> threads;
    for(int i {0}; threads_num > i; ++i)
        threads.push_back(ITaskP{new ITask{tools::sum}});

    // run threads
    //
    { 
        // number of elements to be processed by each thread but last
        //
        const unsigned long delta {size / threads.size()}; 
        int i {0};
        for(auto &t:threads)
        {
            t->run(collection + i * delta,
                   &t == &threads.back() ?  size - i * delta : delta,
                   0);

            ++i;
        }
    }

    // calculate sum of results
    //
    long sum = 0;
    for(auto &t:threads)
        sum += t->get();

    // print the expected and calculated results; compare the two
    //
    const long expected_sum {size * (size + 1) / 2};

    cout << " expected sum: " << expected_sum << endl;
    cout << "sum (threads): " << sum << endl;

    cout << "validation: " << (expected_sum == sum ? "pass" : "fail") << endl;

    // let each thread cleanly exit
    //
    // technically threads should finish their task by this moment
    //
    for(auto &t:threads)
        t->join();
}
