// Created by Samvel Khalatyan on Nov 24, 2013
// Copyright (c) 2013 Samvel Khalatyan. All rights reserved
//
// Use of this source code is governed by a MIT-style license that can be
// found in the LICENSE file.
//
// (*2) Initialize a vector<int> with the elements 5, 9, −1, 200, and 0.
//      Print it. Sort is, and print it again.

#include <algorithm>
#include <iomanip>
#include <iostream>
#include <vector>

using std::cout;
using std::endl;
using std::setw;
using std::sort;
using std::vector;

std::ostream &operator <<(std::ostream &os, const vector<int> &v)
{
    auto *back = &v.back();
    for(const auto &x:v)
    {
        os << x;

        if (&x != back)
            os << ' ';
    }

    return os;
}

void sort(vector<int> &v)
{
    sort(v.begin(), v.end());
}

int main(int argc, char *argv[])
{
    vector<int> values {5, 9, -1, 200, 0};
    cout << values << endl;

    cout << "-- sorted" << endl;
    sort(values);
    cout << values << endl;
}
