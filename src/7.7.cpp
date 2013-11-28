// Created by Samvel Khalatyan on Nov 27, 2013
// Copyright (c) 2013 Samvel Khalatyan. All rights reserved
//
// Use of this source code is governed by a MIT-style license that can be
// found in the LICENSE file.
//
// (*1.5)   Write a program that prints out the letters 'a'..'z' and the
//          digits '0'..'9' and their integer values. Do the same for other
//          printable characters. Do the same again but use hexadecimal
//          notation.

#include <algorithm>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <string>

using std::cout;
using std::endl;
using std::ostringstream;
using std::setbase;
using std::setw;
using std::string;

class Generator
    // generate values in range [from, to)
    //
    // similar to Python generator for use:
    //      for(const auto &x:Generator{'a', 'z' + 1})
    //          cout << x << endl;
    //
{
    public:
        class Iter
            // used in a range-based for loop
            //
            // minimal interface implementation
            //
        {
            public:
                Iter(const char &value):
                    _value{value}
                {}

                char operator *() const
                {
                    return _value;
                }

                bool operator!=(const Iter &iter) const
                {
                    return _value != iter._value;
                }

                Iter &operator ++()
                {
                    ++_value;

                    return *this;
                }

            private:
                char _value;
        };

        Generator(const char &from, const char &to, const char &max=0):
            _from{from},
            _to((max && (to - from) > max) ? (from + max) : to)
        {}

        Iter begin() const
        {
            return _from;
        }

        Iter end() const
        {
            return _to;
        }

    private:
        Iter _from;
        Iter _to;
};

// print numbers in base
//
enum class Base { dec=10, oct=8, hex=16 };

std::ostream &operator <<(std::ostream &os, const Base &base)
    // print base as string rather than number
    //
{
    switch(base)
    {
        case Base::dec:
            os << "dec";
            break;
        case Base::oct:
            os << "oct";
            break;
        default:
            os << "hex";
            break;
    }

    return os;
}

string bold(const string &s)
    // print any string in bold
    //
{
    return string("\033[1;1m") + s + "\033[0m";
}

template<typename T>
    string bold(const T &t)
        // make any printable object bold
        //
    {
        ostringstream os;
        os << t;

        return bold(os.str());
    }

void print(std::string title,
           const char &from,
           const char &to,
           const Base &base=Base::dec)
    // nice print of a sequence of characters with corresponding ASCII code
    // in specific base
    //
{
    cout << "-- " << title << " (base: " << bold(base) << ')' << endl;
    int i {0};
    for(const auto &x:Generator{from, to})
    {
        cout << std::setbase(static_cast<int>(base));
        cout << setw(3) << static_cast<int>(x) << ":" << bold(x) << ' ';
       
        // organize print in N columns
        //
        if (!(++i % 10))
           cout << endl; 
    }

    // extra endl for the last column if needed
    //
    if (i % 10)
        cout << endl;

    cout << endl;
}

int main(int, char *[])
{
    print("alphabet", 'a', 'z' + 1);
    print("numbers", '0', '9' + 1);
    print("printable characters", 32, 127);

    print("alphabet", 'a', 'z' + 1, Base::hex);
    print("numbers", '0', '9' + 1, Base::hex);
    print("printable characters", 32, 127, Base::hex);
}
