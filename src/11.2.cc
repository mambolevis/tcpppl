// Created by Samvel Khalatyan on Dec 11, 2013
// Copyright (c) 2013 Samvel Khalatyan. All rights reserved
//
// Use of this source code is governed by a MIT-style license that can be
// found in the LICENSE file.

#include <iomanip>

#include "interface/11.2.h"

using std::cerr;
using std::cout;
using std::endl;
using std::istream;
using std::string;

namespace parser = reader::parser;

using parser::Values;
using parser::Token;

class KeyComparator
{
    public:
        bool operator ()(const parser::Table::value_type &v1,
                         const parser::Table::value_type &v2)
        {
            return v1.first.size() < v2.first.size();
        }
};

std::ostream &parser::operator <<(std::ostream &os, const Values &values)
{
    for(const auto &v:values)
    {
        os << v;
        if (&v != &values.back())
            os << " ";
    }

    return os;
}

std::ostream &parser::operator <<(std::ostream &os, const Table &t)
{
    using std::setw;

    size_t max_key_length = max_element(t.begin(),
                                        t.end(),
                                        KeyComparator{})->first.size();
    float total_sum {0};
    size_t total_number_of_elements {0};
    for(const auto &entry:t)
    {
        os << setw(max_key_length) << entry.first << ": " <<
            entry.second << endl;

        float sum {0};
        for(const auto &v:entry.second)
            sum += v;

        os << setw(max_key_length) << " " << "   " <<
            "sum: " << sum << " " <<
            "mean: " << sum / entry.second.size() << endl;

        total_sum += sum;
        total_number_of_elements += entry.second.size();
    }

    cout << "total" <<
        " sum: " << total_sum <<
        " mean: " << total_sum / total_number_of_elements << endl;

    return os;
}

parser::Table parser::table;

int parser::errors {0};

parser::Itokenstream parser::itokenstream {std::cin};

parser::value_t parser::error(const string &message)
{
    cerr << message << endl;
    return 1;
}

parser::Itokenstream::Itokenstream(istream &is):
    _is{&is}
{}

istream &parser::Itokenstream::stream(istream &is) noexcept
{
    istream *old_stream = _is;
    _is = &is;

    return *old_stream;
}

Token &parser::Itokenstream::get()
{
    char ch {0};
    *_is >> ch;

    switch(ch)
    {
        case 0:
            _current = {Kind::end};
            break;

        case '0': case '1': case '2': case '3': case '4':
        case '5': case '6': case '7': case '8': case '9':
        case '.':
            _is->putback(ch);
            *_is >> _current.value;

            _current.kind = Kind::number;
            break;

        case ';':
        case ',':
        case '(':
        case ')':
            _current = {static_cast<Kind>(ch)};
            break;

        default:
            if (isalpha(ch))
            {
                _is->putback(ch);
                *_is >> _current.name;

                _current.kind = Kind::name;
                break;
            }

            error("invalid token");
            _current = {Kind::print};
            break;
    }

    return _current;
}

parser::value_t parser::primary(const bool &get)
{
    if (get)
        itokenstream.get();

    switch(itokenstream.current().kind)
    {
        case Kind::lp:
            {
                value_t v = primary(true);
                if (Kind::rp != itokenstream.current().kind)
                    return error("')' is expected");

                itokenstream.get(); // eat ')'
                return v;
            }

        case Kind::name:
            {
                Values &v = table[itokenstream.current().name];
                if (Kind::assign == itokenstream.get().kind)
                    v.push_back(primary(true));

                return v.back();
            }

        case Kind::number:
            {
                value_t value = itokenstream.current().value;
                itokenstream.get(); // advance to next token

                return value;
            }

        default:
            return error("failed primary expression");
    }
}

void parser::driver()
{
    cout << "enter pair of name/value possibly separated by "
        "white-space." << endl;
    cout << "The format is: ( name , value )" << endl;
    cout << "notice spaces b/w parentheces, name, comman and value" << endl;
    cout << "(press Ctrl+D to end session)" << endl;

    while(true)
    {
        itokenstream.get(); // initial read

        if (Kind::end == itokenstream.current().kind)
            break;

        if (Kind::print == itokenstream.current().kind)
        {
            cout << "-- values" << endl;
            cout << table << endl;

            continue;
        }

        if (2 < errors)
        {
            cerr << "too many errors ... stop" << endl;
            break;
        }

        cout << primary(false) << endl;
    }
}
