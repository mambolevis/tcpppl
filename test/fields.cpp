// Created by Samvel Khalatyan on Dec 2, 2013
// Copyright (c) 2013 Samvel Khalatyan. All rights reserved
//
// Use of this source code is governed by a MIT-style license that can be
// found in the LICENSE file.

#include <iostream>
#include <string>

#include "interface/7.6.h"

using std::cout;
using std::endl;

struct Port
    // demonstraction of flags
    //
    // pay attention at the structure size: it has minimal size of a struct
    // even though there are 5 members with two ints !
    //
{
    bool open:1;    // 1 bit for open flag
    bool good:1;    // 1 bit for good status
    bool com:1;     // 1 bit for com port

    unsigned int value:3;   // 3 bits for port value
    unsigned int delay:2;   // 2 bits for the delay (ms)
};

std::string exclam(const bool &b)
    // let's have OSX like prints of bool
{
    return b ? "yes" : "no";
}

std::ostream &operator <<(std::ostream &os, const Port &p)
    // print each port at once
{
    return os << "open:" << exclam(p.open) <<
        " good:" << exclam(p.good) <<
        " com:" << exclam(p.com) <<
        " value:" << p.value <<
        " delay:" << p.delay;
}

int main(int, char *[])
{
    using namespace ex_7_6;

    Port port {false, true, false, 5, 3};
    cout << type_name(Info<Port>{}) << " has size " << sizeof(port) << endl;
    cout << "Port info" << endl;
    cout << port << endl;
}
