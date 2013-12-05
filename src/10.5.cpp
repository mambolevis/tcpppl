// Created by Samvel Khalatyan on Dec 4, 2013
// Copyright (c) 2013 Samvel Khalatyan. All rights reserved
//
// Use of this source code is governed by a MIT-style license that can be
// found in the LICENSE file.
//
// (*2) Write a function itoa(int i, char b[]) that creates a string
//      representation of i in b and returns b.

#include <iomanip>
#include <iostream>

#include "interface/10.5.h"

int main(int, char *[])
{
    using namespace std;

    for(const auto &x:{1, 20, 100, 123, 54, 250, 34223,
                       -13, -2458, -1532})
    {
        char buf[10];
        cout << setw(7) << x << ": " << ex_10_5::itoa(x, buf) << endl;
    }
}
