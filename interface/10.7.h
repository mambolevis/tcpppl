// Created by Samvel Khalatyan on Dec 5, 2013
// Copyright (c) 2013 Samvel Khalatyan. All rights reserved
//
// Use of this source code is governed by a MIT-style license that can be
// found in the LICENSE file.

#ifndef EXERCISE_10_7
#define EXERCISE_10_7

#include <iosfwd>
#include <string>

namespace ex_10_7
{
    class Processor
    {
        public:
            virtual ~Processor() {}

            void run(std::istream &, std::ostream &);

        private:
            virtual std::string comment(const std::string &) const = 0;
    };

    class Remover : public Processor
                    // strip comment
    {
        private:
            virtual std::string comment(const std::string &) const
                // remove comment
            { 
                return "";
            }
    };

    class Highlighter: public Processor
                       // highlight comment
    {
        public:
            enum class Color {bold, red, green, blue};

            Highlighter(const Color &c=Color::bold);

        private:
            virtual std::string comment(const std::string &s) const
                // highlight comment using escape sequences
            {
                return _escape + s + "\033[0m";
            }

            std::string _escape {"\033[1"};
    };
}

#endif
