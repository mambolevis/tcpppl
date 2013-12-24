// Created by Samvel Khalatyan on Dec 24, 2013
// Copyright (c) 2013 Samvel Khalatyan. All rights reserved
//
// Use of this source code is governed by a MIT-style license that can be
// found in the LICENSE file.

#include "interface/tools.h"

std::vector<std::string> tools::arguments(int argc, char *argv[])
{
    std::vector<std::string> args;
    for(int i {1}; argc > i; ++i)
        args.push_back(argv[i]);

    return args;
}
