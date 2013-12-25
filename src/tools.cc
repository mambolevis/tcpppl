// Created by Samvel Khalatyan on Dec 24, 2013
// Copyright (c) 2013 Samvel Khalatyan. All rights reserved
//
// Use of this source code is governed by a MIT-style license that can be
// found in the LICENSE file.

#include "interface/tools.h"

tools::Args tools::arguments(int argc, char *argv[])
{
    tools::Args args;
    for(int i {1}; argc > i; ++i)
        args.push_back(argv[i]);

    return args;
}

tools::CArgs tools::carguments(int argc, char *argv[])
{
    tools::CArgs args;
    for(int i {1}; argc > i; ++i)
        args.push_back(argv[i]);

    return args;
}
