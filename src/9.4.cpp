// Created by Samvel Khalatyan on Dec 2, 2013
// Copyright (c) 2013 Samvel Khalatyan. All rights reserved
//
// Use of this source code is governed by a MIT-style license that can be
// found in the LICENSE file.
//
// (*1.5)   Define a struct Date to keep track of dates. Provide functions
//          that read Dates from input, write Dates to output, and initialize
//          a Date with a date.

#include <iostream>
#include <stdexcept>
#include <type_traits>

#include "interface/9.4.h"

using std::cerr;
using std::cin;
using std::cout;
using std::endl;

int main(int, char *[])
{
    using namespace ex_9_4;

    cout << "Month is pod: " <<  std::is_pod<Month>::value << endl;
    cout << "Date is pod: " <<  std::is_pod<Date>::value << endl;

    unit_test::test_month_is();
    unit_test::test_month_os();
    unit_test::test_date_is();
    unit_test::test_date_os();

    // Date is pod and can be initialized in a simple way:
    Date d {2000, Month::aug, 18};
    cout << d << endl;
}
