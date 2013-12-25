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
        "  '" << node.word.get() << "'";
}

void ex_13_8::swap(node_pointer l, node_pointer r) noexcept
    // swap is easy b/c of cheap copy
    //
    // note: the logic is very complicated if one attempts to manipulate
    //       links, e.g. pointers to left and right node. It is better to
    //       use a pointer to object in the node then and again manipulate
    //       pointer like it is done with string below
{
    decltype(Tnode::word) word = l->word;
    l->word = r->word;
    r->word = word;

    decltype(Tnode::count) count = l->count;
    l->count = r->count;
    r->count = count;
}

int ex_13_8::WordCompare::operator()(const node_pointer l,
                                     const node_pointer r) const
{
    return strcmp(l->word.get(), r->word.get());
}

int ex_13_8::CountCompare::operator()(const node_pointer l,
                                      const node_pointer r) const
{
    return l->count - r->count;
}

void Tree::add(const std::string &word)
{
    node_pointer node{new Tnode{}};
    node->word.reset(new char[word.size() + 1],
                     std::default_delete<char[]>());
    strcpy(node->word.get(), word.c_str());

    node->count = 1;

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

void Tree::swap(const decltype(Tnode::count) l,
                const decltype(Tnode::count) r)
{
    if (empty() or l == r or l < 1 or l > _back->count or r < 1 or  r > _back->count)
        return;

    node_pointer left;
    node_pointer right;
    for(Iterator iter {begin()}, iend {end()}; iend != iter; ++iter)
    {
        if (l == iter->count)
            left = iter._node;

        if (r == iter->count)
            right = iter._node;

        if (left and right)
            break;
    }


    ex_13_8::swap(left, right);
}

ostream &ex_13_8::operator <<(ostream &os, const Tree &tree)
{
    tree.print(os);

    return os;
}
