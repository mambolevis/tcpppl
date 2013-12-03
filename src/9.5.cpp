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
#include <sstream>

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

std::ostream &operator <<(std::ostream &os, const Season &s)
    // output operator
{
    switch(s)
    {
        case Season::spring: os << "spring"; break;
        case Season::summer: os << "summer"; break;
        case Season::autumn: os << "autumn"; break;
        case Season::winter: os << "winter"; break;

        // in case someone wants to use invalid season
        default: os << "undefined"; break;
    }

    return os;
}

namespace unit_test
{
    void increment_prefix();
    void increment_suffix();
    void decrement_prefix();
    void decrement_suffix();
    void ostream();
}

int main(int, char *[])
{
    unit_test::increment_prefix();
    unit_test::increment_suffix();
    unit_test::decrement_prefix();
    unit_test::decrement_suffix();
    unit_test::ostream();
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

    void ostream()
    {
        std::ostringstream os;

        Season s {Season::spring};

        os << s++;
        if (!("spring" == os.str())) cerr << "spring is expected" << endl;

        os.str(""); os << s++;
        if (!("summer" == os.str())) cerr << "summer is expected" << endl;

        os.str(""); os << s++;
        if (!("autumn" == os.str())) cerr << "autumn is expected" << endl;

        os.str(""); os << s++;
        if (!("winter" == os.str())) cerr << "winter is expected" << endl;
    }
}
