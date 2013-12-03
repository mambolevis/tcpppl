// Created by Samvel Khalatyan on Dec 3, 2013
// Copyright (c) 2013 Samvel Khalatyan. All rights reserved
//
// Use of this source code is governed by a MIT-style license that can be
// found in the LICENSE file.
//
// (*2) Implement an enum called Season with enumerators spring, summer,
//      autumn, and winter. Define operators ++ and −− for Season.
//      Define input (>>) and output (<<) operations for Season, providing
//      string values. Provide a way to control the mapping between Season
//      values and their string representations. For example, I might want
//      the strings to reflect the Danish names for the seasons. For further
//      study, see Chapter 39.

#include <iostream>

enum class Season : unsigned char {spring, summer, autumn, winter};

Season &operator ++(Season &s)
    // prefix increment
{
    if (Season::winter == s)
        s = Season::spring;
    else
        s = static_cast<Season>(static_cast<int>(s) + 1);

    return s;
}

Season operator ++(Season &s, int)
    // suffix increment
{
    Season tmp {s};
    ++s;

    return tmp;
}

Season &operator --(Season &s)
    // prefix decrement
{
    if (Season::spring == s)
        s = Season::winter;
    else
        s = static_cast<Season>(static_cast<int>(s) - 1);

    return s;
}

Season operator --(Season &s, int)
    // suffix decrement
{
    Season tmp {s};
    --s;

    return tmp;
}

namespace unit_test
{
    void increment_prefix();
    void increment_suffix();
    void decrement_prefix();
    void decrement_suffix();
}

int main(int, char *[])
{
    unit_test::increment_prefix();
    unit_test::increment_suffix();
    unit_test::decrement_prefix();
    unit_test::decrement_suffix();
}

namespace unit_test
{
    using std::cerr;
    using std::endl;

    void increment_prefix()
    {
        Season s {Season::spring};

        if (!(Season::spring == s)) cerr << "spring is expected" << endl;;
        if (!(Season::summer == ++s)) cerr << "summer is expected" << endl;;

        if (!(Season::summer == s)) cerr << "summer is expected" << endl;;
        if (!(Season::autumn == ++s)) cerr << "autumn is expected" << endl;;

        if (!(Season::autumn == s)) cerr << "autumn is expected" << endl;;
        if (!(Season::winter == ++s)) cerr << "winter is expected" << endl;;

        if (!(Season::winter == s)) cerr << "winter is expected" << endl;;
        if (!(Season::spring == ++s)) cerr << "spring is expected" << endl;;

        if (!(Season::spring == s)) cerr << "spring is expected" << endl;;
    }

    void increment_suffix()
    {
        Season s {Season::spring};

        if (!(Season::spring == s)) cerr << "spring is expected" << endl;;

        if (!(Season::spring == s++)) cerr << "spring is expected" << endl;;
        if (!(Season::summer == s)) cerr << "summer is expected" << endl;;

        if (!(Season::summer == s++)) cerr << "summer is expected" << endl;;
        if (!(Season::autumn == s)) cerr << "autumn is expected" << endl;;

        if (!(Season::autumn == s++)) cerr << "autumn is expected" << endl;;
        if (!(Season::winter == s)) cerr << "winter is expected" << endl;;

        if (!(Season::winter == s++)) cerr << "winter is expected" << endl;;
        if (!(Season::spring == s)) cerr << "spring is expected" << endl;;
    }

    void decrement_prefix()
    {
        Season s {Season::spring};

        if (!(Season::spring == s)) cerr << "spring is expected" << endl;;
        if (!(Season::winter == --s)) cerr << "winter is expected" << endl;;

        if (!(Season::winter == s)) cerr << "winter is expected" << endl;;
        if (!(Season::autumn == --s)) cerr << "autumn is expected" << endl;;

        if (!(Season::autumn == s)) cerr << "autumn is expected" << endl;;
        if (!(Season::summer == --s)) cerr << "summer is expected" << endl;;

        if (!(Season::summer == s)) cerr << "summer is expected" << endl;;
        if (!(Season::spring == --s)) cerr << "spring is expected" << endl;;

        if (!(Season::spring == s)) cerr << "spring is expected" << endl;;
    }

    void decrement_suffix()
    {
        Season s {Season::spring};

        if (!(Season::spring == s)) cerr << "spring is expected" << endl;;

        if (!(Season::spring == s--)) cerr << "spring is expected" << endl;;
        if (!(Season::winter == s)) cerr << "winter is expected" << endl;;

        if (!(Season::winter == s--)) cerr << "winter is expected" << endl;;
        if (!(Season::autumn == s)) cerr << "autumn is expected" << endl;;

        if (!(Season::autumn == s--)) cerr << "autumn is expected" << endl;;
        if (!(Season::summer == s)) cerr << "summer is expected" << endl;;

        if (!(Season::summer == s--)) cerr << "summer is expected" << endl;;
        if (!(Season::spring == s)) cerr << "spring is expected" << endl;;
    }
}
