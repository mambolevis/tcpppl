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

void ex_10_7::Processor::run(std::istream &is, std::ostream &os)
{
    string line;
    while(getline(is, line))
    {
        ostringstream oss;
        for(size_t i {0}, ni {i + 1}; line.size() > i; ++i, ++ni)
        {
            if ('/' == line[i] && line.size() > ni && '/' == line[ni])
            {
                oss << comment(line.substr(i, line.size() - i));

                break;
            }

            oss << line[i];
        }

        os << oss.str() << endl;
    }
}

std::string ex_10_7::Highlighter::comment(const std::string &s) const
    // highlight comment using escape sequences
{
    ostringstream os;
    os << estd::bold << s << estd::reset;

    return os.str();
}
