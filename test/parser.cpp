// Created by Samvel Khalatyan on Dec 10, 2013
// Copyright (c) 2013 Samvel Khalatyan. All rights reserved
//
// Use of this source code is governed by a MIT-style license that can be
// found in the LICENSE file.

#include <cctype>
#include <iostream>
#include <map>
#include <sstream>
#include <string>

using std::cout;
using std::endl;
using std::istringstream;

namespace calc
{
    using std::cerr;
    using std::cin;
    using std::istream;
    using std::map;
    using std::string;

    using Value = double;

    map<string, Value> variables {
        {"pi", 3.14},
        {"e", 2.71}
    };

    enum class Kind : char
    {
        name,
        number,
        end,
       
        assign = '=',

        print = ';',

        plus = '+',
        minus = '-',
        multiply = '*',
        divide = '/',

        lp = '(',
        rp = ')'
    };

    struct Token
    {
        Kind kind;

        string name;
        Value value;
    };

    class itokenstream
    {
        public:
            itokenstream(istream &is=cin):
                _is(&is)
            {}

            istream &stream() const noexcept { return *_is; }
            istream &stream(istream &is) noexcept
            {
                istream *last_is {_is};
                _is = &is;

                return *last_is;
            }

            Token get();
            const Token &current() const noexcept { return _current_token; }

        private:
            istream *_is;
            Token _current_token {Kind::end};
    };

    itokenstream its;
    Value errors {0};

    Value error(const string &str)
    {
        ++errors;

        cerr << str << endl;
        return 1;
    }

    Value term(const bool &);
    Value primary(const bool &);

    Value expression(const bool &get)
    {
        Value result {term(get)};
        while(true)
        {
            switch(its.current().kind)
            {
                case Kind::plus:
                    result += term(true);
                    break;

                case Kind::minus:
                    result -= term(true);
                    break;

                default:
                    return result;  // exit point
            }
        }
    }

    Value term(const bool &get)
    {
        Value result {primary(get)};
        while(true)
        {
            switch(its.current().kind)
            {
                case Kind::multiply:
                    result *= primary(true);
                    break;

                case Kind::divide:
                    if (Value denominator {primary(true)})
                    {
                        result /= denominator;
                        break;
                    }
                    return error("divide by 0");

                default:
                    return result;  // exit point
            }
        }
    }

    Value primary(const bool &get)
    {
        if (get)
            its.get();

        switch(its.current().kind)
        {
            case Kind::number:
                {
                    Value value {its.current().value};
                    its.get();   // advance to next token
                    return value;
                }

            case Kind::minus:   // unari minus
                return -primary(true);

            case Kind::name:
                {
                    Value &value = variables[its.current().name];
                    if (Kind::assign == its.get().kind)
                        value = expression(true);

                    return value;
                }

            case Kind::lp:
                {
                    Value value{expression(true)};
                    if (Kind::rp != its.current().kind)
                        return error("')' is expected");

                    its.get();   // eat ')'
                    return value;
                }

            default:
                return error("primary expression is expected");
        }
    }

    Token itokenstream::get()
    {
        char ch {0};

        do
        {
            if (!_is->get(ch))
                return _current_token = {Kind::end};

        } while(ch != '\n' && isspace(ch));

        switch(ch)
        {
            case 0: // failed to read - end of line
                return _current_token = {Kind::end};

            case '\n':
            case ';':
                return _current_token = {Kind::print};

            case '+':
            case '-':
            case '*':
            case '/':
            case '(':
            case ')':
            case '=':
                return _current_token = {static_cast<Kind>(ch)};

            case '0': case '1': case '2': case '3': case '4':
            case '5': case '6': case '7': case '8': case '9':
            case '.':
                _is->putback(ch);
                *_is >> _current_token.value;
                _current_token.kind = Kind::number;
                return _current_token;

            default:
                if (isalpha(ch))
                {
                    string name {ch};
                    while(_is->get(ch) && isalnum(ch))
                            name += ch;

                    _is->putback(ch);
                    return _current_token = {Kind::name, name};
                }

                error("unsupported token");
                return _current_token = {Kind::print};
        }
    }

    void driver()
    {
        while(true)
        {
            its.get();

            if (Kind::end == its.current().kind)
                break;

            if (Kind::print == its.current().kind)
                continue;

            if (errors > 5)
            {
                error("too many errors... stop");
                break;
            }

            cout << expression(false) << endl;
        }
    }
}

int main(int argc, char *argv[])
{
    if (1 < argc)
    {
        // note: ASSERT_TRUE(argv[argc] == 0)
        for(decltype(argc) i {1}; argv[i]; ++i)
        {
            istringstream iss{argv[i]};
            cout << iss.str() << " > ";
            calc::its.stream(iss);

            calc::driver();
        }
    }
    else
        calc::driver();

    return calc::errors;
}
