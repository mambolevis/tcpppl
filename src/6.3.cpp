// Created by Samvel Khalatyan on Nov 26, 2013
// Copyright (c) 2013 Samvel Khalatyan. All rights reserved
//
// Use of this source code is governed by a MIT-style license that can be
// found in the LICENSE file.
//
// (*2) Time a loop. Write out the time in milliseconds. Do this for the
//      default setting of your compiler and for a setting using an optimizer
//      (e.g., −O2 or "release"). Be careful not to have the optimizer
//      eliminate your whole loop as dead code because you did not use a result.

#include <iostream>

#include "interface/Timer.h"

using std::cout;
using std::endl;

int main(int argc, char *argv[])
{
    int j = 0;

    tools::Timer t; // start timer
    for(int i {0}; 100000000 > i; ++i)
        j += i * i;
    cout << t << endl; // print duration but let timer run

    cout << j << endl;
    cout << t << endl;
}
