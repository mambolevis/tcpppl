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
#include <initializer_list>
#include <iostream>
#include <random>

using std::cout;
using std::endl;

template<typename T>
    void *cast(T *p)
    {
        return static_cast<void *>(p);
    }

template<typename T>
    void *cast(const T *p)
    {
        return static_cast<void *>(const_cast<T *>(p));
    }

template<typename T>
    void run(std::initializer_list<T> &&list)
    {
        std::default_random_engine e{
            std::chrono::system_clock::now().time_since_epoch().count()};
        std::uniform_int_distribution<int> d{0, list.size() - 1};
        auto index = std::bind(d, e);

        for(int i {0}; 10 > i; ++i)
        {
            int i1 = index();
            int i2 = index();

            const T *p1 = &*list.begin() + i1;
            const T *p2 = &*list.begin() + i2;

            cout << '[' << i1 << "]-[" << i2 << "] == " <<
                cast(p1) << " - " << cast(p2) <<
                " = " << std::abs(p1 - p2) << endl;
        }
    }

int main(int, char *[])
{
    run({'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j'});
}
