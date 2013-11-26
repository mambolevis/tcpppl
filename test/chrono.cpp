// Created by Samvel Khalatyan on Nov 26, 2013
// Copyright (c) 2013 Samvel Khalatyan. All rights reserved
//
// Use of this source code is governed by a MIT-style license that can be
// found in the LICENSE file.

#include <chrono>
#include <iostream>

#include "interface/estd_chrono.h"

using namespace std;
using namespace estd;

int main(int argc, char *argv[])
{
    {
        std::chrono::hours v{10};
        cout << v << endl;
    }

    {
        std::chrono::minutes v{10};
        cout << v << endl;
    }

    {
        std::chrono::seconds v{10};
        cout << v << endl;
    }

    {
        std::chrono::milliseconds v{10};
        cout << v << endl;
    }

    {
        std::chrono::microseconds v{10};
        cout << v << endl;
    }

    {
        std::chrono::nanoseconds v{10};
        cout << v << endl;
    }
}
