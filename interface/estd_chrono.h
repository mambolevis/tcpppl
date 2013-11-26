// Created by Samvel Khalatyan on Nov 26, 2013
// Copyright (c) 2013 Samvel Khalatyan. All rights reserved
//
// Use of this source code is governed by a MIT-style license that can be
// found in the LICENSE file.

#ifndef EXTENDED_STD_CHRONO
#define EXTENDED_STD_CHRONO

#include <iosfwd>
#include <chrono>

namespace estd
{
    std::ostream &operator<<(std::ostream &, const std::chrono::hours &);
    std::ostream &operator<<(std::ostream &, const std::chrono::minutes &);
    std::ostream &operator<<(std::ostream &, const std::chrono::seconds &);
    std::ostream &operator<<(std::ostream &, const std::chrono::milliseconds &);
    std::ostream &operator<<(std::ostream &, const std::chrono::microseconds &);
    std::ostream &operator<<(std::ostream &, const std::chrono::nanoseconds &);
}

#endif
