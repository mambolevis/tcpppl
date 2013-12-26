// Created by Samvel Khalatyan on Dec 26, 2013
// Copyright (c) 2013 Samvel Khalatyan. All rights reserved
//
// Use of this source code is governed by a MIT-style license that can be
// found in the LICENSE file.

#include <ostream>
#include <stdexcept>

#include "interface/13.21.h"

using namespace std;

using ex_13_21::Day;
using ex_13_21::Year;
using ex_13_21::Date;
using ex_13_21::Weekday;

Weekday &ex_13_21::operator++(Weekday &wd)
{
    return wd = static_cast<Weekday>((static_cast<int>(wd) + 1) % 7 +
                                     static_cast<int>(Weekday::mon));
}

ostream &ex_13_21::operator <<(ostream &os, const Weekday &wd)
{
    switch(wd)
    {
        case Weekday::mon: os << "Monday"; break;
        case Weekday::tue: os << "Tuesday"; break;
        case Weekday::wed: os << "Wednesday"; break;
        case Weekday::thu: os << "Thursday"; break;
        case Weekday::fri: os << "Friday"; break;
        case Weekday::sat: os << "Saturday"; break;
        case Weekday::sun: os << "Sunday"; break;
    }

    return os;
}

bool ex_13_21::leapyear(const Year &y)
{
    return not (y % 4);
}

Day ex_13_21::days_in_month(const Year &y, const Month &m)
{
    switch(m)
    {
        case Month::feb: return leapyear(y) ? 29 : 28;
        //
    	case Month::apr: return 30;
        //
    	case Month::jun: return 30;
        //
    	case Month::sep: return 30;
    	case Month::nov: return 30;
        //
        default: return 31;
    }
}

Date ex_13_21::add_day(const Date &d, int days)
{
    if (days < 1)
        throw runtime_error("number of days should be positive");

    Date res { d.year, d.month, 1 };
    days += d.day - 1;

    for(Day delta {days_in_month(res.year, res.month)};
            delta <= days;
            delta = days_in_month(res.year, res.month))
    {
        if (res.month == Month::dec)
        {
            res.month = Month::jan;
            res.year += 1;
        }
        else
            res.month = static_cast<Month>(static_cast<int>(res.month) + 1);

        days -= delta;
    }
    res.day += days;

    return res;
}

Date ex_13_21::add_month(const Date &d, const int &months)
{
    // read: http://en.wikipedia.org/wiki/Calculating_the_day_of_the_week
    throw runtime_error("not implemented");
}

Date ex_13_21::add_year(const Date &d, const Year &years)
{
    Date res { d.year + years, d.month, d.day};

    if (Month::feb == res.month and 29 == res.day and not leapyear(res.year))
    {
        res.month = Month::mar;
        res.day = 1;
    }

    return res;
}

[[noreturn]] Weekday ex_13_21::weekday(const Date &)
{
    // read: http://en.wikipedia.org/wiki/Calculating_the_day_of_the_week
    throw runtime_error("not implemented");
}

Date ex_13_21::next(const Date &d, Weekday wd)
{
    // Find out how many days to be added to the date
    Day days {0};
    for(Weekday week_day {weekday(d)}; wd != week_day; ++wd, ++days);

    return days ? add_day(d, days) : d;
}
