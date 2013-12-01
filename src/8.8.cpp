// Created by Samvel Khalatyan on Nov 30, 2013
// Copyright (c) 2013 Samvel Khalatyan. All rights reserved
//
// Use of this source code is governed by a MIT-style license that can be
// found in the LICENSE file.
//
// (*1.5)   What is the size of the array str in the following example:
//              char str[] = "a short string";
//          What is the length of the string "a short string"?

#include <cstring>
#include <iostream>

using std::cout;
using std::endl;

int main(int, char *[])
{
    char str[] {"a short string"};

    // go through each element of the array and count number of elements
    int array_size {0};
    for(const auto &x:str)
    {
        ++array_size;
    }

    cout << "size of the array: " << array_size << endl;
    // strlen(...) counts number of elements in the string until char(0)
    // is found
    cout << "length of the string: " << strlen(str) << endl;
}
