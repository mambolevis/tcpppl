// Created by Samvel Khalatyan on Dec 25, 2013
// Copyright (c) 2013 Samvel Khalatyan. All rights reserved
//
// Use of this source code is governed by a MIT-style license that can be
// found in the LICENSE file.
//
// (*2.5)   Consider:
//
//              struct Tnode {
//                  string word;
//                  int count;
//                  Tnode* left;
//                  Tnode* right;
//              };
//
//          Write a function for entering new words into a tree of Tnodes.
//          Write a function to write out a tree of Tnodes.
//          Write a function to write out a tree of Tnodes with the words
//          in alphabetical order.
//          Modify Tnode so that it stores (only) a pointer to an arbitrarily
//          long word stored as an array of characters on free store using new.
//          Modify the functions to use the new definition of Tnode.

#include <iostream>

#include "interface/13.8.h"
#include "interface/tools.h"

using namespace std;

int main(int argc, char *argv[])
    // fill tree with either arguments or default list of words.
    // print the tree, swap several words, custom sort tree and print.
{
    ex_13_8::Tree tree;
    for(const auto &w:tools::arguments(argc, argv))
        tree.add(w);

    if (tree.empty())
    {
        cout << "no words are given; using default array" << endl;

        // use default list of words
        for(const auto &w:{"Write", "a", "function", "for", "entering", "new",
                           "words", "into", "a", "tree", "of", "Tnodes"})
            tree.add(w);
    }

    cout << tree << endl;

    cout << "-- swap(1, 3)" << endl;
    tree.swap(1, 3);
    cout << tree << endl;

    cout << "-- swap(2, 12)" << endl;
    tree.swap(2, 12);
    cout << tree << endl;

    cout << "-- word sort" << endl;
    tree.sort(ex_13_8::WordCompare{});
    cout << tree << endl;

    cout << "-- count sort" << endl;
    tree.sort(ex_13_8::CountCompare{});
    cout << tree << endl;
}
