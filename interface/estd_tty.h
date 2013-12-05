// Created by Samvel Khalatyan on Dec 5, 2013
// Copyright (c) 2013 Samvel Khalatyan. All rights reserved
//
// Use of this source code is governed by a MIT-style license that can be
// found in the LICENSE file.

#ifndef EXTENDED_STD_ESCAPE_SEQUENCE
#define EXTENDED_STD_ESCAPE_SEQUENCE

#include <iosfwd>
#include <string>

namespace estd 
{
    namespace tty
    {
        class Escape
        {
            public:
                // colors order is important
                enum class Color { none,
                                   black, red, green, yellow, blue,
                                   magenta, cyan, white };

                enum class Typeface { none, reset,
                                      bold, underline,
                                      blink, reverse };

                Escape(const Color &c=Color::none,
                       const Typeface &t=Typeface::none):
                    _color{c},
                    _typeface{t}
                {}

                operator std::string () const;

            private:
                const Color _color;
                const Typeface _typeface;
        };

        std::ostream &operator <<(std::ostream &, const Escape &);
    }

    using tty::Escape;

    extern Escape reset;

    extern Escape red;
    extern Escape blue;
    extern Escape green;

    extern Escape bold;
    extern Escape bold_red;
    extern Escape bold_blue;
    extern Escape bold_green;
}

#endif
