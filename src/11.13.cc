// Created by Samvel Khalatyan on Dec 12, 2013
// Copyright (c) 2013 Samvel Khalatyan. All rights reserved
//
// Use of this source code is governed by a MIT-style license that can be
// found in the LICENSE file.

#include <iostream>
#include <sstream>

#include "interface/11.13.h"

using std::cout;
using std::endl;
using std::istream;
using std::istringstream;
using std::shared_ptr;
using std::string;

namespace ex = ex_11_13;

using Token = ex::Token;
using Kind = Token::Kind;
using Itokenstream = ex::Itokenstream;
using Calculator = ex::Calculator;

// -- Token stream
//
Itokenstream::Itokenstream(std::istream &is):
    _is{&is}
{}

istream &Itokenstream::stream() const noexcept
{
    return *_is;
}

void Itokenstream::stream(istream &is) noexcept
{
    _is = &is;
}

Token &Itokenstream::get()
    // read next token
{
    char ch {0};
    do
        // skip whitespaces
    {
        if (!_is->get(ch))
            break;
    } while(ch != '\n' && isspace(ch));

    switch(ch)
    {
        case 0: // failed to read istream
            _current.kind = {Kind::end};
            break;

        // either white space of semicolon are signals for print command
        case '\n':
        case ';':
            _current = {Kind::print};
            break;

        case '+':
        case '-':
        case '*':
        case '/':
        case '=':
        case '(':
        case ')':
            _current = {static_cast<Kind>(ch)};
            break;

        case '0': case '1': case '2': case '3': case '4':
        case '5': case '6': case '7': case '8': case '9':
        case '.':
            _is->putback(ch);
            *_is >> _current.value;
            _current.kind = Kind::number;
            break;

        case '@':
            {
                if (Kind::name == get().kind)
                    _current.kind = Kind::function;
                else
                    _current.kind = {Kind::function_list};

                break;
            }

        default:
            if (isalpha(ch))
                // customized name read allows for next token follow the name
                // without space
            {
                _current.name = {ch};
                while(_is->get(ch) && isalpha(ch))
                    _current.name += ch;

                _is->putback(ch);

                _current.kind = Kind::name;
            }
            else
            {
                // failed input
                _current.kind = Kind::end;
            }

            break;
    }

    return _current;
}

string Itokenstream::get_function()
{
    std::string function;

    for(char ch; _is->get(ch); )
    {
        // skip wite spaces at the beginning
        if (function.empty() and isspace(ch))
            continue;

        if (ch == '\n')
            break;

        function += ch;
    }

    _current = {Kind::print};

    return function;
}

const Token &Itokenstream::current() const noexcept
{
    return _current;
}


// -- Calculator
//
Calculator::Calculator():
    _its{new Itokenstream{std::cin}}
{
    // add several constants
    //
    _table["pi"] = 3.14;
    _table["e"] = 2.71;

    _functions["abc"] = "2 + 3";
}

void Calculator::run()
    // driver continuously process input
{
    while(valid())
    {
        prompt();

        _its->get();

        if (Kind::end == _its->current().kind)
            break;

        if (Kind::print == _its->current().kind)
            continue;

        if (Kind::function_list == _its->current().kind)
        {
            for(const auto &f:_functions)
            {
                cout << "@" << f.first << ": " << f.second << endl;
            }

            continue;
        }

        print(expression(false));
    }
}

Calculator::value_type Calculator::expression(const bool &get)
{
    value_type left = term(get);
    while(true)
    {
        switch(_its->current().kind)
        {
            case Kind::plus:
                left += term(true);
                break;

            case Kind::minus:
                left -= term(true);
                break;

            default:
                return left;
        }
    }
}

Calculator::value_type Calculator::term(const bool &get)
{
    value_type left = primary(get);
    while(true)
    {
        switch(_its->current().kind)
        {
            case Kind::multiply:
                left *= primary(true);
                break;

            case Kind::divide:
                if (value_type value = primary(true))
                    left /= value;
                else
                    error("division by zero");

                break;

            default:
                return left;
        }
    }
}

Calculator::value_type Calculator::primary(const bool &get)
{
    if (get)
        _its->get();

    switch(_its->current().kind)
    {
        case Kind::number:
            {
                value_type value {_its->current().value};
                _its->get();

                return value;
            }

        case Kind::minus:
            return -primary(true);

        case Kind::name:
            {
                value_type &value = _table[_its->current().name];
                if (Kind::assign == _its->get().kind)
                    value = expression(true);

                return value;
            }

        case Kind::function:
            {
                string function_name = _its->current().name;
                string &function = _functions[function_name];

                if (Kind::assign == _its->get().kind)
                    function = _its->get_function();

                cout << '@' << function_name << ": " << function << endl;

                // evaluate function
                Calculator calc_ss;

                calc_ss._table = _table; // copy constants
                calc_ss._functions = _functions; // copy functions

                // don't allow recursive calls
                calc_ss._functions.erase(function_name);

                istringstream iss {function};
                calc_ss._its =
                    shared_ptr<Itokenstream>{new Itokenstream{iss}};

                calc_ss._its->get();


                return calc_ss.expression(false);
            }

        case Kind::lp:
            {
                value_type value = expression(true);
                if (Kind::rp == _its->current().kind)
                {
                    _its->get();    // eat ')'

                    return value;
                }

                // fall through
            }

        default:
            error("unsupported primary");
    }

    return 1;
}

void Calculator::error(const std::string &message)
{
    ++_errors;

    std::cerr << message << endl;
}

const int &Calculator::errors() const noexcept
{
    return _errors;
}

bool Calculator::valid()
{
    return not _errors;
}

void Calculator::print(const value_type &value)
{
    std::cout << value << endl;
}

void Calculator::prompt()
{
    cout << ">>> ";
}
