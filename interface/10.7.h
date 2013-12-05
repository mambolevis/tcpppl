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
    // status indicates what processor is working on at the moment. It might
    // be regular code (none), long comment (comment), or string literal
    // (string). The status is used internally by processor.
    //
    enum class Status { none = 1, comment = 2, string = 4 };

    Status operator &(const Status &, const Status &);
    Status operator |(const Status &, const Status &);
    Status operator ^(const Status &, const Status &);

    class Processor
        // process comments in a stream with C++ source
        //
        // The comment policy is defined by child classes through overloaded
        // comment(...) function.
    {
        public:
            virtual ~Processor() {}

            // run processor on istream and output to ostream
            void run(std::istream &, std::ostream &);

        private:
            // comment policy: highlight, remove, etc.
            virtual std::string comment(const std::string &) const = 0;

            // check if 'in' starts with 'what'
            bool submatch(const char *in, const char *what) const;

            // signal what processor is currently working on: regular code,
            // string literal, or multi-line comment.
            //
            Status _status {Status::none};
    };

    class Remover : public Processor
        // use empty strings instead of each and every comment
    {
        private:
            virtual std::string comment(const std::string &) const
            { 
                return "";
            }
    };

    class Highlighter: public Processor
       // highlight each and every comment
    {
        private:
            virtual std::string comment(const std::string &) const;
    };
}

#endif
