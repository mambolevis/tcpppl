// Created by Samvel Khalatyan on Nov 27, 2013
// Copyright (c) 2013 Samvel Khalatyan. All rights reserved
//
// Use of this source code is governed by a MIT-style license that can be
// found in the LICENSE file.
//
// (*1) Write a program that prints signed if plain chars are signed on your
//      implementation and unsigned otherwise.

#include <iostream>
#include <limits>

using std::cout;
using std::endl;

template<typename T>
    std::ostream &operator <<(std::ostream &os,
                              const std::numeric_limits<T> &nl)
    {
        return os << (std::numeric_limits<T>::is_signed ?
                      "signed" :
                      "unsigned");
    }

int main(int, char *[])
{
    cout << "   plain char: " << std::numeric_limits<char>{} << endl;
    cout << "  signed char: " << std::numeric_limits<signed char>{} << endl;
    cout << "unsigned char: " << std::numeric_limits<unsigned char>{} << endl;
}
