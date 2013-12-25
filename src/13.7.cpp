// Created by Samvel Khalatyan on Dec 24, 2013
// Copyright (c) 2013 Samvel Khalatyan. All rights reserved
//
// Use of this source code is governed by a MIT-style license that can be
// found in the LICENSE file.
//
// (*2) Implement ssort() (§12.5) using a more efficient sorting algorithm.
//      Hint: sort() and qsort().

#include <cstdlib>
#include <iostream>

#include "interface/tools.h"

using namespace std;

using Compare = int (*)(const void *, const void *);

void ssort(void *base, size_t elements, size_t element_size, Compare compare)
    // forward sort to std::qsort
{
    qsort(base, elements, element_size, compare);
}

int int_cmp(const void *l, const void *r)
{
    return *static_cast<const int *>(l) - *static_cast<const int *>(r);
}

template<typename T>
ostream &operator <<(ostream &os, const vector<T> &args)
    // print vector of some elements
{
    for(const auto &arg:args)
        os << arg << ' ';

    return os;
}

template<size_t N>
ostream &operator <<(ostream &os, const int (&arr)[N])
    // print c-style array
{
    for(const auto &el:arr)
        os << el << ' ';

    return os;
}

void test_int()
    // manipulate c-style array
{
    int args[] { 40, 10, 100, 90, 20, 25 };
    cout << "-- raw int args" << endl;
    cout << args << endl;

    cout << "-- sort" << endl;
    ssort(args, 6, sizeof(args[0]), int_cmp);

    cout << "-- sorted int args" << endl;
    cout << args << endl;
}

void test_vint()
    // manipulate vector data
{
    vector<int> args { 40, 10, 100, 90, 20, 25 };
    cout << "-- raw vint args" << endl;
    cout << args << endl;

    cout << "-- sort" << endl;
    ssort(args.data(), args.size(), sizeof(args.front()), int_cmp);

    cout << "-- sorted vint args" << endl;
    cout << args << endl;
}

int main(int argc, char *argv[])
{
    test_int();
    cout << endl;

    test_vint();
}
