// Created by Samvel Khalatyan on Nov 24, 2013
// Copyright (c) 2013 Samvel Khalatyan. All rights reserved
//
// Use of this source code is governed by a MIT-style license that can be
// found in the LICENSE file.

#ifndef EXERCISE_5_6
#define EXERCISE_5_6

#include <iosfwd>
#include <string>

namespace ex_5_6
{
    struct Person
    {
        Person() = default; // use default constructor;

        Person(const std::string &n, const int &a):
            name{n}, age{a} {}

        operator bool() const noexcept { return 0 < age && 100 > age && name.size(); }

        std::string name;
        int age;
    };

    std::istream &operator >>(std::istream &, Person &);
    std::ostream &operator <<(std::ostream &, const Person &);
}

#endif
