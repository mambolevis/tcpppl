// Created by Samvel Khalatyan on Dec 10, 2013
// Copyright (c) 2013 Samvel Khalatyan. All rights reserved
//
// Use of this source code is governed by a MIT-style license that can be
// found in the LICENSE file.
//
// C++11 defines alternative operator representation:
//      http://en.cppreference.com/w/cpp/language/operator_alternative
//
// This is very useful if some of the characters are not available in the
// 7-bit chars, e.g. [0..127]. Some of these include:
//
//  logical
//      and     &&
//      or      ||
//      not     !
//      not_eq  !=
//
//  bitwise
//      bitand  &
//      and_eq  &=
//
//      bitor   |
//      or_eq   |=
//
//      xor     ^
//      xor_eq  ^=
//
//      compl   ~
//
// it is even possible to substitute paranthesis and some other chars:
//
//  {       <%      ??<
//  }       %>      ??>
//  [       <:      ??(
//  ]       :>      ??)
//  #       %:      ??=
//  \               ??/
//  ^               ??'
//  |               ??!
//  ~               ??-
//
// Probably the most insteresting are logical alternatives, e.g. Python-like
// 'and', 'or', and 'not'.

%:include <iostream>

using namespace std;

int main(int argc, char *argv<::>)
{
    if (argc > 0 and argv[1] != 0)
    {
        for(decltype(argc) i {0}; argv[i]; ++i)
        <%
            cout << argv[i] << endl;
        %>
    }
}
