// Created by Samvel Khalatyan on Nov 26, 2013
// Copyright (c) 2013 Samvel Khalatyan. All rights reserved
//
// Use of this source code is governed by a MIT-style license that can be
// found in the LICENSE file.
//
// (*2) Repeat the histogram drawing example from §5.6.3 for a
//      normal_distribution and 30 rows.

#include <chrono>
#include <iomanip>
#include <iostream>
#include <random>
#include <vector>

using std::cout;
using std::endl;
using std::setw;

using VInt = std::vector<int>;

// hice print histogram
//
std::ostream &operator <<(std::ostream &, const VInt &);

int main(int argc, char *argv[])
{
    // Create generator and distribution
    //
    // (we'll use poisson instead of normal for visual purposes)
    //
    std::default_random_engine g {
        std::chrono::system_clock::now().time_since_epoch().count()};
    std::normal_distribution<double> d {15, 4};

    // bind distribution to generator for short call
    //
    auto rnd = bind(d, g);

    // Create and fill histogram
    VInt hist(30);
    for(int i{0}; 2000 > i; ++i)
    {
        int x {static_cast<int>(rnd())};

        // Put low/high values into under/over-flow bins
        //
        if (x < 0)
            x = 0;
        else if (x > 29)
            x = 29;

        ++hist[x];
    }

    // nice print histogram
    //
    cout << hist << endl;
}

std::ostream &operator <<(std::ostream &os, const VInt &v)
{
    // loop over bins
    //
    for(const auto &x:v)
    {
        // bin ID is calculated on fly: momory and CPU hungry computation
        //
        os << setw(2) << (&x - &v.front()) << "| ";

        // print bin content which is scaled down by x2
        //
        for(int i {0}, counts {x / 2}; counts > i; ++i)
            os << '*';

        // proceed to next bin
        //
        os << endl;
    }

    return os;
}
