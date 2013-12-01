// Created by Samvel Khalatyan on Nov 30, 2013
// Copyright (c) 2013 Samvel Khalatyan. All rights reserved
//
// Use of this source code is governed by a MIT-style license that can be
// found in the LICENSE file.
//
// (*1) Define functions:
//           f(char)
//           g(char&)
//           h(const char&)
//      Call them with the arguments 'a', 49, 3300, c, uc, and sc,
//      where c is a char, uc is an unsigned char, and sc is a signed char.
//      Which calls are legal? Which calls cause the compiler to introduce
//      a temporary variable?

#include <iostream>

using std::cout;
using std::endl;

void f(char c)
    // copy object
{
    cout << "f(char '" << c << "')" << endl;
}

void g(char &c)
    // lvalue reference
{
    cout << "g(char &'" << c << "')" << endl;
}

void h(const char &c)
    // const lvalue reference
{
    cout << "h(const char &'" << c << "')" << endl;
}

void i(char &&c)
    // rvalue
{
    cout << "i(char &&'" << c << "')" << endl;
}

int main(int, char *[])
{
    char c {'c'};
    unsigned char uc {'u'};
    signed char sc {'s'};

    cout << "-- f calls" << endl;
    f('a');     // legal call, temp variable
    f(49);      // legal call, temp variable
                // implicit conversion int > char, safe: 49 < 127
    f(3300);    // legal call, temp variable
                // implicit conversion int > char, unsafe: 3300 > 127
    f(c);       // legal call
    f(uc);      // legal call, temp variable
                // implicit convertion unsigned char > char
    f(sc);      // legal call, temp variable
                // implicit conversion signed char > char
    cout << endl;

    cout << "-- g calls" << endl;
    // g('a');     // illegal call, temp variable is not accepted
    // g(49);      // illegal call, temp variable is not accepted
    // g(3300);    // illegal call, temp variable is not accepted
    g(c);       // legal call, exact match of types
    // g(uc);      // illegal call, type match requires temp variable
    // g(sc);      // illegal call, type match requires temp variable
    cout << endl;

    cout << "-- h calls" << endl;
    h('a');     // legal call, temp variable
    h(49);      // legal call, temp variable
                // implicit conversion int > char, safe: 49 < 127
    h(3300);    // legal call, temp variable
                // implicit conversion int > char, unsafe: 3300 > 127
    h(c);       // legal call
    h(uc);      // legal call, temp variable
                // implicit convertion unsigned char > char
    h(sc);      // legal call, temp variable
                // implicit conversion signed char > char
    cout << endl;

    cout << "-- i calls" << endl;
    i('a');     // legal call, temp variable
    i(49);      // legal call, temp variable
                // implicit conversion int > char, safe: 49 < 127
    i(3300);    // legal call, temp variable
                // implicit conversion int > char, unsafe: 3300 > 127
    // i(c);       // illegal call, lvalue is given but rvalue is needed
    i(uc);      // legal call, temp variable
                // implicit convertion unsigned char > char
    i(sc);      // legal call, temp variable
                // implicit conversion signed char > char
    cout << endl;
}
