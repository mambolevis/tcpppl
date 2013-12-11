// Created by Samvel Khalatyan on Dec 11, 2013
// Copyright (c) 2013 Samvel Khalatyan. All rights reserved
//
// Use of this source code is governed by a MIT-style license that can be
// found in the LICENSE file.

#ifndef EXERCISE_11_2
#define EXERCISE_11_2

#include <iostream>
#include <map>
#include <string>
#include <vector>

namespace reader
{
    namespace parser
    {
        using value_t = double; // numbers are floating-point

        using Values = std::vector<value_t>;
        using Table = std::map<std::string, Values>;

        std::ostream &operator <<(std::ostream &, const Values &);
        std::ostream &operator <<(std::ostream &, const Table &);
        
        extern Table table;

        extern int errors;

        enum Kind
        {
            end,

            name,
            number,

            print = ';',
            assign = ',',

            lp = '(',
            rp = ')'
        };

        struct Token
        {
            Kind kind;
            std::string name;
            value_t value;
        };

        value_t error(const std::string &);

        class Itokenstream
        {
            public:
                Itokenstream(std::istream &);

                // get stream
                std::istream &stream() const noexcept { return *_is; }

                // set new stream and return old one
                std::istream &stream(std::istream &) noexcept;

                Token &get();
                Token &current() noexcept { return _current; }

            private:
                std::istream *_is;
                Token _current {Kind::end};
        };

        extern Itokenstream itokenstream;

        value_t primary(const bool &get);

        void driver();
    }

    using parser::itokenstream;
    using parser::driver;
}

#endif
