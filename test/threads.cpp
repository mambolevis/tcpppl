// Created by Samvel Khalatyan on Nov 24, 2013
// Copyright (c) 2013 Samvel Khalatyan. All rights reserved
//
// Use of this source code is governed by a MIT-style license that can be
// found in the LICENSE file.
//
// Low-level communication b/w threads can be organized through locks on
// mutexes (mutual exclusion objects) and conditional variables thay are
// used to synchronize between threads.

#include <condition_variable>
#include <iostream>
#include <mutex>
#include <queue>
#include <thread>

#include "interface/print.h"

using std::condition_variable;
using std::cout;
using std::endl;
using std::mutex;
using std::queue;
using std::thread;
using std::unique_lock;

namespace test
{
    using tools::print;

    queue<int> mqueue; // FIFO for messages exchange between two threads
    mutex mmutex;
    condition_variable mcondition;

    void producer()
    {
        print("start producer");

        int iter = 10;  // number of messages to be sent
        while(iter)
        {
            unique_lock<mutex> lock(mmutex);    // guard write access to queue
            mqueue.push(iter);
            mcondition.notify_one();    // inform any waiting consumer(s) of
                                        // new message. Note: function does
                                        // nothing if consumer is not in a wait
                                        // state -> use predicate in consumer
                                        // in order to avoid dead lock.

            --iter;
        } // lock is automatically released

        print("producer has finished");
    }

    bool predicate()
        // let consumer go to wait mode if no messages are available,
        // otherwise skip wait mode, acquire lock and use queue.
    {
        return mqueue.size();
    }

    void consumer()
    {
        print("consumer runs");

        while(true)
        {
            unique_lock<mutex> lock(mmutex);    // guard read access to queue
            mcondition.wait(lock, predicate);   // wait to be notified

            int message = mqueue.front();
            mqueue.pop();
            lock.unlock();  // don't need to access queue any more.

            print("consumer:", message);
            
            if (1 == message)
                break;
        }

        print("consumer has finished");
    }
}

using test::consumer;
using test::producer;

int main(int argc, char *argv[])
{
    thread threads[] {
        thread(consumer),
        thread(producer)
    };

    // let all threads finish their job
    for(auto &t:threads)
        t.join();

    cout << "done" << endl;
}
