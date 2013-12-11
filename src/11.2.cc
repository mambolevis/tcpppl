// Created by Samvel Khalatyan on Dec 11, 2013
// Copyright (c) 2013 Samvel Khalatyan. All rights reserved
//
// Use of this source code is governed by a MIT-style license that can be
// found in the LICENSE file.

#include <iomanip>
#include <iostream>

#include "interface/11.2.h"

using std::cerr;
using std::cout;
using std::endl;
using std::istream;
using std::string;

namespace parser = reader::parser;  // shortcut the names in code

using parser::Values;
using parser::Token;

parser::Itokenstream parser::itokenstream {std::cin};
parser::Table parser::table;
int parser::errors {0};

parser::value_t parser::error(const string &message)
    // print error message and increase errors counter
{
    ++errors;

    cerr << message << endl;
    return 1;
}

istream &parser::Itokenstream::stream(istream &is) noexcept
    // set new input stream and return old one
{
    istream *old_stream = _is;
    _is = &is;

    return *old_stream;
}

Token &parser::Itokenstream::get()
    // read next token
{
    char ch {0};
    do
    {
        if (!_is->get(ch))
            return _current_token = {Kind::end};
    } while(ch != '\n' && isspace(ch));

    switch(ch)
    {
        case 0:
            // failed to read char: eof
            _current_token = {Kind::end};
            break;

        case '\n':
        case ';':
            return _current_token = {Kind::print};

        // numbers
        case '0': case '1': case '2': case '3': case '4':
        case '5': case '6': case '7': case '8': case '9':
        case '.':
            _is->putback(ch);
            *_is >> _current_token.value;

            _current_token.kind = Kind::number;
            break;

        // special symbols
        case ',':
        case '(':
        case ')':
            _current_token = {static_cast<Kind>(ch)};
            break;

        default:
            if (isalpha(ch))
            {
                string name {ch};
                while(_is->get(ch) && isalpha(ch))
                   name += ch; 

                _is->putback(ch);

                _current_token = {Kind::name, name};
            }
            else
            {
                error("invalid token");
                _current_token = {Kind::print};
            }

            break;
    }

    return _current_token;
}

void parser::expression(const bool &get)
    // parse expression of the form:
    //
    //      ( primary )
    //
{
    if (get)
        itokenstream.get();

    while(true)
        // there might be more than one expression in the row
    {
        switch(itokenstream.current().kind)
        {
            case Kind::lp: // each expression starts with '('
                primary(true);  // the result of primary is unnecessary

                if (Kind::rp != itokenstream.current().kind)
                    // and expression should end with ')'
                {
                    error("')' is expected");
                    return;
                }

                itokenstream.get(); // eat ')'
                break;

            // any unsupported expression exits processing
            default:
                return;
        }
    }
}

parser::value_t parser::primary(const bool &get)
    // parse primary which is either "number" or "name , number"
{
    if (get)
        itokenstream.get();

    switch(itokenstream.current().kind)
    {
        case Kind::name:
            {
                Values &v = table[itokenstream.current().name];
                if (Kind::assign == itokenstream.get().kind)
                    // recursive call of the primary function will let user
                    // input number only as primary: this is left intentionally
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

        expression(false);
    }
}

class KeyComparator
    // compare two iterm of the Table and choose the one with largest key
    // (the key is string)
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
