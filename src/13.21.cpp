// Created by Samvel Khalatyan on Dec 26, 2013
// Copyright (c) 2013 Samvel Khalatyan. All rights reserved
//
// Use of this source code is governed by a MIT-style license that can be
// found in the LICENSE file.
//
// (*2) Write functions to add one day, one month, and one year to a Date as
//      defined in §X.9[4].
//      Write a function that gives the day of the week for a given Date.
//      Write a function that gives the Date of the first Monday following
//      a given Date.

#include <sstream>
#include <stdexcept>

#include "gtest/gtest.h"

#include "interface/13.21.h"

using namespace std;

using ex_13_21::Weekday;
using ex_13_21::Month;
using ex_13_21::Date;

TEST(WeekdayTest, Increment)
{
    Weekday wd {Weekday::mon};

    EXPECT_EQ(wd, Weekday::mon);
    EXPECT_EQ(++wd, Weekday::tue);
    EXPECT_EQ(++wd, Weekday::wed);
    EXPECT_EQ(++wd, Weekday::thu);
    EXPECT_EQ(++wd, Weekday::fri);
    EXPECT_EQ(++wd, Weekday::sat);
    EXPECT_EQ(++wd, Weekday::sun);
    EXPECT_EQ(++wd, Weekday::mon);
}

TEST(WeekdayTest, Ostream)
{
    Weekday wd {Weekday::sun};

    ostringstream os;

    os.clear(); os.str(""); os << ++wd; EXPECT_STREQ(os.str().c_str(), "Monday");
    os.clear(); os.str(""); os << ++wd; EXPECT_STREQ(os.str().c_str(), "Tuesday");
    os.clear(); os.str(""); os << ++wd; EXPECT_STREQ(os.str().c_str(), "Wednesday");
    os.clear(); os.str(""); os << ++wd; EXPECT_STREQ(os.str().c_str(), "Thursday");
    os.clear(); os.str(""); os << ++wd; EXPECT_STREQ(os.str().c_str(), "Friday");
    os.clear(); os.str(""); os << ++wd; EXPECT_STREQ(os.str().c_str(), "Saturday");
    os.clear(); os.str(""); os << ++wd; EXPECT_STREQ(os.str().c_str(), "Sunday");
}

TEST(DateTest, Leapyear)
{
    EXPECT_TRUE(ex_13_21::leapyear(2000));
    EXPECT_FALSE(ex_13_21::leapyear(2015));
    EXPECT_FALSE(ex_13_21::leapyear(2017));
    EXPECT_FALSE(ex_13_21::leapyear(2018));
    EXPECT_FALSE(ex_13_21::leapyear(2019));
    EXPECT_TRUE(ex_13_21::leapyear(2020));
}

TEST(DateTest, Days_in_month)
{
    using ex_13_21::days_in_month;

    EXPECT_EQ(31, days_in_month(2000, Month::jan));
    EXPECT_EQ(29, days_in_month(2000, Month::feb));
    EXPECT_EQ(28, days_in_month(2001, Month::feb));
    EXPECT_EQ(31, days_in_month(2000, Month::mar));
    EXPECT_EQ(30, days_in_month(2000, Month::apr));
    EXPECT_EQ(31, days_in_month(2000, Month::may));
    EXPECT_EQ(30, days_in_month(2000, Month::jun));
    EXPECT_EQ(31, days_in_month(2000, Month::jul));
    EXPECT_EQ(31, days_in_month(2000, Month::aug));
    EXPECT_EQ(30, days_in_month(2000, Month::sep));
    EXPECT_EQ(31, days_in_month(2000, Month::oct));
    EXPECT_EQ(30, days_in_month(2000, Month::nov));
    EXPECT_EQ(31, days_in_month(2000, Month::dec));
}

TEST(DateTest, Add_day)
{
    using ex_13_21::add_day;

    // leap year
    Date d { 2000, Month::jan, 1};
    Date res = d;

    res.day = 2; EXPECT_EQ(res, add_day(d, 1));
    res.day = 30; EXPECT_EQ(res, add_day(d, 29));
    res.day = 31; EXPECT_EQ(res, add_day(d, 30));
    res.day = 1; res.month = Month::feb; EXPECT_EQ(res, add_day(d, 31));
    res.day = 28; EXPECT_EQ(res, add_day(d, 58));

    // there is Feb 29 in the leap year
    res.day = 29; EXPECT_EQ(res, add_day(d, 59));
    res.day = 1; res.month = Month::mar; EXPECT_EQ(res, add_day(d, 60));

    // leap year has 366 days
    res = Date { 2001, Month::jan, 1}; EXPECT_EQ(res, add_day(d, 366));


    // non-leap year
    d = Date { 2001, Month::jan, 1};
    res = d;

    res.day = 2; EXPECT_EQ(res, add_day(d, 1));
    res.day = 30; EXPECT_EQ(res, add_day(d, 29));
    res.day = 31; EXPECT_EQ(res, add_day(d, 30));
    res.day = 1; res.month = Month::feb; EXPECT_EQ(res, add_day(d, 31));
    res.day = 28; EXPECT_EQ(res, add_day(d, 58));

    // there is no Feb 29 in the non-leap year
    res.day = 1; res.month = Month::mar; EXPECT_EQ(res, add_day(d, 59));

    // non-leap year has 365 days
    res = Date { 2002, Month::jan, 1}; EXPECT_EQ(res, add_day(d, 365));
}

TEST(DateTest, Add_month)
{
    Date d { 2000, Month::jan, 1 };

    EXPECT_THROW(ex_13_21::add_month(d, 1), runtime_error);
}

TEST(DateTest, Add_year)
{
    using ex_13_21::add_year;

    // test ordinary day
    Date d { 2000, Month::jan, 1 };
    Date res = d;

    res.year = 2001; EXPECT_EQ(res, add_year(d, 1));
    res.year = 2002; EXPECT_EQ(res, add_year(d, 2));
    res.year = 2003; EXPECT_EQ(res, add_year(d, 3));
    res.year = 2004; EXPECT_EQ(res, add_year(d, 4));
    res.year = 2005; EXPECT_EQ(res, add_year(d, 5));

    // last day of leapyear independent month
    d.day = 31;
    res = d;

    res.year = 2001; EXPECT_EQ(res, add_year(d, 1));
    res.year = 2002; EXPECT_EQ(res, add_year(d, 2));
    res.year = 2003; EXPECT_EQ(res, add_year(d, 3));
    res.year = 2004; EXPECT_EQ(res, add_year(d, 4));
    res.year = 2005; EXPECT_EQ(res, add_year(d, 5));

    // last day of feb that depends on leap year: Feb 29
    d.month = Month::feb;
    d.day = 29;
    res = d;

    res.year = 2001; res.month = Month::mar; res.day = 1; EXPECT_EQ(res, add_year(d, 1));
    res.year = 2002; EXPECT_EQ(res, add_year(d, 2));
    res.year = 2003; EXPECT_EQ(res, add_year(d, 3));
    res = d; res.year = 2004; EXPECT_EQ(res, add_year(d, 4));
    res.year = 2005; res.month = Month::mar; res.day = 1; EXPECT_EQ(res, add_year(d, 5));

    // feb 28 should not depend on leapyear status
    d.day = 28;
    res = d;

    res.year = 2001; EXPECT_EQ(res, add_year(d, 1));
    res.year = 2002; EXPECT_EQ(res, add_year(d, 2));
    res.year = 2003; EXPECT_EQ(res, add_year(d, 3));
    res.year = 2004; EXPECT_EQ(res, add_year(d, 4));
    res.year = 2005; EXPECT_EQ(res, add_year(d, 5));
}

TEST(DateTest, Weekday)
{
    Date d { 2000, Month::jan, 1 };

    EXPECT_THROW(ex_13_21::weekday(d), runtime_error);
}

TEST(DateTest, NextWeekday)
{
    Date d { 2000, Month::jan, 1 };

    EXPECT_THROW(ex_13_21::next(d, Weekday::mon), runtime_error);
    EXPECT_THROW(ex_13_21::next(d, Weekday::tue), runtime_error);
    EXPECT_THROW(ex_13_21::next(d, Weekday::wed), runtime_error);
    EXPECT_THROW(ex_13_21::next(d, Weekday::thu), runtime_error);
    EXPECT_THROW(ex_13_21::next(d, Weekday::fri), runtime_error);
    EXPECT_THROW(ex_13_21::next(d, Weekday::sat), runtime_error);
    EXPECT_THROW(ex_13_21::next(d, Weekday::sun), runtime_error);
}

int main(int argc, char *argv[])
{
    ::testing::InitGoogleTest(&argc, argv);

    return RUN_ALL_TESTS();
}
