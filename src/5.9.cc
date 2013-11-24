// Created by Samvel Khalatyan on Nov 24, 2013
// Copyright (c) 2013 Samvel Khalatyan. All rights reserved
//
// Use of this source code is governed by a MIT-style license that can be
// found in the LICENSE file.

#include "interface/5.9.h"

std::vector<int> ex_5_9::values(const int &size)
{
    std::vector<int> collection(size);

    int i = 0;
    for(auto &x:collection)
        x = ++i;

    return collection;
}
