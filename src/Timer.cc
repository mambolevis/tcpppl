// Created by Samvel Khalatyan on Nov 26, 2013
// Copyright (c) 2013 Samvel Khalatyan. All rights reserved
//
// Use of this source code is governed by a MIT-style license that can be
// found in the LICENSE file.

#include <ostream>

#include "interface/Timer.h"

using std::chrono::duration_cast;
using std::chrono::milliseconds;
using std::chrono::system_clock;

void tools::Timer::stop()
{
    if (!_duration)
    {
        _duration.reset(new milliseconds{duration_cast<milliseconds>(
                    system_clock::now() - _time_point)});
    }
}

tools::Timer::operator unsigned long() const
{
    if (!_duration)
        return duration_cast<milliseconds>(system_clock::now() -
                                           _time_point).count();
    else
        return _duration->count();
}

std::ostream &tools::operator <<(std::ostream &os, const Timer &t)
{
    return os << static_cast<unsigned long>(t) << " ms";
}
