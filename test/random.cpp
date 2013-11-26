// Created by Samvel Khalatyan on Nov 26, 2013
// Copyright (c) 2013 Samvel Khalatyan. All rights reserved
//
// Use of this source code is governed by a MIT-style license that can be
// found in the LICENSE file.

#include <chrono>
#include <iostream>
#include <random>

using std::cout;
using std::endl;

int main(int argc, char *argv[])
{
    using generator = std::default_random_engine;
    using distribution = std::uniform_int_distribution<int>;

    generator g(std::chrono::system_clock::now().time_since_epoch().count());
    distribution d{1, 6};

    auto dice = std::bind(d, g);    // let dice act as a function

    for(int i {10}; i; --i)
        cout << dice() << endl;
}
