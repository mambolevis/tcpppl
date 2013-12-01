// Created by Samvel Khalatyan on Dec 01, 2013
// Copyright (c) 2013 Samvel Khalatyan. All rights reserved
//
// Use of this source code is governed by a MIT-style license that can be
// found in the LICENSE file.
//
// (*2) Write a function that counts the number of occurrences of a pair of
//      letters in a string and another that does the same in a
//      zero-terminated array of char (a C-style string). For example, the
//      pair "ab" appears twice in "xabaacbaxabb".

#include <iostream>
#include <string>

using std::cout;
using std::endl;
using std::string;

int count(const string &str, const char *substr)
    // find number of times substr is present in string
{
    int result {0};
    for(size_t index {0};
            string::npos != (index = str.find(substr, index));
            ++index, ++result)
    {}

    return result;
}

int count(const char *str, const char *substr)
    // find number of times substr is present in c-string
{
    int result {0};
    for(const char *index {str};
            (index = strstr(index, substr));
            ++index, ++result)
    {}

    return result;
}

int main(int, char *[])
{
    string str {"xabaacbaxabb"};
    const char *substr {"ab"};

    cout << "    string: " << str << endl;
    cout << "sub-string: " << substr << endl;
    cout << endl;

    cout << "-- search in string" << endl;
    cout << "count: " << count(str, substr) << endl;
    cout << endl;

    cout << "-- search in c-string" << endl;
    cout << "count: " << count(str.c_str(), substr) << endl;
}
