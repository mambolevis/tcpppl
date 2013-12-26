// Created by Samvel Khalatyan on Dec 26, 2013
// Copyright (c) 2013 Samvel Khalatyan. All rights reserved
//
// Use of this source code is governed by a MIT-style license that can be
// found in the LICENSE file.
//
// (*1) Write a factorial function that does not use recursion.

#include <gtest/gtest.h>

int factorial(int n)
{
    int res {n};
    while(--n)
    {
        res *= n;
    }

    return res;
}

int recursive_factorial(const int &n)
{
    if (1 >= n)
        return 1;

    return n * recursive_factorial(n - 1);
}

TEST(FactorialTest, Factorial)
{
    EXPECT_EQ(factorial(1), recursive_factorial(1));
    EXPECT_EQ(factorial(2), recursive_factorial(2));
    EXPECT_EQ(factorial(5), recursive_factorial(5));
    EXPECT_EQ(factorial(20), recursive_factorial(20));
    EXPECT_EQ(factorial(50), recursive_factorial(50));
}

int main(int argc, char *argv[])
{
    ::testing::InitGoogleTest(&argc, argv);

    return RUN_ALL_TESTS();
}
