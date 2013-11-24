// Created by Samvel Khalatyan on Nov 24, 2013
// Copyright (c) 2013 Samvel Khalatyan. All rights reserved
//
// Use of this source code is governed by a MIT-style license that can be
// found in the LICENSE file.

#ifndef EXERCISE_5_7
#define EXERCISE_5_7

#include <iostream>

#include "interface/estd_vector.h"

using std::cout;
using std::endl;

using namespace estd;

namespace ex_5_7
{
    template<typename T>
        void run(std::vector<T> &collection)
        {
            cout << collection << endl;

            cout << "-- sorted" << endl;
            sort(collection);
            cout << collection << endl;
        }
}

#endif
