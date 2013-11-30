// Created by Samvel Khalatyan on Nov 30, 2013
// Copyright (c) 2013 Samvel Khalatyan. All rights reserved
//
// Use of this source code is governed by a MIT-style license that can be
// found in the LICENSE file.

#ifndef EXERCISE_8_3
#define EXERCISE_8_3

namespace ex_8_3
{
    // unsigned char
    extern unsigned char &rc;
    
    // const unsigned char
    extern const unsigned char &crc;

    // pointer to integer
    extern int *&rpi;

    // pointer to pointer to char
    extern char **&rppc;

    // pointer to array of char
    extern char *&rpc;

    // array of 7 pointers to int
    using pint = int *;
    using a7pint = pint [7];
    extern a7pint &rapi;

    // pointer to an array of 7 pointers to int
    extern a7pint *&rpapi;

    // array of 8 arrays of 7 pointers to int
    using a8a7pint = a7pint [8];
    extern a8a7pint &raapi;
}

#endif
