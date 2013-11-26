// Created by Samvel Khalatyan on Nov 26, 2013
// Copyright (c) 2013 Samvel Khalatyan. All rights reserved
//
// Use of this source code is governed by a MIT-style license that can be
// found in the LICENSE file.

#include <ostream>

#include "interface/estd_chrono.h"

using std::ostream;
namespace chrono = std::chrono;

ostream &estd::operator<<(ostream &os, const chrono::hours &h)
{
    return os << h.count() << " h";
}

ostream &estd::operator<<(ostream &os, const chrono::minutes &m)
{
    return os << m.count() << " m";
}

ostream &estd::operator<<(ostream &os, const chrono::seconds &s)
{
    return os << s.count() << " s";
}

ostream &estd::operator<<(ostream &os, const chrono::milliseconds &s)
{
    return os << s.count() << " ms";
}

ostream &estd::operator<<(ostream &os, const chrono::microseconds &s)
{
    return os << s.count() << " us";
}

ostream &estd::operator<<(ostream &os, const chrono::nanoseconds &s)
{
    return os << s.count() << " ns";
}
