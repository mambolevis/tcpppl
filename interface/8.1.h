// Created by Samvel Khalatyan on Nov 30, 2013
// Copyright (c) 2013 Samvel Khalatyan. All rights reserved
//
// Use of this source code is governed by a MIT-style license that can be
// found in the LICENSE file.

#ifndef EXERCISE_8_1
#define EXERCISE_8_1

namespace ex_8_1
{
    // a pointer to a character
    extern char *p;

    // an array of 10 integers
    extern int a[10];

    // a reference to an array of 10 integers
    using ints = int [10];
    extern ints &ra;

    // a pointer to an array of character strings
    extern const char **ps;

    // a pointer to a pointer to a character
    extern char **ppc;

    // a constant integer
    extern const int num;

    // a pointer to a constant integer
    extern const int *pn;

    // a constant pointer to an integer
    extern int *const cpn;
}

#endif
