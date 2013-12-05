// Created by Samvel Khalatyan on Dec 5, 2013
// Copyright (c) 2013 Samvel Khalatyan. All rights reserved
//
// Use of this source code is governed by a MIT-style license that can be
// found in the LICENSE file.

#include <iostream>

#include "interface/estd_tty.h"

using std::cout;
using std::endl;

int main(int argc, char *[])
{
    using namespace std;
    using namespace estd;

    // -- red
    cout << "-- red" << endl <<
        "hello from " << red << "computer" << reset << "!" << endl;

    // -- blue
    cout << "-- blue" << endl <<
        "hello from " << blue << "computer" << reset << "!" << endl;

    // -- green
    cout << "-- green" << endl <<
        "hello from " << green << "computer" << reset << "!" << endl;

    // -- bold
    cout << "-- bold" << endl <<
        "hello from " << bold << "computer" << reset << "!" << endl;

    // -- bold_red
    cout << "-- bold_red" << endl <<
        "hello from " << bold_red << "computer" << reset << "!" << endl;

    // -- bold_blue
    cout << "-- bold_blue" << endl <<
        "hello from " << bold_blue << "computer" << reset << "!" << endl;

    // -- bold_green
    cout << "-- bold_green" << endl <<
        "hello from " << bold_green << "computer" << reset << "!" << endl;
}
