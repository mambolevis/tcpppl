// Created by Samvel Khalatyan on Nov 30, 2013
// Copyright (c) 2013 Samvel Khalatyan. All rights reserved
//
// Use of this source code is governed by a MIT-style license that can be
// found in the LICENSE file.
//
// (*1) Given two char*'s pointing into an array, find and output the number
//      of characters between the two pointed-to characters (zero if they
//      point to the same element).

#include <chrono>
#include <cmath>
#include <iostream>
#include <random>

using std::cout;
using std::endl;

void *cast(char *p)
{
    return static_cast<void *>(p);
}

int main(int, char *[])
{
    std::default_random_engine e{
        std::chrono::system_clock::now().time_since_epoch().count()};
    std::uniform_int_distribution<int> d{0, 9};
    auto index = std::bind(d, e);

    char array[] {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j'};
    for(int i {0}; 5 > i; ++i)
    {
        int i1 = index();
        int i2 = index();

        char *p1 = array + i1;
        char *p2 = array + i2;

        cout << '[' << i1 << "]-[" << i2 << "] == " <<
            cast(p1) << " - " << cast(p2) <<
            " = " << std::abs(p1 - p2) << " chars" << endl;
    }
}
