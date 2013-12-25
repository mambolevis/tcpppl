// Created by Samvel Khalatyan on Dec 25, 2013
// Copyright (c) 2013 Samvel Khalatyan. All rights reserved
//
// Use of this source code is governed by a MIT-style license that can be
// found in the LICENSE file.

#include <cstring>
#include <iomanip>
#include <ostream>

#include "interface/estd_ios.h"
#include "interface/13.8.h"

using namespace std;

using ex_13_8::Tree;

ostream &ex_13_8::operator <<(ostream &os, const Tnode &node)
{
    estd::Flags flags(os);
    return os << setw(3) << node.count <<
        "  p:" << setw(14) << left << &node << 
        "  l:" << setw(14) << left << node.left.get() <<
        "  r:" << setw(14) << left << node.right.get() << 
        "  '" << node.word << "'";
}

int ex_13_8::WordCompare::operator()(const Tnode *l, const Tnode *r) const
{
    return strcmp(l->word.c_str(), r->word.c_str());
}

int ex_13_8::CountCompare::operator()(const Tnode *l, const Tnode *r) const
{
    return l->count - r->count;
}

void Tree::add(const std::string &word)
{
    node_pointer node{new Tnode{word, 1}};

    if (_back)
    {
        _back->right = node;
        node->left = _back;

        node->count += _back->count;
    }
    else
    {
        _front = node;
    }

    _back = node;
}

void Tree::print(ostream &os) const
{
    for(const auto &node:*this)
        os << node << endl;
}

void Tree::sort(const Compare &compare)
{
}

ostream &ex_13_8::operator <<(ostream &os, const Tree &tree)
{
    tree.print(os);

    return os;
}
