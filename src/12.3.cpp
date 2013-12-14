// Created by Samvel Khalatyan on Dec 13, 2013
// Copyright (c) 2013 Samvel Khalatyan. All rights reserved
//
// Use of this source code is governed by a MIT-style license that can be
// found in the LICENSE file.
//
// Write a simple loop calculating a sum of elements (like std::accumulate()).
// Write it in a dozen or more ways using:
//      for-statements
//      range-for statements
//      the for_each() algorithm
//      using indices
//      pointers
//      iterators
//      using ‘‘plain code’’
//      function objects
//      lambdas
//      using different element types
// See if you can find any performance differences between the different
// versions.

#include <algorithm>
#include <iomanip>
#include <iostream>
#include <iterator>
#include <numeric>
#include <string>
#include <vector>
#include <utility>

#include "gtest/gtest.h"

#include "interface/estd_chrono.h"
#include "interface/Timer.h"

using namespace std;
using Timer = tools::NanoTimer;

using estd::operator <<;

using result = pair<string, Timer::precision>;

vector<result> results;

ostream &operator <<(ostream &os, const vector<result> &r)
{
    int max_len {0};
    for_each(r.begin(), r.end(),
             [&max_len](const result &x) mutable
             {
                if (max_len < x.first.size()) max_len = x.first.size();
             });

    for(const auto &x:r)
        os << setw(max_len) << x.first << ": " << x.second << endl;

    return os;
}

struct Array
{
    const int *array;
    size_t size;
} input;

struct Iterator : iterator<input_iterator_tag, int>
{
    public:
        Iterator(const int *value): _value{value} {}

        Iterator &operator ++() { return (++_value, *this); }

        bool operator ==(const Iterator &i) const { return _value == i._value; }
        bool operator !=(const Iterator &i) const { return _value != i._value; }

        const int &operator *() { return *_value; }

    private:
        const int *_value;
};

const int *begin(const Array &a)
{
    return a.array;
}

const int *end(const Array &a)
{
    return a.array + a.size;
}

// -- algorithms
TEST(SumTest, ForStatement)
{
    Timer t;
    int sum {0};
    for(size_t s {input.size}; s--; sum += input.array[s]);
    t.stop();

    EXPECT_EQ(sum, accumulate(input.array, input.array + input.size, 0));

    const ::testing::TestInfo* const test_info =
          ::testing::UnitTest::GetInstance()->current_test_info();

    results.push_back(make_pair(test_info->name(), t.duration()));
}

TEST(SumTest, RangeFor)
{
    Timer t;
    int sum {0};
    for(const auto &x:input)
        sum += x;
    t.stop();

    EXPECT_EQ(sum, accumulate(input.array, input.array + input.size, 0));

    const ::testing::TestInfo* const test_info =
          ::testing::UnitTest::GetInstance()->current_test_info();

    results.push_back(make_pair(test_info->name(), t.duration()));
}

TEST(SumTest, ForEach)
{
    Timer t;
    int sum {0};
    for_each(input.array, input.array + input.size,
             [&sum](const int &x) { sum += x; });
    t.stop();

    EXPECT_EQ(sum, accumulate(input.array, input.array + input.size, 0));

    const ::testing::TestInfo* const test_info =
          ::testing::UnitTest::GetInstance()->current_test_info();

    results.push_back(make_pair(test_info->name(), t.duration()));
}

TEST(SumTest, Indices)
{
    Timer t;
    int sum {0};
    for(size_t i {0}; input.size > i; ++i)
        sum += input.array[i];
    t.stop();

    EXPECT_EQ(sum, accumulate(input.array, input.array + input.size, 0));

    const ::testing::TestInfo* const test_info =
          ::testing::UnitTest::GetInstance()->current_test_info();

    results.push_back(make_pair(test_info->name(), t.duration()));
}

TEST(SumTest, Pointers)
{
    Timer t;
    int sum {0};
    for(const int *p {input.array + input.size};
            --p >= input.array;
            sum += *p);
    t.stop();

    EXPECT_EQ(sum, accumulate(input.array, input.array + input.size, 0));

    const ::testing::TestInfo* const test_info =
          ::testing::UnitTest::GetInstance()->current_test_info();

    results.push_back(make_pair(test_info->name(), t.duration()));
}

TEST(SumTest, Iterators)
{
    Timer t;
    int sum {0};
    for(Iterator p {input.array}, end {input.array + input.size};
            p != end;
            ++p)
        sum += *p;
    t.stop();

    EXPECT_EQ(sum, accumulate(input.array, input.array + input.size, 0));

    const ::testing::TestInfo* const test_info =
          ::testing::UnitTest::GetInstance()->current_test_info();

    results.push_back(make_pair(test_info->name(), t.duration()));
}

TEST(SumTest, Functor)
{
    class Functor
    {
        public:
            Functor(int &sum): _sum{sum} {}

            void operator()(const int &x) { _sum += x; }

        private:
            int &_sum;
    };

    Timer t;
    int sum {0};
    for_each(begin(input), end(input), Functor(sum));
    t.stop();

    EXPECT_EQ(sum, accumulate(input.array, input.array + input.size, 0));

    const ::testing::TestInfo* const test_info =
          ::testing::UnitTest::GetInstance()->current_test_info();

    results.push_back(make_pair(test_info->name(), t.duration()));
}

TEST(SumTest, Lambda)
{

    Timer t;
    int sum {0};
    auto f = [&sum](const int &x) mutable { sum += x; };
    for(const int &x:input)
        f(x);
    t.stop();

    EXPECT_EQ(sum, accumulate(input.array, input.array + input.size, 0));

    const ::testing::TestInfo* const test_info =
          ::testing::UnitTest::GetInstance()->current_test_info();

    results.push_back(make_pair(test_info->name(), t.duration()));
}

int main(int argc, char *argv[])
{
    const int array[] {1, 2, 3, 4, 5, 6, 7, 8, 9};
    input = Array{array, static_cast<size_t>(sizeof(array) / sizeof(int))};

    ::testing::InitGoogleTest(&argc, argv);

    int gresult = RUN_ALL_TESTS();

    cout << "-- test resuls" << endl;
    cout << results << endl;

    return gresult;
}
