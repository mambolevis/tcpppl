// Created by Samvel Khalatyan on Dec 01, 2013
// Copyright (c) 2013 Samvel Khalatyan. All rights reserved
//
// Use of this source code is governed by a MIT-style license that can be
// found in the LICENSE file.
//
// (*2) Read a sequence of words from input. Use Quit as a word that
//      terminates the input. Print the words in the order they were entered.
//      Don’t print a word twice. Modify the program to sort the words before
//      printing them.

#include <algorithm>
#include <iostream>
#include <string>
#include <set>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::set;
using std::string;
using std::vector;

string lower(string str)
    // lower case of the string
{
    for(auto &x:str)
        x = tolower(x);

    return str;
}

std::ostream &operator <<(std::ostream &os, const vector<string> &words)
{
    for(const auto &x:words)
        os << x << endl;

    return os;
}

int main(int, char *[])
{
    // store unique words in the order they are typed in
    vector<string> words;

    {
        // keep track of unique words
        // set uses binary search which is way faster than linear
        // search trough vector
        set<string> unique_words;

        cout << "Input words. Type 'quit' to exit." << endl;
        for(string word; cin >> word; )
            // read words one by one and store unique ones
            // words are case insensitive
        {
            // check if 'quit' command is typed in
            word = lower(word);
            if ("quit" == word)
                break;

            // memorize the word if it was not used yet
            if (unique_words.insert(word).second)
                words.push_back(word);
        }
    }
    cout << endl;

    // print typed in words
    cout << "-- you input words" << endl;
    cout << words << endl;

    // sort and print again
    std::sort(words.begin(), words.end());
    cout << "-- sorted words" << endl;
    cout << words << endl;
}
