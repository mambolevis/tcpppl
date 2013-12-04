// Created by Samvel Khalatyan on Dec 4, 2013
// Copyright (c) 2013 Samvel Khalatyan. All rights reserved
//
// Use of this source code is governed by a MIT-style license that can be
// found in the LICENSE file.
//
// (*1) Rewrite the following for-statement as an equivalent while-statement:
//          for (i=0; i!=max_length; i++)
//              if (input_line[i] == '?')
//                  quest_count++;
//      Rewrite it to use a pointer as the controlled variable, that is, so
//      that the test is of the form *p=='?'.
//      Rewrite it to use a range-for.

#include <iostream>
#include <string>

using std::cout;
using std::endl;
using std::string;

int quest_count(const char *str)
    // use element access through index in the loop
{
    cout << "-- initial code" << endl;

    const size_t max_length {strlen(str)};
    int count {0};
    for(int i {0}; max_length > i; ++i)
        if ('?' == str[i])
            ++count;

    return count;
}

int count_with_pointer(const char *p)
    // use pointer to access elements
{
    cout << "-- test with pointer" << endl;

    int count {0};
    while(*p)
        if ('?' == *p++)
            ++count;

    return count;
}

int count_with_range_for(const char *str)
    // use range-based for: wrap c-string to stl string b/c of begin/end
{
    cout << "-- range for" << endl;

    int count {0};
    for(const auto &c: string(str))
        if ('?' == c)
            ++count;

    return count;
}

int main(int, char *[])
{
    // input string
    //
    const char *str {"How are you? "
                     "do you think this is a good idea? "
                     "good buy. really?"};
    cout << str << endl;

    // isolate each implementation in separate function and each in a loop.
    //
    using function = int(*)(const char *);
    function functions[] {
        quest_count,
        count_with_pointer,
        count_with_range_for
    };

    for(auto &f:functions)
    {
        int counts = f(str);
        cout << "found " << counts << " '?' symbol(s)" << endl;
    }
}
