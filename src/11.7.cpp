// Created by Samvel Khalatyan on Dec 11, 2013
// Copyright (c) 2013 Samvel Khalatyan. All rights reserved
//
// Use of this source code is governed by a MIT-style license that can be
// found in the LICENSE file.
//
// (*2) Implement and test these functions:
//
//          strlen(), which returns the length of a C-style string;
//          strcpy(), which copies a C-style string into another;
//          strcmp(), which compares two C-style strings.
//
//      Consider what the argument types and return types ought to be.
//      Then compare your functions with the standard library versions as
//      declared in <cstring> (<string.h>) and as specified in §43.4.

#include <cmath>
#include <cstring>
#include <iostream>

#include "gtest/gtest.h"
#include "interface/11.7.h"

using namespace std;

TEST(StringTest, Length)
{
    const char *s {"Hello world!"};

    EXPECT_EQ(ex_11_7::strlen(s), strlen(s));
}

TEST(StringTest, Copy)
{
    const char *s {"Hello from Earth!"};

    char buf1[255] {}; // let's have extra space
    char buf2[255] {};

    EXPECT_EQ(ex_11_7::strcpy(s, buf1), strlen(strcpy(buf2, s)));
    EXPECT_STREQ(buf1, buf2);
}

TEST(StringTest, Compare)
{
    const char *s1 {"hello"};
    const char *s2 {"Hello"};
    const char *s3 {"hallo"};
    const char *s4 {"hollo"};

    EXPECT_EQ(ex_11_7::strcmp(s1, s1), strcmp(s1, s1));
    EXPECT_EQ(ex_11_7::strcmp(s1, s2), strcmp(s1, s2) / abs(strcmp(s1, s2)));
    EXPECT_EQ(ex_11_7::strcmp(s1, s3), strcmp(s1, s3) / abs(strcmp(s1, s3)));
    EXPECT_EQ(ex_11_7::strcmp(s1, s4), strcmp(s1, s4) / abs(strcmp(s1, s4)));
}

int main(int argc, char *argv[])
{
    ::testing::InitGoogleTest(&argc, argv);

    return RUN_ALL_TESTS();
}
