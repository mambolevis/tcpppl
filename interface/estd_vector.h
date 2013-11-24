// Created by Samvel Khalatyan on Nov 24, 2013
// Copyright (c) 2013 Samvel Khalatyan. All rights reserved
//
// Use of this source code is governed by a MIT-style license that can be
// found in the LICENSE file.

#ifndef EXTENDED_STD_VECTOR
#define EXTENDED_STD_VECTOR

#include <algorithm>
#include <ostream>
#include <vector>

namespace estd
{
    // print vector
    //
    template<typename T>
        std::ostream &operator <<(std::ostream &os, const std::vector<T> &v)
        {
            const auto *back = &v.back();
            for(const auto &x:v)
            {
                os << x;

                if (&x != back)
                    os << ' ';
            }

            return os;
        }

    // sort vector
    //
    template<typename T>
        void sort(std::vector<T> &v)
        {
            std::sort(v.begin(), v.end());
        }
}

#endif
