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

// one of the ways to pass an actual array instead of pointer to the first
// element is to use reference. Unfortunately, one needs to specify the array
// size in that case and the size has to match the size of the array passed
// as an argument. This leads to inflexibility in the code.
//
// Therefore, it might be a better idea to use a template function that takes
// an array size as one of the parameters.
//
// The functions below demonstrate such technique
template<typename T, size_t N>
constexpr size_t size(T (&)[N])
{
    return N;
}

template<size_t N>
long long sum(const int (&array)[N])
{
    long long result {0};
    for(const auto &x:array)
        result += x;

    return result;
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

    // pass array along with its size by reference
    cout << "-- size(...)" << endl;
    constexpr int a[] {1, 2, 3};
    for(size_t i {0}, sz {size(a)}; sz > i; ++i)
    {
        cout << a[i] << ' ';
    }
    cout << endl << "sum: " << sum(a) << endl;

    constexpr const int b[10] {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    for(size_t i {0}, sz {size(b)}; sz > i; ++i)
    {
        cout << b[i] << ' ';
    }
    cout << endl << "sum: " << sum(b) << endl;
}
