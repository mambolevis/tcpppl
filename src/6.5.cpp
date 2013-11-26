// Created by Samvel Khalatyan on Nov 26, 2013
// Copyright (c) 2013 Samvel Khalatyan. All rights reserved
//
// Use of this source code is governed by a MIT-style license that can be
// found in the LICENSE file.
//
// (*1.5)   Use a regex to find all decimal numbers in a file.

#include <exception>
#include <fstream>
#include <iostream>
#include <regex>
#include <string>

using std::cerr;
using std::cout;
using std::endl;

int main(int argc, char *argv[])
    // use user-supplied filename
try
{
    // make sure user has specified filename
    //
    if (1 >= argc)
        throw std::invalid_argument{"input TXT file is not supplied"};

    // make sure file was successfully opened
    //
    std::ifstream is{argv[1]};
    if (!is.good())
        throw std::runtime_error{"failed to open input TXT file"};

    std::regex re("(\\d+)");    // look up for any decimal number

    // loop over each line in input file and highlight numbers
    //
    for(std::string line; std::getline(is, line); )
    {
        // escape sequence for bold-red: \033[1;31m
        //                        reset: \033[0m
        cout << std::regex_replace(line, re, "\033[1;31m$1\033[0m") << endl;
    }
}
catch(const std::invalid_argument &e)
{
    cerr << e.what() << endl;
}
catch(const std::runtime_error &e)
{
    cerr << e.what() << endl;
}
