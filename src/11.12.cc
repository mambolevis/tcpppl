// Created by Samvel Khalatyan on Dec 12, 2013
// Copyright (c) 2013 Samvel Khalatyan. All rights reserved
//
// Use of this source code is governed by a MIT-style license that can be
// found in the LICENSE file.

#include <iostream>

#include "interface/11.12.h"

using std::cout;
using std::endl;

using Calculator = ex_11_12::Calculator;

void Calculator::error(const std::string &message)
{
    std::cerr << "error in L:" << _line_number << " ";
    ex_11_11::Calculator::error(message);
}

bool Calculator::valid()
{
    return 5 > errors();
}

void Calculator::prompt()
{
    ++_line_number;

    cout << ">>> ";
}
