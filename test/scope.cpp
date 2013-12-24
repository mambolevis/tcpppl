// Created by Samvel Khalatyan on Dec 24, 2013
// Copyright (c) 2013 Samvel Khalatyan. All rights reserved
//
// Use of this source code is governed by a MIT-style license that can be
// found in the LICENSE file.

#include <iostream>

using namespace std;

int f(const int &x)
{
    return x * 2;
}

int main(int argc, char *[])
{
    // one way to declare a function inside another one is to use lambda
    auto f = [](const int &x) -> int { return x * 3; };

    // another way is to use a callable object, e.g. functor
    struct Functor
    {
        int operator()(const int &x) { return x * 5; };
    };

    Functor functor;

    cout << "    ::f(4) = " << ::f(4) << endl;
    cout << "      f(4) = " << f(4) << endl;
    cout << "functor(4) = " << functor(4) << endl;
}
