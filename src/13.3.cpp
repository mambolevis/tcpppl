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
#include <vector>

using namespace std;

vector<const char *> arguments(int argc, char *argv[])
    // put all arguments but the name of executable into a vector of strings
{
    vector<const char *> args;
    for(size_t i{1}; argc > i; ++i)
    {
        argv[i][0] = toupper(argv[i][0]);
        args.push_back(argv[i]);
    }

    return args;
}

int main(int argc, char *argv[])
{
    for(const char *arg:arguments(argc, argv))
        cout << "Hello, " << arg << "!" << endl;
}
