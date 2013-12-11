// Created by Samvel Khalatyan on Dec 11, 2013
// Copyright (c) 2013 Samvel Khalatyan. All rights reserved
//
// Use of this source code is governed by a MIT-style license that can be
// found in the LICENSE file.
//
// (*1) Fully parenthesize the following expressions:
//
//         a = b + c ∗ d << 2 & 8
//         a & 077 != 3
//         a == b || a == c && c < 5 c = x != 0
//         0 <= i < 7
//         f(1,2)+3
//         a = − 1 + + b −− − 5
//         a = b == c ++ a=b=c=0
//         a[4][2] ∗= ∗ b ? c : ∗ d ∗ 2 a−b,c=d

#include "gtest/gtest.h"

int a {1};
int b {2};
int c {3};
int d {4};

TEST(PriorityTest, First)
{
    EXPECT_EQ(b + c * d << 2 & 8, ((b + (c * d)) << 2) & 8);
}

TEST(PriorityTest, Second)
{
    EXPECT_EQ(a & 077 != 3, a & (077 != 3));
}

TEST(PriorityTest, Third)
{
    EXPECT_EQ(a == b || a == c && c < 5,
              ((a == b) || (a == c)) && (c < 5));
}

TEST(PriorityTest, Fourth)
{
    int x {a};

    EXPECT_EQ(c = x != 0, c = (x != 0));
}

TEST(PriorityTest, Fifth)
{
    int i {a};

    EXPECT_EQ(0 <= i < 7, (0 <= i) < 7);
}

constexpr int f(const int &a, const int &b)
{
    return a + b;
}

TEST(PriorityTest, Sixth)
{
    EXPECT_EQ(f(1,2)+3, (f(1,2))+3);
}

TEST(PriorityTest, Seventh)
{
    int b1 {b};
    int b2 {b};

    int a1 = - 1 + + b1 -- - 5;
    int a2 = ((- 1) + (+ (b2 --))) - 5;

    EXPECT_EQ(a1, a2);
}

TEST(PriorityTest, Eighth)
{
    int b1 {};
    int b2 {};
    int c1 {1};
    int c2 {1};

    int a1 = b1 == c1 ++;
    int a2 = (b2 == (c2 ++));

    EXPECT_EQ(a1, a2);
}

TEST(PriorityTest, Nineth)
{
    int a1 = b = c = 0;
    int a2 = (b = (c = 0));

    EXPECT_EQ(a1, a2);
}

TEST(PriorityTest, Tenth)
{
    int a[5][5] {};
    int vb {1};
    int vd {2};

    int *b {&vb};
    int *d {&vd};

    a[4][2] *= * b ? c : * d * 2;

    (a[2])[4] *= ((* b) ? c : ((* d) * 2));

    EXPECT_EQ(a[4][2], a[2][4]);
}

TEST(PriorityTest, Eleventh)
{
    
    int a1 = (a - b, c = d);
    int a2 = ((a - b), (c = d));

    EXPECT_EQ(a1, a2);
}

int main(int argc, char *argv[])
{
    ::testing::InitGoogleTest(&argc, argv);

    return RUN_ALL_TESTS();
}
