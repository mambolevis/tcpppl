// Created by Samvel Khalatyan on Nov 24, 2013
// Copyright (c) 2013 Samvel Khalatyan. All rights reserved
//
// Use of this source code is governed by a MIT-style license that can be
// found in the LICENSE file.

#include <iomanip>
#include <iostream>

#include "interface/5.6.h"

// helpers
//
std::istream &ex_5_6::operator >>(std::istream &is, Person &p)
{
    is >> p.name >> p.age;
    p.name[0] = toupper(p.name[0]); // capitalize name

    return is;
}

std::ostream &ex_5_6::operator <<(std::ostream &os, const Person &p)
{
    using std::setw;

    return os << setw(2) << p.age << ' ' << p.name;
}
