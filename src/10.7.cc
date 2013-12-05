// Created by Samvel Khalatyan on Dec 5, 2013
// Copyright (c) 2013 Samvel Khalatyan. All rights reserved
//
// Use of this source code is governed by a MIT-style license that can be
// found in the LICENSE file.

#include <iostream>
#include <string>

#include "interface/10.7.h"

using std::endl;
using std::string;

void ex_10_7::Remover::run(std::istream &is, std::ostream &os)
{
    string line;
    while(getline(is, line))
    {
        os << line << endl;
    }
}
