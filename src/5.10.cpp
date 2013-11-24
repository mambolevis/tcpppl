// Created by Samvel Khalatyan on Nov 24, 2013
// Copyright (c) 2013 Samvel Khalatyan. All rights reserved
//
// Use of this source code is governed by a MIT-style license that can be
// found in the LICENSE file.
//
// (*1) Open the file of integers from §X.5[9] for reading (as an ifstream)
//      and read it.

#include <iostream>
#include <fstream>

#include "interface/estd_vector.h"
#include "interface/5.9.h"

using std::cerr;
using std::cout;
using std::endl;
using std::ifstream;

using namespace estd;

using Vint = std::vector<int>;

bool compare(const Vint &v1, const Vint &v2)
{
    if (v1.size() != v2.size())
        return false;

    for(Vint::const_iterator v1iter {v1.begin()}, v2iter {v2.begin()};
            v1.end() != v1iter;
            ++v1iter, ++v2iter)
    {
        if (*v1iter != *v2iter)
            return false;
    }

    return true;
}

int main(int argc, char *argv[])
{
    using ex_5_9::filename;

    ifstream is(filename);
    if (is.good())
    {
        std::vector<int> values;
        int value;
        while(is >> value)
        {
            values.push_back(value);
        }

        cout << "values are read from " << filename << endl;
        cout << "validating ... " <<
            (compare(values, ex_5_9::values()) ? "valid" : "invalid") << endl;
    }
    else
    {
        cerr << "failed to open " << filename << " for read" << endl;
    }
}
