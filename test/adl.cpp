// Created by Samvel Khalatyan on Jan 29, 2014
// Copyright (c) 2014 Samvel Khalatyan. All rights reserved
//
// Use of this source code is governed by a license that can be found in
// the LICENSE file.

#include <iostream>

using namespace std;

namespace base
{
    struct Struct {};

    void a(const Struct &)
    {
        cout << "base::a(base::Struct)" << endl;
    }

    void b(const Struct &b)
    {
        cout << "base::b(base::Struct)" << endl;

        a(b);
    }

    struct Base
    {
        virtual void a(const Struct &)
        {
            cout << "base::Base::a(base::Struct)" << endl;
        }
    };
}

namespace child
{
    struct Struct {};
    struct CStruct: public base::Struct {};

    void a(const base::Struct &)
    {
        cout << "child::a(base::Struct)" << endl;
    }

    void a(const child::Struct &)
    {
        cout << "child::a(child::Struct)" << endl;
    }

    void a(const child::CStruct &)
    {
        cout << "child::a(child::CStruct)" << endl;
    }

    struct Child: public base::Base
    {
        virtual void a(const base::Struct &)
        {
            cout << "child::Child[Base]::a(base::Struct)" << endl;
        }

        virtual void a(const Struct &)
        {
            cout << "child::Child[Base]::a(child::Struct)" << endl;
        }

        virtual void b(const Struct &s)
        {
            cout << "child::Child[Base]::b(child::Struct)" << endl;

            a(s);
        }
    };
}

int main(int, char *[])
{
    a(base::Struct{});
    cout << "--" << endl;
    b(base::Struct{});
    cout << "--" << endl;
    a(child::Struct{});
    cout << "--" << endl;
    a(child::CStruct{});
    cout << "--" << endl;
    a(static_cast<const base::Struct &>(child::CStruct{}));

    cout << "--" << endl;
    base::Base{}.a(base::Struct{});
    cout << "--" << endl;
    child::Child{}.a(base::Struct{});
    cout << "--" << endl;
    static_cast<base::Base>(child::Child{}).a(base::Struct{});
    cout << "--" << endl;
    child::Child{}.a(child::Struct{});
}
