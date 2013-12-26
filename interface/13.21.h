// Created by Samvel Khalatyan on Dec 26, 2013
// Copyright (c) 2013 Samvel Khalatyan. All rights reserved
//
// Use of this source code is governed by a MIT-style license that can be
// found in the LICENSE file.

#ifndef EXERCISE_13_21
#define EXERCISE_13_21

#include <iosfwd>

#include "interface/9.4.h"

namespace ex_13_21
{
    using namespace ex_9_4;

    enum class Weekday : char
    {
        mon, tue, wed, thu, fri, sat, sun
    };

    Weekday &operator++(Weekday &wd);

    std::ostream &operator <<(std::ostream &, const Weekday &);

    bool leapyear(const Year &);
    Day days_in_month(const Year &, const Month &);

    // [[noreturn]] functions are not implemented
    //
    Date add_day(const Date &, int days);
    [[noreturn]] Date add_month(const Date &, const int &months);
    Date add_year(const Date &, const Year &years);

    [[noreturn]] Weekday weekday(const Date &);

    Date next(const Date &, Weekday=Weekday::mon);
}

#endif
