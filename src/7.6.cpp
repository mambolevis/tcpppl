// Created by Samvel Khalatyan on Nov 27, 2013
// Copyright (c) 2013 Samvel Khalatyan. All rights reserved
//
// Use of this source code is governed by a MIT-style license that can be
// found in the LICENSE file.
//
// (*1.5)   Write a program that prints the sizes of the fundamental types, a
//          few pointer types, and a few enumerations of your choice. Use the
//          sizeof operator.

#include <cxxabi.h> // for demangle

#include <iomanip>
#include <iostream>
#include <typeinfo>
#include <string>

using std::cout;
using std::endl;
using std::setw;

template<typename T>
    struct Info{};

template<typename T>
    std::string type_name(const Info<T> &type)
    {
        int status;
        char *name {abi::__cxa_demangle(typeid(T).name(),
                                                  NULL,
                                                  NULL,
                                                  &status)};
        std::string name_ {name};
        std::free(name);

        return name_;
    }

template<typename T>
    std::ostream &operator<<(std::ostream &os, const Info<T> &type)
        // automatically print name and size of the type
    {
        // std::type_info::name() returns mangled name in C++11, e.g. an
        // abbreviation that usually consists of 1-2 letters and hard to
        // read.
        //
        // The procedure below is how to demangle the name and get back
        // user-friendly name printed.
        //
        os << setw(15) << type_name(type) << ": " << setw(2) << sizeof(T) << " B";

        return os;
    }

enum class Rainbow { red, orange, yellow, green, blue, indigo, violet };
enum class Light { red, yellow, green };

int main(int, char *[])
{
    cout << "-- built-in types" << endl;
    cout << Info<void>{} << endl;
    cout << Info<bool>{} << endl;
    cout << Info<char>{} << endl;
    cout << Info<wchar_t>{} << endl;
    cout << Info<int>{} << endl;
    cout << Info<long>{} << endl;
    cout << Info<long long>{} << endl;
    cout << Info<float>{} << endl;
    cout << Info<double>{} << endl;
    cout << Info<long double>{} << endl;

    cout << "-- pointers" << endl;
    cout << Info<int *>{} << endl;
    cout << Info<char *>{} << endl;
    cout << Info<double *>{} << endl;

    cout << "-- enumerations" << endl;
    cout << Info<Rainbow>{} << endl;
    cout << Info<Light>{} << endl;
}
