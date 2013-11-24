// Created by Samvel Khalatyan on Nov 24, 2013
// Copyright (c) 2013 Samvel Khalatyan. All rights reserved
//
// Use of this source code is governed by a MIT-style license that can be
// found in the LICENSE file.

#include <iostream>
#include <vector>

#include "interface/5.6.h"

using std::cin;
using std::cout;
using std::endl;
using std::vector;

using ex_5_6::Person;

int main(int argc, char *argv[])
{
    vector<Person> people;
    while(!cin.eof())
    {
        cout << "Enter name and age (separated with space): ";

        Person person;
        cin >> person;

        if (person)
            people.push_back(person);
    }

    cout << endl;
    cout << "you've entered next people" << endl;
    for(auto &person:people)
        cout << person << endl;
}
