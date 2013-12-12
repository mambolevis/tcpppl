// Created by Samvel Khalatyan on Dec 12, 2013
// Copyright (c) 2013 Samvel Khalatyan. All rights reserved
//
// Use of this source code is governed by a MIT-style license that can be
// found in the LICENSE file.
//
// (*2) Write a function cat() that takes two C-style string arguments and
//      returns a string that is the concatenation of the arguments.
//      Use new to find store for the result.

#include <cstring>
#include <iostream>
#include <memory>

#include "gtest/gtest.h"

using namespace std;

shared_ptr<const char> cat(const char *, const char *);

const char *str1;
const char *str2;

TEST(CatTest, Concatenation)
{
    shared_ptr<const char> result {cat(str1, str2)};

    char buf[255];
    strcpy(buf, str1);
    strcat(buf, str2);

    // two results should have the same lengths and content
    EXPECT_EQ(strlen(result.get()), strlen(buf));
    EXPECT_STREQ(result.get(), buf);
}

int main(int argc, char *argv[])
{
    if (1 == argc)
    {
        str1 = "Hello ";
        str2 = "World!";
    }
    else if (3 == argc)
    {
        str1 = argv[1];
        str2 = argv[2];
    }
    else
    {
        cerr << "invalid number of arguments" << endl;
        return 1;
    }

    ::testing::InitGoogleTest(&argc, argv);

    return RUN_ALL_TESTS();
}

shared_ptr<const char> cat(const char *s1, const char *s2)
{
    return shared_ptr<char>{new char[1] {'\0'}};
}
