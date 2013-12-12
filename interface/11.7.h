// Created by Samvel Khalatyan on Dec 11, 2013
// Copyright (c) 2013 Samvel Khalatyan. All rights reserved
//
// Use of this source code is governed by a MIT-style license that can be
// found in the LICENSE file.

#ifndef EXERCISE_11_7
#define EXERCISE_11_7

#include <cstddef>

namespace ex_11_7
{
    // remembers: all c-style strings end with '\0' character

    // return size of a c-style string
    size_t strlen(const char *);

    // return number of chars copied
    size_t strcpy(const char * /* from */, char * /* to */);

    // compare two strings and return:
    //
    //  -1      if str1 < str2
    //  0       if str1 == str2
    //  1       if str1 > str2
    int strcmp(const char * /* str1 */, const char * /* str2 */);
}

#endif
