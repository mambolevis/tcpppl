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

    ex_9_4::unit_test::test_month_is();
    ex_9_4::unit_test::test_month_os();

    /*
    try
    {
        cout << "input month: ";
        for(Month m; cin >> m; cout << "input month: ")
            cout << "your input is: " << m << endl;
    }
    catch(const std::runtime_error &e)
    {
        cerr << e.what() << endl;
    }
    */
}
