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
        using value_type = double; // all numbers are floating-point

        enum class Kind : char
            // supported token types
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
        // input stream parser: extract tokens
    {
        public:
            Itokenstream(std::istream &);

            std::istream &stream() const noexcept;  // get stream
            void stream(std::istream &) noexcept; // set new stream

            Token &get();   // read next token from istream
            const Token &current() const noexcept;  // access last token

        private:
            using Kind = Token::Kind;

            std::istream *_is;

            Token _current {Kind::end}; // last read token
    };

    class Calculator
        // Calculator backend which combines tokens into primary expressions,
        // terms, expressions and expression lists.
    {
        public:
            using value_type = Token::value_type;

            Calculator(); // use CIN for Tokenizer by default
            virtual ~Calculator() {}

            // driver:
            //      end
            //      expression_list end
            //
            //  expression_list:
            //      expression print
            //      expression print expression_list
            void run(); // driver

            // expression:
            //      term
            //      term + term
            //      term - term
            value_type expression(const bool &);

            // term:
            //      primary
            //      primary * primary
            //      primary / primary
            value_type term(const bool &);

            // primary:
            //      number
            //      name
            //      name = expression
            //      -primary
            //      (expression)
            value_type primary(const bool &);

            // count number of errors and print an error message
            void error(const std::string &);

        private:
            // determine whether calculator should continue running
            virtual bool valid(); 

            int _errors {0}; // count number of errors

            std::map<std::string, value_type> _table; // constants
            std::shared_ptr<Itokenstream> _its; // input stream parser
    };
}

#endif
