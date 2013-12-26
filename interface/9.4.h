// Created by Samvel Khalatyan on Dec 2, 2013
// Copyright (c) 2013 Samvel Khalatyan. All rights reserved
//
// Use of this source code is governed by a MIT-style license that can be
// found in the LICENSE file.

#ifndef EXERCISE_9_4
#define EXERCISE_9_4

#include <iosfwd>

namespace ex_9_4
{
    using Day = int;
    using Year = int;

    enum class Month : char
    {
        jan, feb,
        mar, apr, may,
        jun, jul, aug,
        sep, oct, nov,
        dec
    };

    // supported formats
    //
    //  ------------------------------------
    //  type            example     result
    //  ------------------------------------
    //  int             1           january
    //                  4           april
    //
    //  string          jan         january 
    //                  dec         december
    //                  april       april
    //                  march       march
    //  ------------------------------------
    //
    //  operator will raise a runtime_error if invalid month is used
    //
    std::istream &operator >>(std::istream &is, Month &);
    std::ostream &operator <<(std::ostream &os, const Month &);

    namespace unit_test
    {
        void test_month_is();   // istream month
        void test_month_os();   // ostream month
    }

    struct Date
        // Do not define constructor to keep Date POD, aka Plain Old Data
    {
        Year year;
        Month month;
        Day day;
    };

    // supported formats
    //
    //  --------------------------------------------
    //  format          example         result
    //  --------------------------------------------
    //  d/m/y           3/4/2013        Apr 3, 2013
    //  d.m.y           5.Jan.2013      Jan 5, 2013
    //  --------------------------------------------
    //
    //  Month can be typed in any supported form: see above
    //
    std::istream &operator >>(std::istream &is, Date &);
    std::ostream &operator <<(std::ostream &os, const Date &);

    bool operator ==(const Date &, const Date &);
    inline bool operator !=(const Date &d1, const Date &d2)
    {
        return not (d1 == d2);
    }

    namespace unit_test
    {
        void test_date_is();
        void test_date_os();
    }
}

#endif
