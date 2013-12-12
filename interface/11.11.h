// Created by Samvel Khalatyan on Dec 12, 2013
// Copyright (c) 2013 Samvel Khalatyan. All rights reserved
//
// Use of this source code is governed by a MIT-style license that can be
// found in the LICENSE file.
//
// Calculator syntax:
//
// driver:
//      end
//      expression_list end
//
// expression_list:
//      expression print
//      expression print expression_list
//
// expression:
//      term
//      expression + term
//      expression - term
//
//  term:
//      primary
//      term * primary
//      term / primary
//      term % primary
//
//  primary:
//      number
//      name
//      name = number
//      -primary
//      +primary
//      (expression)

#ifndef EXERCISE_11_11
#define EXERCISE_11_11

#include <iosfwd>
#include <map>
#include <memory>
#include <string>

namespace ex_11_11
{
    struct Token
    {
        using value_type = double;

        enum class Kind : char
        {
            end,
            print = ';',

            name,
            number,

            plus = '+',
            minus = '-',

            multiply = '*',
            divide = '/',

            assign = '=',

            lp = '(',
            rp = ')'
        };

        Kind kind;
        std::string name;
        value_type value;
    };

    class Itokenstream
    {
        public:
            Itokenstream(std::istream &);

            std::istream &stream() const noexcept;  // get stream
            void stream(std::istream &) noexcept; // set new stream

            Token &get();
            const Token &current() const noexcept;

        private:
            using Kind = Token::Kind;

            std::istream *_is;

            Token _current {Kind::end};
    };

    class Calculator
    {
        public:
            using value_type = Token::value_type;

            Calculator();

            void run(); // driver

            value_type expression(const bool &);
            value_type term(const bool &);
            value_type primary(const bool &);

            void error(const std::string &);

        private:
            int _errors {0}; // count number of errors

            std::map<std::string, value_type> _table;
            std::shared_ptr<Itokenstream> _its;
    };
}

#endif
