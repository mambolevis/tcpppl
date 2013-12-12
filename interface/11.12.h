// Created by Samvel Khalatyan on Dec 12, 2013
// Copyright (c) 2013 Samvel Khalatyan. All rights reserved
//
// Use of this source code is governed by a MIT-style license that can be
// found in the LICENSE file.

#ifndef EXERCISE_11_12
#define EXERCISE_11_12

#include "interface/11.11.h"

namespace ex_11_12
{
    class Calculator : public ex_11_11::Calculator
    {
        protected:
            virtual void error(const std::string &message); 

        private:
            virtual bool valid(); // increase errors threshold

            virtual void prompt();

            int _line_number;
    };
}

#endif
