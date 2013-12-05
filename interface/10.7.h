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
        private:
            virtual std::string comment(const std::string &) const;
    };
}

#endif
