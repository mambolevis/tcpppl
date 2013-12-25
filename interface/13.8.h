// Created by Samvel Khalatyan on Dec 25, 2013
// Copyright (c) 2013 Samvel Khalatyan. All rights reserved
//
// Use of this source code is governed by a MIT-style license that can be
// found in the LICENSE file.

#ifndef EXERCISE_13_8
#define EXERCISE_13_8

#include <iosfwd>
#include <memory>
#include <string>

namespace ex_13_8
{
    // always work with smart pointers
    using node_pointer = std::shared_ptr<struct Tnode>;
    using str_pointer = std::shared_ptr<char>;

    struct Tnode
        // Node keeps track of neighbours, e.g. left and right nodes,
        // and data. Ideally, data can be put into a separate container.
        // In this case node would keep only a pointer to that container.
    {
        str_pointer word;
        int count;

        node_pointer left;
        node_pointer right;
    };

    // nice print
    std::ostream &operator <<(std::ostream &, const Tnode &);

    // swap two nodes
    void swap(Tnode &, Tnode &) noexcept;

    struct Compare
        // interface for a functor to compare two nodes. It should return:
        //
        //  -1  if left < right
        //   1  if left > right
        //   0  otherwise
    {
        virtual int operator()(const Tnode &left,
                               const Tnode &right) const = 0;
    };

    struct WordCompare : public Compare
    {
        virtual int operator()(const Tnode &left,
                               const Tnode &right) const;
    };

    struct CountCompare : public Compare
    {
        virtual int operator()(const Tnode &left,
                               const Tnode &right) const;
    };

    class Iterator
        // iterator can be only created by Tree
    {
        public:
            inline Iterator &operator ++()
            { 
                if (_node)
                    _node = _node->right;
                else
                    _node.reset();

                return *this;
            }

            inline Iterator &operator --()
            {
                if (_node)
                    _node = _node->left;
                else
                    _node.reset();

                return *this;
            }

            inline Tnode &operator *() noexcept { return *_node; }

            inline node_pointer operator ->() noexcept
            { 
                return _node;
            }

            inline bool operator ==(const Iterator &iter)
            {
                return _node == iter._node;
            }

            inline bool operator !=(const Iterator &iter)
            {
                return _node != iter._node;
            }

        private:
            Iterator(node_pointer node): _node(node) {}

            friend class Tree;

            node_pointer _node;
    };

    class Tree
    {
        public:
            // add a new word: the value will be copied
            void add(const std::string &);

            // print a tree
            void print(std::ostream &) const;

            // user defined sort
            void sort(const Compare &compare);

            // swap two elements with counts
            void swap(const decltype(Tnode::count) &,
                      const decltype(Tnode::count) &);

            // check if tree is empty
            inline bool empty() const noexcept { return not _size; }

            inline Iterator begin() const { return Iterator{_front}; }
            inline Iterator end() const { return Iterator{nullptr}; }

            inline size_t size() const noexcept { return _size; }

        private:
            node_pointer _front {nullptr};
            node_pointer _back {nullptr};

            size_t _size {0};
    };

    // Tree nice print
    std::ostream &operator <<(std::ostream &, const Tree &);
}

#endif
