// Created by Samvel Khalatyan on Dec 10, 2013
// Copyright (c) 2013 Samvel Khalatyan. All rights reserved
//
// Use of this source code is governed by a MIT-style license that can be
// found in the LICENSE file.
//
// Consinder a range-for:
//
//  for(const auto &x:g) {...}
//
// The requirements for 'g' to be used in the range-for are the following:
//
//      - the object has g.begin() and g.end() methods that return iterators
//  OR
//      - begin(g) and end(g) are defined and these return iterators.
//
// In addition Iterators should be:
//
//      - dereferencable    operator *()
//      - advancable        operator ++()
//      - comparable        bool operator !=(...)
//
// A demonstration is given below

#include <iostream>

using namespace std;

class Iterator
    // simple common iterator that is dereferencable and advancable
{
    public:
        Iterator(const int &value):
            _value{value}
        {}

        int operator *() const noexcept { return _value; }
        Iterator &operator ++() { ++_value; return *this; }

    private:
        int _value;
};

bool operator !=(const Iterator  &i1, const Iterator &i2)
    // make iterators comparable
{
    return *i1 != *i2;
}

class Generator
    // a generator with EXTERNAL begin/end functions
{
    public:
        Generator(const int &from,
                  const int &till):
            _from{Iterator{from}},
            _till{Iterator{till}}
        {}

        // methods below are NOT used by default to get the begin and end
        // iterators
        Iterator begin_iterator() const noexcept { return std::move(_from); }
        Iterator end_iterator() const noexcept { return std::move(_till); }

    private:
        Iterator _from;
        Iterator _till;
};

Iterator begin(const Generator &g)
{
    cout << "::begin" << endl;

    return g.begin_iterator();
}

Iterator end(const Generator &g)
{
    cout << "::end" << endl;

    return g.end_iterator();
}

class AdvancedGenerator : public Generator
    // a generator with BUILT-IN begin/end methods
{
    public:
        AdvancedGenerator(const int &from,
                          const int &till):
            Generator(from, till)
        {}

        // these WILL be use by the range-for to get the beginning and end
        // iterators
        Iterator begin() const noexcept
        { 
            cout << "AdvancedGenerator::begin" << endl;

            return begin_iterator();
        }

        Iterator end() const noexcept
        { 
            cout << "AdvancedGenerator::end" << endl;

            return end_iterator();
        }
};

int main(int, char *[])
{
    cout << "-- Generator(1, 5)" << endl;
    for(const auto &x:Generator(1, 5))
    {
        cout << x << " ";
    }
    cout << endl << endl;

    cout << "-- AdvancedGenerator(1, 5)" << endl;
    for(const auto &x:AdvancedGenerator(1, 5))
    {
        cout << x << " ";
    }
    cout << endl;
}
