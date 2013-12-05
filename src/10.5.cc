// Created by Samvel Khalatyan on Dec 4, 2013
// Copyright (c) 2013 Samvel Khalatyan. All rights reserved
//
// Use of this source code is governed by a MIT-style license that can be
// found in the LICENSE file.

#include "interface/10.5.h"

char *ex_10_5::itoa(int i, char b[])
{
    int left_index {0}; // the index of the starting string
    if (i < 0)
    {
        b[0] = '-';
        ++left_index;
        i *= -1;
    }

    int right_index {left_index}; // index of the end of the string
    while(i > 0)
        // note that all numbers will be stored in reverse order, e.g.
        // lower digits first
    {
        int a = i % 10;
        i /= 10;
        b[right_index++] = '0' + a;
    }
    b[right_index] = '\0'; // make it c-style string
    
    // reverse the sequence of numbers 
    //
    for(; left_index < --right_index; ++left_index)
    {
        char tmp {b[left_index]};
        b[left_index] = b[right_index];
        b[right_index] = tmp;
    }

    return b;
}
