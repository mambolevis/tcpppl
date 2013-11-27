// Created by Samvel Khalatyan on Nov 26, 2013
// Copyright (c) 2013 Samvel Khalatyan. All rights reserved
//
// Use of this source code is governed by a MIT-style license that can be
// found in the LICENSE file.

#include <iomanip>
#include <iostream>
#include <type_traits>

using std::cout;
using std::endl;
using std::setw;

template<typename T>
    bool is_signed(const T &)
    {
        return std::is_signed<T>::value;
    }

int main(int, char *[])
{
    unsigned char c1 = 255;
    signed char c2 = 255;
    char c3 = 255;

    cout << "assign value 255 to different types of char and convert to int" <<
        endl;

    cout << setw(8) << (is_signed(c1) ? "signed" : "unsigned") <<
        " char > int: " << static_cast<int>(c1) << endl;

    cout << setw(8) << (is_signed(c2) ? "signed" : "unsigned") <<
        " char > int: " << static_cast<int>(c2) << endl;

    cout << setw(8) << (is_signed(c3) ? "signed" : "unsigned") <<
        " char > int: " << static_cast<int>(c3) << endl;
}
