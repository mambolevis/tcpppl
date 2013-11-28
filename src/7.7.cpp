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
#include <string>

using std::cout;
using std::endl;
using std::setbase;
using std::string;

class Generator
{
    public:
        class Iter
        {
            public:
                Iter(const char &value):
                    _value(value)
                {}

                char operator *() const
                {
                    return _value;
                }

                bool operator!=(const Iter &iter) const
                {
                    return _value != iter._value;
                }

                bool operator==(const Iter &iter) const
                {
                    return _value == iter._value;
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
            _from{from}, _to((max && (to - from) > max) ? (from + max) : to)
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

void print(std::string title,
           const char &from,
           const char &to,
           const int &base=10)
{
    cout << "-- " << title << " (base:" << base << ')' << endl;
    for(const auto &x:Generator{from, to})
    {
        cout << std::setbase(base);
        cout << static_cast<int>(x) << ":" << x << ' ';
    }
    cout << endl;
}

int main(int, char *[])
{
    print("alphabet", 'a', 'z' + 1);
    print("numbers", '0', '9' + 1);
    print("printable characters", 32, 127);

    print("alphabet", 'a', 'z' + 1, 16);
    print("numbers", '0', '9' + 1, 16);
    print("printable characters", 32, 127, 16);
}
