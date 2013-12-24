// Created by Samvel Khalatyan on Dec 24, 2013
// Copyright (c) 2013 Samvel Khalatyan. All rights reserved
//
// Use of this source code is governed by a MIT-style license that can be
// found in the LICENSE file.
//
// (*1.5)   Write a program like ‘‘Hello, world!’’ that takes a name as
//          a command-line argument and writes ‘‘Hello, name !’’.
//          Modify this program to take any number of names as arguments
//          and to say hello to each.

#include <cctype>
#include <iostream>

#include "interface/tools.h"

using namespace std;

int main(int argc, char *argv[])
{
    for(string &arg:tools::arguments(argc, argv))
    {
        arg[0] = toupper(arg[0]);
        cout << "Hello, " << arg << "!" << endl;
    }
}
