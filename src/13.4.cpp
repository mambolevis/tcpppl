// Created by Samvel Khalatyan on Dec 24, 2013
// Copyright (c) 2013 Samvel Khalatyan. All rights reserved
//
// Use of this source code is governed by a MIT-style license that can be
// found in the LICENSE file.
//
// (*1.5)   Write a program that reads an arbitrary number (possibly limited
//          to some maximum number) of files whose names are given as
//          command-line arguments and writes them one after another on cout.
//          Because this program concatenates its arguments to produce its
//          output, you might call it cat.

#include <fstream>
#include <iostream>

#include "interface/tools.h"

using namespace std;
using tools::arguments;

int main(int argc, char *argv[])
{
    for(const std::string &filename:arguments(argc, argv))
    {
        ifstream is {filename};
        for(char c; is.get(c); cout << c);
    }
}
