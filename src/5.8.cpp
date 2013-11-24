// Created by Samvel Khalatyan on Nov 24, 2013
// Copyright (c) 2013 Samvel Khalatyan. All rights reserved
//
// Use of this source code is governed by a MIT-style license that can be
// found in the LICENSE file.
//
// (*1) Repeat §X.5[7] with a vector<string> initialized with
//      "Kant", "Plato", "Aristotle", "Kierkegard", and "Hume".

#include <string>
#include <vector>

#include "interface/5.7.h"

int main(int argc, char *argv[])
{
    std::vector<std::string> values {
        "Kant", "Plato", "Aristotle", "Kierkegard", "Hume"
    };
    ex_5_7::run(values);
}
