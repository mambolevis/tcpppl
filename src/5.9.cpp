// Created by Samvel Khalatyan on Nov 24, 2013
// Copyright (c) 2013 Samvel Khalatyan. All rights reserved
//
// Use of this source code is governed by a MIT-style license that can be
// found in the LICENSE file.
//
// (*1) Open a file for writing (as an ofstream) and write a few hundred
//      integers to it.

#include <iostream>
#include <fstream>
#include <string>

#include "interface/5.9.h"

using std::cerr;
using std::cout;
using std::endl;
using std::ofstream;
using std::string;

int main(int argc, char *argv[])
{
    using ex_5_9::filename;

    ofstream os(filename);
    if (os.good())
    {
        for(const auto &x:ex_5_9::values())
        {
            os << x << endl;;
        }
        cout << "values are written to " << filename << endl;
    }
    else
    {
        cerr << "failed to open " << filename << " for write" << endl;
    }
}
