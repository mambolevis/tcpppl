// Created by Samvel Khalatyan on Nov 30, 2013
// Copyright (c) 2013 Samvel Khalatyan. All rights reserved
//
// Use of this source code is governed by a MIT-style license that can be
// found in the LICENSE file.
//
// (*1) Write a function that swaps (exchanges the values of) two integers.
//      Use int* as the argument type. Write another swap function using
//      int& as the argument type.

#include <iostream>

#include "interface/7.6.h"
#include "interface/8.4.h"

using std::cout;
using std::endl;

class Test
    // Monitor copy/move construction/assignment calls
{
    public:
        // default constructor
        Test(const int &id):
            _id(id)
        {
            cout << "Test::Test()"
               " _id:" << _id << endl;
        }

        // copy constructor
        Test(const Test &t):
            _id(t._id)
        {
            cout << "Test::Test(const Test &)"
               " _id:" << _id << endl;
        }

        // copy assignment
        const Test &operator =(const Test &t)
        { 
            _id = t._id;

            cout << "const Test &Test::operator =(const Test &)"
               " _id:" << _id << endl;

            return *this;
        }

        // move constructor
        Test(Test &&t):
            _id(t._id)
        {
            t._id = 0;

            cout << "Test::Test(Test &&)"
               " _id:" << _id << endl;
        }

        // move assignment
        const Test &operator =(Test &&t)
        { 
            _id = t._id;
            t._id = 0;

            cout << "const Test &Test::operator =(Test &&)"
               " _id:" << _id << endl;

            return *this;
        }

        // default destructor
        ~Test()
        {
            cout << "Test::~Test()"
               " _id:" << _id << endl;
        }

        operator int() const
        {
            return _id;
        }

    private:
        int _id;
};

template<typename T>
    void swap(T *&v1, T *&v2)
        // swap pointers rather than values pointed to
    {
        T *tmp {v1};
        v1 = v2;
        v2 = tmp;
    }

template<typename T>
    void swap(T &v1, T &v2)
        // move values between v1 and v2: way better than copying objects
        // since these can be large
    {
        using std::move;

        T tmp {move(v1)};
        v1 = move(v2);
        v2 = move(tmp);
    }

template<typename T>
    void run()
        // test swap with different types
    {
        using ex_7_6::Info;
        using ex_7_6::type_name;
        using ex_8_4::tools::cast;

        cout << "-- work with " << type_name(Info<T>{}) << endl;
        // construct two objects
        T v1 {98};
        T v2 {99};

        cout << "v1: " << v1 << endl;
        cout << "v2: " << v2 << endl;
        cout << endl;

        // swap two objects 
        cout << "> swap v1 and v2" << endl;
        swap(v1, v2);
        cout << "v1: " << v1 << endl;
        cout << "v2: " << v2 << endl;
        cout << endl;

        // swap two pointers to objects
        cout << "> swap &v1 and &v2" << endl;
        T *p1 {&v1};
        T *p2 {&v2};
        cout << "+ before" << endl;
        // pointers to char are automatically dereferenced. cast(...) will
        // make C++ print it as pointer
        cout << " p1: " << cast(p1) << ' ' << *p1 << endl;
        cout << " p2: " << cast(p2) << ' ' << *p2 << endl;
        swap(p1, p2);
        cout << "+ after" << endl;
        cout << " p1: " << cast(p1) << ' ' << *p1 << endl;
        cout << " p2: " << cast(p2) << ' ' << *p2 << endl;
        cout << endl;
    }

int main(int, char *[])
{
    run<char>();
    run<int>();
    run<Test>();
}
