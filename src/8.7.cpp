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

using std::cout;
using std::endl;

class Test
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
    {
        T *tmp {v1};
        v1 = v2;
        v2 = tmp;
    }

template<typename T>
    void swap(T &v1, T &v2)
    {
        using std::move;

        T tmp {move(v1)};
        v1 = move(v2);
        v2 = move(tmp);
    }

template<typename T>
    void run()
    {
        using ex_7_6::Info;
        using ex_7_6::type_name;

        cout << "construct " << type_name(Info<T>{}) << endl;
        T v1 {1};
        cout << "v1: " << v1 << endl;

        cout << "construct " << type_name(Info<T>{}) << endl;
        T v2 {2};
        cout << "v2: " << v2 << endl;

        cout << "-- swap v1 and v2" << endl;
        swap(v1, v2);
        cout << "v1: " << v1 << endl;
        cout << "v2: " << v2 << endl;

        cout << "-- swap &v1 and &v2" << endl;
        T *p1 {&v1};
        T *p2 {&v2};
        cout << "p1: " << p1 << ' ' << *p1 << endl;
        cout << "p2: " << p2 << ' ' << *p2 << endl;
        swap(p1, p2);
        cout << "p1: " << p1 << ' ' << *p1 << endl;
        cout << "p2: " << p2 << ' ' << *p2 << endl;
    }

int main(int, char *[])
{
    run<int>();
    
    cout << endl;

    run<Test>();
}
