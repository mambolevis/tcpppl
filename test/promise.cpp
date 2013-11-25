// Created by Samvel Khalatyan on Nov 24, 2013
// Copyright (c) 2013 Samvel Khalatyan. All rights reserved
//
// Use of this source code is governed by a MIT-style license that can be
// found in the LICENSE file.

#include <chrono>
#include <functional>
#include <iostream>
#include <future>
#include <thread>

#include "interface/print.h"

using std::cout;
using std::endl;

namespace test
{
    class Consumer
    {
        public:
            Consumer(std::promise<int> &promise):
                _future{promise.get_future()}
            {}

            void operator()()
            {
                using tools::print;

                print("consumer started and waits for future");
                auto x = _future.get();
                print("consumer received:", x);
            }

        private:
            std::future<int> _future;
    };


    class Producer
    {
        public:
            Producer(std::promise<int> &promise,
                     const int &milliseconds=500):
                _promise{promise},
                _milliseconds{milliseconds}
            {}

            void operator()()
            {
                using tools::print;

                namespace this_thread = std::this_thread;
                namespace chrono = std::chrono;

                print("producer started and goes to sleep");
                this_thread::sleep_for(chrono::milliseconds(_milliseconds));
                _promise.set_value(500);
            }

        private:
            std::promise<int> &_promise;
            int _milliseconds;
    };
}

int main(int argc, char *argv[])
{
    std::promise<int> promise;

    std::thread threads[] {
        std::thread{test::Consumer(promise)},
        std::thread{test::Producer(promise)}
    };

    // let all threads finish their job
    for(auto &t:threads)
        t.join();

    cout << "done" << endl;

}
