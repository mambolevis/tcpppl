// Created by Samvel Khalatyan on Dec 2, 2013
// Copyright (c) 2013 Samvel Khalatyan. All rights reserved
//
// Use of this source code is governed by a MIT-style license that can be
// found in the LICENSE file.
//
// (*1) Define a struct with a member of each of the types:
//          bool, char, int, long, double, and long double
//      Order the members so as to get the largest size of the struct
//      and the smallest size of the struct.

#include <iostream>

#include "interface/7.6.h"

using std::cout;
using std::endl;

using namespace ex_7_6;

struct LargestSize
{
    bool b;
    long double ld;
    int i;
    double d;
    char c;
    long l;
};

struct SmallestSize
{
    long double ld;
    double d;
    long l;
    int i;
    char c;
    bool b;
};

int main(int, char *[])
{
    using ex_7_6::print::size::operator <<;

    cout << "-- structures and sizes" << endl;
    cout << Info<LargestSize>{} << endl;
    cout << Info<SmallestSize>{} << endl;
}
