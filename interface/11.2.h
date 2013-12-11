// Created by Samvel Khalatyan on Dec 11, 2013
// Copyright (c) 2013 Samvel Khalatyan. All rights reserved
//
// Use of this source code is governed by a MIT-style license that can be
// found in the LICENSE file.

#ifndef EXERCISE_11_2
#define EXERCISE_11_2

#include <iosfwd>
#include <map>
#include <string>
#include <vector>

namespace reader
{
    namespace parser
    {
        using value_t = double; // numbers are floating-point

        enum Kind
            // enumerate all possible tokens
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
            // depending on a kind either name or value (or even neither of
            // the two) is used, e.g.:
            //
            //  Kind    Property used
            //
            //  end     -
            //
            //  name    name
            //  number  value
            //
            //  print   -
            //  assign  -
            //  lp      -
            //  rp      -
        {
            Kind kind;
            std::string name;
            value_t value;
        };

        class Itokenstream
            // low-level stream parser, e.g. token reader
        {
            public:
                Itokenstream(std::istream &is):
                    _is(&is)
                {}

                // get stream
                std::istream &stream() const noexcept { return *_is; }

                // set new stream and return old one
                std::istream &stream(std::istream &) noexcept;

                // read next token
                Token &get();

                // access current token
                Token &current() noexcept { return _current_token; }

            private:
                std::istream *_is;
                Token _current_token {Kind::end};
        };

        // print error message and count errors
        value_t error(const std::string &);

        // an expression is:
        //
        //      (primary)
        //
        void expression(const bool &get);

        // read primary expression
        value_t primary(const bool &get);

        void driver();  // application entry point

        // the same name may be defined several times: keep list of values
        // in a map
        using Values = std::vector<value_t>;
        using Table = std::map<std::string, Values>;
        
        // tokenizer is automatically initialized with CIN
        extern Itokenstream itokenstream;
        extern Table table; // read values
        extern int errors; // count number of errors occured

        // make table printable
        std::ostream &operator <<(std::ostream &, const Values &);
        std::ostream &operator <<(std::ostream &, const Table &);
    }

    // make application main parts easily accessible
    using parser::itokenstream;
    using parser::driver;
}

#endif
