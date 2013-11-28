// Created by Samvel Khalatyan on Nov 28, 2013
// Copyright (c) 2013 Samvel Khalatyan. All rights reserved
//
// Use of this source code is governed by a MIT-style license that can be
// found in the LICENSE file.
//
// (*1.5)   Write a loop that prints out the values 4, 5, 9, 17, 12 without
//          using an array or a vector.

#include <iostream>

using std::cout;
using std::endl;

int main(int, char *[])
{
    for(const auto &x:{4, 5, 9, 17, 12})
        cout << x << endl;
}
