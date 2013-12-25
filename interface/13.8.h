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
    struct Tnode;
    using node_pointer = std::shared_ptr<Tnode>;

    struct Tnode
    {
        std::string word;
        int count;

        node_pointer left;
        node_pointer right;
    };

    std::ostream &operator <<(std::ostream &, const Tnode &);

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
            class Iterator
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

            void add(const std::string &);
            void print(std::ostream &) const;
            void sort(const Compare &compare);

            inline bool empty() const noexcept { return not _front.get(); }

            Iterator begin() const { return Iterator{_front}; }
            Iterator end() const { return Iterator{nullptr}; }

        private:
            node_pointer _front {nullptr};
            node_pointer _back {nullptr};
    };

    std::ostream &operator <<(std::ostream &, const Tree &);
}

#endif
