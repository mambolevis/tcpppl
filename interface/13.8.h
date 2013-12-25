// Created by Samvel Khalatyan on Dec 25, 2013
// Copyright (c) 2013 Samvel Khalatyan. All rights reserved
//
// Use of this source code is governed by a MIT-style license that can be
// found in the LICENSE file.

#ifndef EXERCISE_13_8
#define EXERCISE_13_8

#include <iosfwd>
#include <string>

namespace ex_13_8
{
    struct Tnode
    {
        std::string word;
        int count;

        Tnode *left;
        Tnode *right;
    };

    void swap(Tnode *, Tnode *) noexcept;

    struct Compare
    {
        virtual int operator()(const Tnode *left,
                               const Tnode *right) const = 0;
    };

    struct WordCompare
    {
        virtual int operator()(const Tnode *left,
                               const Tnode *right) const;
    };

    struct CountCompare
    {
        virtual int operator()(const Tnode *left,
                               const Tnode *right) const;
    };

    class Tree
    {
        public:
            void add(const std::string &);
            void print(std::ostream &) const;
            void sort(const Compare &compare);

        private:
            Tnode *_front;
    };

    std::ostream &operator <<(std::ostream &, const Tree &);
}

#endif
