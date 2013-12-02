// Created by Samvel Khalatyan on Dec 2, 2013
// Copyright (c) 2013 Samvel Khalatyan. All rights reserved
//
// Use of this source code is governed by a MIT-style license that can be
// found in the LICENSE file.

#include <iostream>
#include <stdexcept>

#include "interface/7.6.h"

using std::cout;
using std::endl;

using namespace ex_7_6;

// enum class does not support implicit conversions
// plain enum does

enum class TrafficLight : char; // enum can be declared
enum PlainTrafficLight : char;  // plain enumeration declaration

enum class RainbowColor;    // default type is used (int)
// enum PlainRainbowColor;  // error: can not forward declaration of plain
                            // enum with default type

enum class TrafficLight : char { green, yellow, red}; // definition
enum PlainTrafficLight : char { green, yellow, red}; // definition

enum class RainbowColor { red, orange, yellow, green, blue, indigo, violet };

// plain enumerations shat the same namespace and all constans fall into the
// same block, therefore no two constants may have the same name. But each
// enum class is isolated. 
//
// enum PlainRainbowColor { red, orange, yellow, green, blue, indigo, violet };

std::ostream &operator <<(std::ostream &os, const TrafficLight &t)
{
    switch(t)
    {
        case TrafficLight::green:
            os << "green";
            break;

        case TrafficLight::yellow:
            os << "yellow";
            break;

        case TrafficLight::red:
            os << "red";
            break;

        default:
            throw std::invalid_argument("unsupported Traffic Light");
    }

    return os;
}

std::ostream &operator <<(std::ostream &os, const RainbowColor &t)
{
    switch(t)
    {
        case RainbowColor::red:
            os << "red";
            break;

        case RainbowColor::orange:
            os << "orange";
            break;

        case RainbowColor::yellow:
            os << "yellow";
            break;

        case RainbowColor::green:
            os << "green";
            break;

        case RainbowColor::blue:
            os << "blue";
            break;

        case RainbowColor::indigo:
            os << "indigo";
            break;

        case RainbowColor::violet:
            os << "violet";
            break;

        default:
            throw std::invalid_argument("unsupported Rainbow Color");
    }

    return os;
}

template<typename T>
    std::ostream &operator <<(std::ostream &os, const Info<T> &info)
    {
        return os << type_name(info) << " has size " << sizeof(T) << " B";
    }

int main(int, char *[])
{
    cout << "-- types and sizes" << endl;
    cout << Info<TrafficLight>{} << endl;
    cout << Info<PlainTrafficLight>{} << endl;
    cout << Info<RainbowColor>{} << endl;

    cout << "-- enum class initialization and arithmetics" << endl;
    cout << TrafficLight{} << endl;
    cout << TrafficLight{TrafficLight::red} << endl;
    cout << TrafficLight{static_cast<TrafficLight>(1)} << endl;
}
