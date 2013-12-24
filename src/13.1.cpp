// Created by Samvel Khalatyan on Dec 24, 2013
// Copyright (c) 2013 Samvel Khalatyan. All rights reserved
//
// Use of this source code is governed by a MIT-style license that can be
// found in the LICENSE file.
//
// (*1) Write declarations for the following:
//
//          a function taking arguments of type pointer to character and
//          reference to integer and returning no value;
//
//          a pointer to such a function;
//
//          a function taking such a pointer as an argument;
//
//          a function returning such a pointer.
//
//      Write the definition of a function that takes such a pointer as
//      an argument and returns its argument as the return value.
//
//      Hint: Use a type alias (using).

#include <iostream>

using namespace std;

void a(char *);
void b(int &);

// pointer to functions: will be used as args or return types
using pa = void (*)(char *);
using pb = void (*)(int &);

// functions accepting pointer to function
void fa(pa);
void fb(pb);

// functions returning pointer to function
pa ra();
pb rb();

int main(int, char *[])
{
    char str[] {"Hello"};
    int num {10};

    a(str); cout << endl;
    b(num); cout << endl;

    fa(a); cout << endl;
    fb(b); cout << endl;


    ra()(str); cout << endl;
    rb()(num); cout << endl;
}

void a(char *arg)
{
    cout << "void a(char *" << arg << ")" << endl;
}

void b(int &arg)
{
    cout << "void b(int &" << arg << ")" << endl;
}

void fa(pa function_)
{
    cout << "-- void fa(" << function_ << ")" << endl;
    char str[] {"World"};
    function_(str);
}

void fb(pb function_)
{
    cout << "-- void fb(" << function_ << ")" << endl;
    int num {5};
    function_(num);
}

pa ra()
{
    cout << "-- pa *ra()" << endl;
    return a;
}

pb rb()
{
    cout << "-- pb *rb()" << endl;
    return b;
}
