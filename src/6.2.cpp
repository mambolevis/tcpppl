// Created by Samvel Khalatyan on Nov 26, 2013
// Copyright (c) 2013 Samvel Khalatyan. All rights reserved
//
// Use of this source code is governed by a MIT-style license that can be
// found in the LICENSE file.
//
// (*1.5)   Write a program with two treads: one that writes hello every second
//          and one that writes world! every second.

#include <chrono>
#include <thread>

#include "interface/print.h"    // thread safe print to COUT

using std::thread;

using tools::print;

void task(const std::string &message)
{
    // Use thead_id in all prints
    //
    std::thread::id id {std::this_thread::get_id()};
    print("thread", id, "will write message '", message, "'");

    // write the message N times
    //
    std::chrono::seconds seconds(1);
    for(int i {1}; 5 >= i; ++i)
    {
        std::this_thread::sleep_for(seconds);   // sleep every M seconds

        print(message);
    }

    print("thread", id, "exits");
}

int main(int argc, char *argv[])
{
    // Run threads
    //
    thread threads[] {
        thread(task, "hello"),
        thread(task, "world!")
    };

    // let threads finish
    //
    for(auto &t:threads)
        t.join();
}
