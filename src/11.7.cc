// Created by Samvel Khalatyan on Dec 11, 2013
// Copyright (c) 2013 Samvel Khalatyan. All rights reserved
//
// Use of this source code is governed by a MIT-style license that can be
// found in the LICENSE file.

#include "interface/11.7.h"

size_t ex_11_7::strlen(const char *s)
{
    size_t i {0};
    while(*s)
    {
        ++s;
        ++i;
    }
    return i;
}

size_t ex_11_7::strcpy(const char *from, char *to)
{
    size_t i {0};
    do
        // copy then check the input char for '\0'
    {
        *to++ = *from;

        ++i;
    }
    while(*from++);

    return i;
}

int ex_11_7::strcmp(const char *s1, const char *s2)
{
    while(*s1 && *s2)
    {
        if (*s1 < *s2)
            return -1;
        else if (*s1 > *s2)
            return 1;

        ++s1;
        ++s2;
    }

    if (!*s1 && *s2)
        return -1;
    else if (*s1 && !*s2)
        return 1;
    else
        return 0;
}
