// Created by Samvel Khalatyan on Dec 12, 2013
// Copyright (c) 2013 Samvel Khalatyan. All rights reserved
//
// Use of this source code is governed by a MIT-style license that can be
// found in the LICENSE file.
//
// (*2) Write a function rev() that takes a C-style string argument and
//      reverses the characters in it. That is, after rev(p) the last
//      character of p will be the first, etc.

#include <cstring>
#include <iostream>
#include <string>

#include "gtest/gtest.h"

using namespace std;

char *str;

// Concatenate two strings and return result
char *rev(char *);

TEST(RevTest, Reversion)
    // compare custom CAT with c-string concatenation functions
{
    string s1{str};
    string s2;
    for(auto iter = s1.rbegin(); s1.rend() != iter; ++iter)
    {
        s2 += *iter;
    }
    EXPECT_STRNE(s1.c_str(), s2.c_str());
    EXPECT_STREQ(str, s1.c_str());
    EXPECT_STRNE(str, s2.c_str());

    rev(str);

    // two results should have the same lengths and content
    EXPECT_EQ(strlen(str), s2.size());
    EXPECT_STRNE(str, s1.c_str());
    EXPECT_STREQ(str, s2.c_str());
}

int main(int argc, char *argv[])
    // the application may run by deault or with command line arguments. In
    // the latter case the two input strings will be cancatenated.
{
    char input[] {"Hello World!"};
    if (1 == argc)
        str = input;
    else if (2 == argc)
        str = argv[1];
    else
    {
        cerr << "invalid number of arguments" << endl;
        return 1;
    }

    ::testing::InitGoogleTest(&argc, argv);

    return RUN_ALL_TESTS();
}

char *rev(char *s)
{
    for(char *l {s},
             *r {s + strlen(s) - 1};
        l < r;
        ++l, --r)
    {
        char tmp = *l;
        *l = *r;
        *r = tmp;
    }

    return s;
}
