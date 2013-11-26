// Created by Samvel Khalatyan on Nov 26, 2013
// Copyright (c) 2013 Samvel Khalatyan. All rights reserved
//
// Use of this source code is governed by a MIT-style license that can be
// found in the LICENSE file.

#include <chrono>
#include <iomanip>
#include <iostream>
#include <random>
#include <vector>

using std::cout;
using std::endl;
using std::setw;

using IVector = std::vector<int>;
using Function = std::function<int()>;

template<typename D>
    Function dice(const D &distribution)
    {
        using generator = std::default_random_engine;

        generator g(std::chrono::system_clock::now().time_since_epoch().count());

        return std::bind(distribution, g);    // let dice act as a function
    }

Function uniform_dice(const int &max=5)
{
    return dice(std::uniform_int_distribution<int>{0, max});
}

Function normal_dice(const int &mean=2)
{
    return dice(std::poisson_distribution<int>{mean});
}

IVector histogram(Function dice, const int &max=5)
{
    IVector hist(max + 1);
    for(int i {200}; i; --i)
    {
        int x = dice();
        if (x < 0)
            x = 0;
        else if (x > max)
            x = max;

        hist[x] += 1;
    }

    return hist;
}

std::ostream &operator <<(std::ostream &os, const IVector &v)
{
    for(const auto &x:v)
    {
        os << setw(2) << (&x - &*v.begin()) + 1 << "| ";
        for(int j {1}, max {x / 2}; max > j; ++j)
            cout << '*';

        os << endl;
    }

    return os;
}

int main(int argc, char *argv[])
{
    cout << "-- uniform dice" << endl;
    cout << histogram(uniform_dice(9), 9) << endl;

    cout << "-- normal dice" << endl;
    cout << histogram(normal_dice(4), 9) << endl;
}
