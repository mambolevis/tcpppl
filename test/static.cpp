// Created by Samvel Khalatyan on Dec 23, 2013
// Copyright (c) 2013 Samvel Khalatyan. All rights reserved
//
// Use of this source code is governed by a MIT-style license that can be
// found in the LICENSE file.

#include <iostream>

using namespace std;

void f(int n)
{
    using counter = decltype(n);

    for(counter i{n}; i; --i)
    {
        static counter static_n {0}; // initialized only once
        counter x {0};  // initialized n times

        cout << "static_n: " << static_n++ << " x: " << x++ << endl;

    }
}

int main(int, char *[])
{
    cout << "-- f(2)" << endl;
    f(2);

    cout << "-- f(3)" << endl;
    f(3);
}
