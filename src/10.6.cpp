// Created by Samvel Khalatyan on Dec 4, 2013
// Copyright (c) 2013 Samvel Khalatyan. All rights reserved
//
// Use of this source code is governed by a MIT-style license that can be
// found in the LICENSE file.
//
// Modify iota() from the previous exercise to take an extra ‘‘string length’’
// argument to make overflow less likely.

#include <cmath>
#include <iomanip>
#include <iostream>

#include "interface/10.5.h"

char *itoa(int i, char b[], const int &size)
    // make sure not more than N chars are output:
    //  - size includes sign of the value
    //  - size excludes trailing \0 char
{
    return ex_10_5::itoa(i % static_cast<int>(pow(10, (i < 0) ?
                                                      size - 1 :
                                                      size)),
                         b);
}

int main(int, char *[])
{
    using namespace std;

    for(const auto &x:{1, 20, 100, 123, 54, 250, 34223,
                       -13, -2458, -1532})
    {
        char buf[10];
        cout << setw(7) << x << ": " << itoa(x, buf, 3) << endl;
    }
}
