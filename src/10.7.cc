// Created by Samvel Khalatyan on Dec 5, 2013
// Copyright (c) 2013 Samvel Khalatyan. All rights reserved
//
// Use of this source code is governed by a MIT-style license that can be
// found in the LICENSE file.

#include <iostream>
#include <sstream>
#include <string>

#include "interface/10.7.h"
#include "interface/estd_tty.h"

using std::endl;
using std::string;
using std::istringstream;
using std::ostringstream;

using ex_10_7::Status;
using ex_10_7::Processor;

Status ex_10_7::operator &(const Status &s1, const Status &s2)
{
    return static_cast<Status>(static_cast<int>(s1) &
                               static_cast<int>(s2));
}

Status ex_10_7::operator |(const Status &s1, const Status &s2)
{
    return static_cast<Status>(static_cast<int>(s1) |
                               static_cast<int>(s2));
}

Status ex_10_7::operator ^(const Status &s1, const Status &s2)
{
    return static_cast<Status>(static_cast<int>(s1) ^
                               static_cast<int>(s2));
}

void Processor::run(std::istream &is, std::ostream &os)
{
    // process file line by line
    string line;
    while(getline(is, line))
    {
        // oss will keep formatted line of text with processed comments
        ostringstream oss;

        // scan line by chars and look for comment patterns
        for(const char *p {line.c_str()}; *p; ++p)
        {
            // check if it is string literal
            if (Status::comment != _status && '"' == *p)
            {
                _status = (Status::string == _status) ?
                          Status::none :
                          Status::string;
            }
            // one line comment? Should be scanned only in status different
            // than string literal or multi-line comment
            else if (Status::none == _status && submatch(p, "//"))
            {
                // mark the rest of the line as comment and skip to the next
                // line
                oss << comment(line.substr(p - line.c_str(),
                                           line.size() - (p - line.c_str())));

                break;
            }
            // multi-line comment? It may be split over several lines of code.
            // The body cashes the line until either the end of the comment is
            // found or the end of line is reached. In the latter case the
            // code should be able to re-enter the block and continue scan for
            // the closing block. The comment is accumulated in buffer that
            // is commented later and added to the output stream.
            else if (Status::comment == _status ||
                     (Status::none == _status && submatch(p, "/*")))
            {
                ostringstream buf; // comment buffer

                // skip /* if the runflow got here this way
                if (Status::none == _status)
                {
                    // put two symbols into buffer, e.g. /*,
                    // and set status to comment
                    buf << *(p++);
                    buf << *(p++);

                    _status = Status::comment;
                }

                // find closing sequence */ or eof. In the latter case the
                // code will revisit block on the next line
                while(*p)
                {
                    if (submatch(p, "*/"))
                    {
                        // add two symbols */ to the buffer and set status to
                        // non-comment.
                        // Note: p will be automatically advanced in the outter
                        //       loop. This is essencial for several multi-line
                        //       comments in the same line.
                        //
                        // next like is used for demonstration purposes
                        ; /* like */ ; /* this one */
                        buf << *(p++);
                        buf << *p;

                        _status = Status::none;

                        break;
                    } 

                    // closing sequence was not found: symbol is a part of
                    // comment
                    buf << *(p++);
                }

                // mark buffer as comment and continue as usual
                oss << comment(buf.str());

                if (*p)
                    continue;
                else
                    break;
            }

            oss << *p;
        }

        os << oss.str() << endl;
    }
}

bool Processor::submatch(const char *str, const char *pattern) const
    // check if str starts with pattern
{
    // continue until pattern is exhausted
    for(; *pattern; ++str, ++pattern)
    {
        // the source string 'str' may exhaust before the pattern finishes
        if (!*str || *str != *pattern)
            return false;
    }

    return true;
}

std::string ex_10_7::Highlighter::comment(const std::string &s) const
    // highlight the comment in color
{
    ostringstream os;
    os << estd::bold_red << s << estd::reset;

    return os.str();
}
