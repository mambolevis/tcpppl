// Created by Samvel Khalatyan on Dec 23, 2013
// Copyright (c) 2013 Samvel Khalatyan. All rights reserved
//
// Use of this source code is governed by a MIT-style license that can be
// found in the LICENSE file.

#include <iostream>

using namespace std;

// there is NO version of f() with an rvalue argument
void f(int &n)
{
    cout << "f(int &)" << endl;
}

void f(const int &n)
{
    cout << "f(const int &)" << endl;
}

// g() has an overloaded version that accepts an rvalue
void g(int &n)
{
    cout << "g(int &)" << endl;
}

void g(const int &n)
{
    cout << "g(const int &)" << endl;
}

void g(int &&n)
{
    cout << "g(int &&)" << endl;
}

int main(int, char *[])
{
    int n {2};
    const int cn {3};

    cout << "-- f(...)" << endl;
    f(n);
    f(cn);
    f(5);   // there is NO function definition that accepts an rvalue
            // therefore a const lvalue reference is called

    cout << "-- g(...)" << endl;
    g(n);
    g(cn);
    g(5);   // there is a version of g() function that accepts an rvalue
}
