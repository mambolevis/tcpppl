// Created by Samvel Khalatyan on Dec 25, 2013
// Copyright (c) 2013 Samvel Khalatyan. All rights reserved
//
// Use of this source code is governed by a MIT-style license that can be
// found in the LICENSE file.

#include "interface/estd_ios.h"

estd::Flags::Flags(std::ios &ios):
    ios{ios}, flags{ios.flags()}
    // backup flags for later restore
{}

estd::Flags::~Flags()
    // restore flags from backup
{
    ios.flags(flags);
}
