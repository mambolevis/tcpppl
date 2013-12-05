// Created by Samvel Khalatyan on Dec 5, 2013
// Copyright (c) 2013 Samvel Khalatyan. All rights reserved
//
// Use of this source code is governed by a MIT-style license that can be
// found in the LICENSE file.

#include <sstream>

#include "interface/estd_tty.h"

using estd::tty::Escape;
using Color = Escape::Color;
using Typeface = Escape::Typeface;

Escape estd::reset {Color::black, Typeface::reset};

Escape estd::red {Color::red};
Escape estd::blue {Color::blue};
Escape estd::green {Color::green};

Escape estd::bold {Color::none, Typeface::bold};
Escape estd::bold_red {Color::red, Typeface::bold};
Escape estd::bold_blue {Color::blue, Typeface::bold};
Escape estd::bold_green {Color::green, Typeface::bold};

Escape::operator std::string() const
{
    using tf = Typeface;

    std::ostringstream os;
    os << "\033[";
    switch(_typeface)
    {
        case tf::none: os << '0'; break;
        case tf::reset: os << '0'; break;
        case tf::bold: os << '1'; break;
        case tf::underline: os << '4'; break;
        case tf::blink: os << '5'; break;
        case tf::reverse: os << "26"; break;
    }

    if (Color::none != _color && _typeface != Typeface::reset)
    {
        os << ';' << (30 + static_cast<int>(_color) -
                           static_cast<int>(Color::black));
    }

    os << 'm';

    return os.str();
}

std::ostream &estd::tty::operator <<(std::ostream &os, const Escape &e)
{
            return os << static_cast<std::string>(e);
}
