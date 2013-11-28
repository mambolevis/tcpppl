// Created by Samvel Khalatyan on Nov 28, 2013
// Copyright (c) 2013 Samvel Khalatyan. All rights reserved
//
// Use of this source code is governed by a MIT-style license that can be
// found in the LICENSE file.
//
// (*2) What, on your system, are the largest and the smallest values of the
//      following types:
//          bool, char, short, int, long, long long, float, double,
//          long double, unsigned and unsigned long.

#include <iomanip>
#include <iostream>
#include <limits>

#include "interface/7.6.h"

using std::cout;
using std::endl;
using std::setw;

using ex_7_6::Info;

template<typename T>
    std::ostream &operator<<(std::ostream &os, const Info<T> &type)
        // automatically print name and size of the type
    {
        // std::type_info::name() returns mangled name in C++11, e.g. an
        // abbreviation that usually consists of 1-2 letters and hard to
        // read.
        //
        // The procedure below is how to demangle the name and get back
        // user-friendly name printed.
        //
        std::ios::fmtflags flags {os.flags()};

        os << setw(15) << ex_7_6::type_name(type) << " min: " <<
            setw(20);
        os.setf(std::ios::left);
        os << std::numeric_limits<T>::min() << " max: " <<
            std::numeric_limits<T>::max();

        os.flags(flags);

        return os;
    }

int main(int, char *[])
{
    cout << "-- built-in types" << endl;
    cout << Info<bool>{} << endl;
    cout << Info<char>{} << endl;
    cout << Info<wchar_t>{} << endl;
    cout << Info<short>{} << endl;
    cout << Info<int>{} << endl;
    cout << Info<long>{} << endl;
    cout << Info<long long>{} << endl;
    cout << Info<float>{} << endl;
    cout << Info<double>{} << endl;
    cout << Info<long double>{} << endl;
    cout << Info<unsigned>{} << endl;
    cout << Info<unsigned long>{} << endl;
}
