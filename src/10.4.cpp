// Created by Samvel Khalatyan on Dec 4, 2013
// Copyright (c) 2013 Samvel Khalatyan. All rights reserved
//
// Use of this source code is governed by a MIT-style license that can be
// found in the LICENSE file.
//
// (*2) Write a function atoi(const char*) that takes a C-style string
//      containing digits and returns the corresponding int. For example,
//      atoi("123") is 123.
//      Modify atoi() to handle C++ octal and hexadecimal notation in
//      addition to plain decimal numbers.
//      Modify atoi() to handle the C++ character constant notation.

#include <iomanip>
#include <iostream>
#include <vector>
#include <utility>

int atoi(const char *str)
{
    int base {10};
    char max_char {'9'};
    int sign {1};
    if ('-' == *str)
    {
        sign = -1;
        ++str;
    }
    else if ('+' == *str)
        ++str;

    if ('0' == *str && 'x' == *(str + 1))
    {
        str += 2;   // skip prefix '0x'
        max_char = 'f';
        base = 16;
    }
    else if ('0' == *str)
    {
        str += 1;   // skip prefix '0'
        max_char = '7';
        base = 8;
    }

    int result {0};
    while(*str)
    {
        if ('0' <= *str && max_char >= *str)
        {
            result *= base;
            if ('a' <= *str)
                result += 10 + (*str - 'a');
            else
                result += *str - '0';
        }
        else
            break;

        ++str;
    }

    return sign * result;
}

int atoi(const char &c)
{
    char str[2] {c, '\0'};
    return atoi(str);
}

int main(int, char *[])
{
    using namespace std;
    
    using test = pair<int, initializer_list<string>>;
    vector<test> tests {
        {10, {"123", "432", "692", "+123", "-123"}},
        {8, {"0123", "0432", "0692", "0010101", "04751", "-0123"}},
        {16, {"0x123", "0x432", "0x692", "0xa3d", "0xff", "-0xff"}}
    };

    for(const auto &t:tests)
    {
        cout << "-- base " << t.first << endl;
        for(const auto &s:t.second)
        {
            ios_base::fmtflags flags = cout.flags();
            const int value = atoi(s.c_str());
            cout << setw(10) << s << " | " << setw(10) << left << value <<
                " | ";
            cout << showbase << setbase(t.first) << abs(value) << endl;
            cout.flags(flags);
        }
    }

    cout << "-- base 10" << endl;
    for(const auto &c:{'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'})
    {
        cout << c << ": " << atoi(c) << endl;
    }
}
