// Created by Samvel Khalatyan on Nov 30, 2013
// Copyright (c) 2013 Samvel Khalatyan. All rights reserved
//
// Use of this source code is governed by a MIT-style license that can be
// found in the LICENSE file.
//
// (*1) Write declarations for the following:
//          - a pointer to a character
//          - an array of 10 integers
//          - a reference to an array of 10 integers
//          - a pointer to an array of character strings
//          - a pointer to a pointer to a character
//          - a constant integer
//          - a pointer to a constant integer
//          - a constant pointer to an integer
//      Initialize each one.

#include <iostream>

#include "interface/8.1.h"

using std::cout;
using std::endl;

int main(int, char *[])
{
    cout << "        pointer to char: " << ex_8_1::p << ' ' << *ex_8_1::p << endl;
    cout << "      arrray of 10 ints: " << ex_8_1::a << ' ';
    for(int i{0}; 10 > i; ++i)
        cout << ex_8_1::a[i] << ' ';
    cout << endl;

    cout << "ref to array of 10 ints: " << ex_8_1::ra << ' ';
    for(int i{0}; 10 > i; ++i)
        cout << ex_8_1::ra[i] << ' ';
    cout << endl;

    cout << "pointer to array fo char strings: " << ex_8_1::ps << ' ' <<
        *ex_8_1::ps << endl;

    cout << "pointer to a pointer to a char: " << ex_8_1::ppc << ' ' <<
        *ex_8_1::ppc << endl;

    cout << "const int: " << ex_8_1::num << endl;

    cout << "pointer to const int: " << ex_8_1::pn << ' ' <<
        *ex_8_1::pn << endl;

    cout << "const pointer to int: " << ex_8_1::cpn << ' ' <<
        *ex_8_1::cpn << endl;
}
