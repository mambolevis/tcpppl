// Created by Samvel Khalatyan on Dec 25, 2013
// Copyright (c) 2013 Samvel Khalatyan. All rights reserved
//
// Use of this source code is governed by a MIT-style license that can be
// found in the LICENSE file.

#ifndef EXTENDED_IOS
#define EXTENDED_IOS

#include <ios>

namespace estd
{
    struct Flags
        // RAII flags backup with automatic restore for any ios, e.g.:
        //
        //  {
        //      Flags flags {std::cout};
        //
        //      std::cout << std::left << "hello" << std::endl;
        //
        //      // now on std::cout will justify left all prints, but flags
        //      // will restore any previous behaviour
        //  }
    {
        Flags(std::ios &ios);
        ~Flags();

        std::ios &ios;
        std::ios::fmtflags flags; // backed up flags
    };
}

#endif
