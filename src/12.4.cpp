// Created by Samvel Khalatyan on Dec 20, 2013
// Copyright (c) 2013 Samvel Khalatyan. All rights reserved
//
// Use of this source code is governed by a MIT-style license that can be
// found in the LICENSE file.
//
// (*2.5)   Define an apply(v,f) that applies a function f to each element of
//          v assumed to be a vector<Shape∗>. Test apply() with a a variety
//          of functions, function objects, and lambdas.
//          Note that by capturing variables from a lambda or storing values
//          in a function object, you can call Shape functions that takes
//          arguments without having to have f() take explicit arguments.
//          Hint: there is a variety of ways of specifying apply()’s argument
//          types; experiment.

#include <iostream>
#include <vector>

using namespace std;

class Shape
// every shape redefines print
{
    public:
        virtual ~Shape() {}

        virtual void print(ostream &os) const { os << "Shape::print"; }
};

ostream &operator <<(ostream &os, const Shape &s)
// make shapes printable
{
    return (s.print(os), os);
}

using Shapes = vector<Shape *>;

template<typename Function, typename ... Args> 
void apply(Shapes &shapes, Function function_, Args ... args)
    // apply a function to each shape in the vector with possible args
{
    for(auto &s:shapes)
        function_(s, args ...);
}

// -- Test Shapes
//
class Circle: public Shape
{
    public:
        virtual void print(ostream &os) const { os << "Circle::print"; }
};

class Square: public Shape
{
    public:
        virtual void print(ostream &os) const { os << "Square::print"; }
};

// -- functions
//
void noargs(Shape *s)
{
    cout << "-- noargs" << endl;
    cout << *s << endl;
}

void withargs(Shape *s, const int &v)
{
    cout << "-- with args: " << v << endl;
    cout << *s << endl;
}

// -- functor
//
struct NoargsFunctor
{
    void operator()(Shape *s)
    {
        cout << "-- NoargsFunctor" << endl;
        cout << *s << endl;
    };
};

struct ArgsFunctor
{
    void operator()(Shape *s, const char *str)
    {
        cout << "-- ArgsFunctor: " << str << endl;
        cout << *s << endl;
    };
};

int main(int, char *[])
{
    Shape shape;
    Circle circle;
    Square square;

    Shapes shapes {&shape, &circle, &square};

    // -- function
    apply(shapes, noargs);
    cout << endl;

    apply(shapes, withargs, 10);
    cout << endl;

    // -- lambda
    apply(shapes, [](Shape *s) { cout << "-- lambda" << endl << *s << endl; });
    cout << endl;

    // -- functor
    apply(shapes, NoargsFunctor{});
    cout << endl;

    apply(shapes, ArgsFunctor{}, "Hello World!");
}
