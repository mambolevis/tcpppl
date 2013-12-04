// Created by Samvel Khalatyan on Dec 3, 2013
// Copyright (c) 2013 Samvel Khalatyan. All rights reserved
//
// Use of this source code is governed by a MIT-style license that can be
// found in the LICENSE file.
//
// THIS IS VERY SICK CODE !!! DO NOT EVER DO ANYTHING LIKE THIS !!!
// IT ONLY DEMONSTRATES STATEMENTS AND THEIR CLASSIFICATION
//
// statement:
//  
//      declaration
//      [expression];
//      { [statement-list] }
//      try { [statement-list] } handler-list
//
//  where:
//      declaration ends with semicolumn
//
//      statement-list:
//          statement [statement-list]
//
//      handler-list:
//          handler [handler-list]
//
//      handler:
//          catch( exception-declaration ) { [statement-list] }
//
//  -----------
//  selection-statement:
//      
//      if ( condition ) statement
//      if ( condition ) statement else statement
//      switch ( condition ) statement
//
//  where:
//      condition:
//          expression
//          type-specifier declarator = expression
//          type-specifier declarator { expression }
//
//      swtich would have one of the following statement forms:
//          case constant-expression: statement
//          default: statement
//
//  -----------
//  iteration-statement:
//
//      while ( condition ) statement
//      do statement while ( expression );
//      for ( for-init-statement [condition]; [expression] ) statement
//      for ( for-init-declaration : expression ) statement
//
//  -----------
//  special type statements:
//      break;
//      continue;
//      return [expression];
//      goto identifier;
//      identifier : statement
//
//  -----------
//  notes:
//      - assignments and function calls are expressions:
//              a = 5
//              f(3)     
//      - a for-init-statement must be either:
//          + a declaration
//          + an expression-statement
//        and both end with a semicolon:
//              int a;
//              a = 4;

#include <iostream>
#include <stdexcept>

using namespace std;

void statement();
void special_type_statement();
void selection_statement();
void iteration_statement();

int main(int, char *[])
{
    statement();
    special_type_statement();
    selection_statement();
    iteration_statement();

    for(int i {0}; 10 > i; ++i)
        try
        {
            if (!(i % 3))
                throw logic_error{"skip"};
            else
                cout << i << endl;
        }
        catch(const exception &e)
        {
            cerr << e.what() << endl;
        }
}

void statement()
{
    // declaration
    int i; 

    // optional expression
    ;

    // expression
    i = 4;

    // optional statement list
    {
    }

    // statement list
    {
        int b;
        b = 3;
        b += 6;
    }

    // optional statement-list in the try block
    try
    {
    }
    catch(const std::runtime_error &) // handler with statement list
    {
        int c;
    }
    catch(const std::exception &) // handler with optional statement list
    {
    }

    // try block with statement list
    try
    {
        int a;
    }
    catch(const std::exception &)
    {
    }
}

void special_type_statement()
{
    // break can only be used within loops
    for(;;)
        break;

    // continue can also be used only within loops
    for(bool flag {true}; flag; flag = !flag)
        continue;

    // goto with identifier
    goto finish;

    // identifier with return and optional statement
finish: return;
}

void selection_statement()
{
    // if ( condition ) statement
    if (true);

    if (bool b = true)
        try {} catch(const std::exception &) {}

    if (int i {0})
        int c;

    // if ( condition ) statement else statement
    if (true); else;

    if (bool b {true})
        try {} catch (const std::exception &) {}
    else
        try {} catch (const std::runtime_error &) {}

    // switch ( condition ) statement
    switch ( true );

    switch ( bool test = static_cast<bool>(nullptr))
        try {} catch (const std::exception &) {}

    switch (bool test {true} )
        try
        {
            if (test)
                throw std::logic_error("no way");
        }
        catch(const std::exception &)
        {
            // here we go
        }
}

void iteration_statement()
{
    // while ( condition ) statement
    // while ( true ) ; // demonstration only
    while ( bool next {1})
        try { break; } catch (const std::exception &) {}

    // do statement while (expression);
    int j {1};
    do int i; while (j--);

    int i {0};
    do ; while(--i + 4);

    do
        try { break; }
        catch(const std::exception &) {}
    while(true);

    // for (for-init-statement [condition]; [expression]) statement
    for(;;) break;

    // for (for-init-declaration: expression) statement
    for(auto &x:{1, 2});

    for(const auto &x:{1}) int i;

    for(auto &x:{1, 2, 3})
        try
        {
            if (2 > x)
                throw std::runtime_error("");

            cout << "in try" << endl;
            break;
        }
        catch(const std::exception &)
        {
            cout << "in catch" << endl;
            continue;
        }
}
