// Created by Samvel Khalatyan on Dec 01, 2013
// Copyright (c) 2013 Samvel Khalatyan. All rights reserved
//
// Use of this source code is governed by a MIT-style license that can be
// found in the LICENSE file.
//
// (*1) Define an array of strings in which the strings contain the names of
//      the months. Print those strings. Pass the array to a function that
//      prints those strings.

#include <iostream>

using std::cout;
using std::endl;

void print(const char **months, const int &size)
    // the array size has to be passed in addition to the pointer to array
    //
    // note: months is a pointer to the first element of the array which
    //       in turn has const char * type.
{
    for(int i {0}; size > i; ++i)
        cout << *(months + i) << endl;
}

int main(int, char *[])
{
    const char *months[] {"jan", "feb", "mar", "apr", "may", "jun", "jul",
                          "aug", "sep", "oct", "nov", "dec"};

    // months can be printed using range-based for loop b/c the array size
    // is known at this stage
    //
    cout << "-- direct print" << endl;
    for(const auto &m:months)
        cout << m << endl;
    cout << endl;

    // on the other hand array is cast to pointer to array and any information
    // about the array size is lost: the array is treated as ordinary pointer
    // in the function. Therefore an array size needs to be passed.
    //
    cout << "-- print via function call" << endl;
    print(months, 12);
}
