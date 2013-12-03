// Created by Samvel Khalatyan on Dec 2, 2013
// Copyright (c) 2013 Samvel Khalatyan. All rights reserved
//
// Use of this source code is governed by a MIT-style license that can be
// found in the LICENSE file.

#include <iostream>
#include <regex>
#include <sstream>
#include <stdexcept>
#include <vector>
#include <utility>

#include "interface/9.4.h"

using std::regex;

using ex_9_4::Month;

using month_re = std::pair<Month, regex>;
std::regex::flag_type flags {std::regex_constants::ECMAScript |
                             std::regex_constants::icase};
month_re patterns[]
{
    {Month::jan, regex{R"*((1|jan(uary)?))*", flags}},
    {Month::feb, regex{R"*((2|feb(ruary)?))*", flags}},
    //
    {Month::mar, regex{R"*((3|mar(ch)?))*", flags}},
    {Month::apr, regex{R"*((4|apr(il)?))*", flags}},
    {Month::may, regex{R"*((5|may))*", flags}},
    //
    {Month::jun, regex{R"*((6|jun(e)?))*", flags}},
    {Month::jul, regex{R"*((7|jul(y)?))*", flags}},
    {Month::aug, regex{R"*((8|aug(ust)?))*", flags}},
    //
    {Month::sep, regex{R"*((9|sep(tember)?))*", flags}},
    {Month::oct, regex{R"*((10|oct(ober)?))*", flags}},
    {Month::nov, regex{R"*((11|nov(ember)?))*", flags}},
    //
    {Month::dec, regex{R"*((12|dec(ember)?))*", flags}}
};

std::istream &ex_9_4::operator >>(std::istream &is, Month &m)
{
    std::string value;
    is >> value;
    for(const auto &p:patterns)
    {
        if (regex_match(value, p.second))
        {
            m = p.first;
            value.clear();
            break;
        }
    }

    if (value.empty())
        return is;
    else
        throw std::runtime_error("invalid month code used");
}

std::ostream &ex_9_4::operator <<(std::ostream &os, const Month &m)
{
    switch(m)
    {
    	case Month::jan: os << "jan"; break;
    	case Month::feb: os << "feb"; break;
        //
    	case Month::mar: os << "mar"; break;
    	case Month::apr: os << "apr"; break;
    	case Month::may: os << "may"; break;
        //
    	case Month::jun: os << "jun"; break;
    	case Month::jul: os << "jul"; break;
    	case Month::aug: os << "aug"; break;
        //
    	case Month::sep: os << "sep"; break;
    	case Month::oct: os << "oct"; break;
    	case Month::nov: os << "nov"; break;
        //
    	case Month::dec: os << "dec"; break;

        default: throw std::runtime_error("unsupported month");
    }

    return os;
}

void ex_9_4::unit_test::test_month_is()
{
    using std::cout;
    using std::endl;
    using std::string;
    using patterns = std::vector<string>;
    using test = std::pair<Month, patterns>;

    cout << "-- run month istream tests" << endl;

    std::vector<test> tests
    {
        {Month::jan, {"1", "jan", "january"}},
        {Month::feb, {"2", "feb", "february"}},
        {Month::mar, {"3", "mar", "march"}},
        {Month::apr, {"4", "apr", "april"}},
        {Month::may, {"5", "may"}},
        {Month::jun, {"6", "jun", "june"}},
        {Month::jul, {"7", "jul", "july"}},
        {Month::aug, {"8", "aug", "august"}},
        {Month::sep, {"9", "sep", "september"}},
        {Month::oct, {"10", "oct", "october"}},
        {Month::nov, {"11", "nov", "november"}},
        {Month::dec, {"12", "dec", "december"}}
    };

    for(const auto &t:tests)
    {
        Month m;
        for(const auto &p:t.second)
        {
            try
            {
                std::istringstream is(p);
                is >> m;
                if (m != t.first)
                    throw std::runtime_error("failed");
            }
            catch(const std::runtime_error &e)
            {
                cout << "pattern: " << p << " failed" << endl;
            }
        }
    }
}

void ex_9_4::unit_test::test_month_os()
{
    using std::cout;
    using std::endl;
    using std::string;
    using test = std::pair<Month, string>;

    cout << "-- run month ostream tests" << endl;

    std::vector<test> tests
    {
        {Month::jan, "jan"},
        {Month::feb, "feb"},
        {Month::mar, "mar"},
        {Month::apr, "apr"},
        {Month::may, "may"},
        {Month::jun, "jun"},
        {Month::jul, "jul"},
        {Month::aug, "aug"},
        {Month::sep, "sep"},
        {Month::oct, "oct"},
        {Month::nov, "nov"},
        {Month::dec, "dec"}
    };

    for(const auto &t:tests)
    {
        Month m {t.first};
        try
        {
            std::ostringstream os;
            os << m;
            if (os.str() != t.second)
                throw std::runtime_error("failed");
        }
        catch(const std::runtime_error &e)
        {
            cout << "month: " << t.second << " failed" << endl;
        }
    }

}
