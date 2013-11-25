// Created by Samvel Khalatyan on Nov 24, 2013
// Copyright (c) 2013 Samvel Khalatyan. All rights reserved
//
// Use of this source code is governed by a MIT-style license that can be
// found in the LICENSE file.

#include <future>
#include <iostream>
#include <numeric>
#include <thread>

using std::cout;
using std::endl;
using std::future;
using std::packaged_task;
using std::thread;

int sum(const int *from, const int &elements, int init)
{
    return std::accumulate(from, from + elements, init);
}

int main(int argc, char *argv[])
{
    const int size {100000};
    int collection[size];
    for(int i {0}; size > i; ++i)
        collection[i] = i + 1;

    using Task = int(const int *, const int &, int);

    packaged_task<Task> task1 {&sum};
    packaged_task<Task> task2 {&sum};

    future<int> f1 {task1.get_future()};
    future<int> f2 {task2.get_future()};

    const int half_size {size / 2};
    thread t1 {std::move(task1), collection, half_size, 0};
    thread t2 {std::move(task2), collection + half_size, half_size, 0};

    cout << "sum: " << size * (size + 1) / 2 <<  endl;
    cout << "sum (threads): " << f1.get() + f2.get() << endl;

    t1.join();
    t2.join();
}
