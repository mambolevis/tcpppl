// Created by Samvel Khalatyan on Nov 25, 2013
// Copyright (c) 2013 Samvel Khalatyan. All rights reserved
//
// Use of this source code is governed by a MIT-style license that can be
// found in the LICENSE file.

#include <future>
#include <iostream>

#include "interface/tools.h"

using std::async;
using std::cout;
using std::endl;
using std::future;

int main(int argc, char *argv[])
{
    const long size {10000};  // array size
    const int max_calculators {7};  // number of calculators to be created

    // fill array with data (linear function)
    //
    long collection[size];
    for(long i {0}; size > i; ++i)
        collection[i] = i + 1;

    future<long> calculators[max_calculators];
    {
        // run calculators for each designated section
        //
        // async will automatically decide how many threads to run depending
        // on the system and its implementation 
        //
        const unsigned long delta {size / max_calculators}; 
        int i {0};
        int last {max_calculators - 1};
        for(auto &x:calculators)
        {
            x = async(tools::sum<long>, collection + i * delta,
                      last == i ? size - i * delta : delta,
                      0);

            ++i;
        }
    }

    // calculate sum of results
    //
    long sum = 0;
    for(auto &f:calculators)
        sum += f.get();

    // print the expected and calculated results; compare the two
    //
    const long expected_sum {size * (size + 1) / 2};

    cout << " expected sum: " << expected_sum << endl;
    cout << "sum (threads): " << sum << endl;

    cout << "validation: " << (expected_sum == sum ? "pass" : "fail") << endl;
}
