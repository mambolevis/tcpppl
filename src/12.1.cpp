// Created by Samvel Khalatyan on Dec 13, 2013
// Copyright (c) 2013 Samvel Khalatyan. All rights reserved
//
// Use of this source code is governed by a MIT-style license that can be
// found in the LICENSE file.
//
// (*1) Copy all even non-zero elements of an int[] into a vector<int>.
//      Use a pointer and ++ for the traversal.

#include <iostream>
#include <vector>

using namespace std;

struct Array
    // keep pointer to an array and its size
{
    int *array;
    int size;
};

ostream &operator <<(ostream &os, const Array &a)
    // print array in a nice way
{
    for(int *p {a.array}, size {a.size}; size--; p++)
    {
        os << *p;
        if (size)
            os << ' ';
    }

    return os;
}

ostream &operator <<(ostream &os, const vector<int> &v)
    // print elements of vector
{
    for(const auto &x:v)
    {
        os << x;
        if (&x != &v.back())
            os << ' ';
    }

    return os;
}

int main(int, char *[])
{
    int numbers[] {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    vector<int> numbers_copy;

    for(int *p {numbers}, size {sizeof(numbers) / sizeof(int)};
            size;
            --size, ++p)
        if (*p && not (*p % 2))
            numbers_copy.push_back(*p);

    cout << "numbers: " << Array{numbers, sizeof(numbers) / sizeof(int)} << endl;
    cout << "   copy: " << numbers_copy << endl;
}
