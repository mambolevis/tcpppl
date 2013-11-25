// Created by Samvel Khalatyan on Nov 25, 2013
// Copyright (c) 2013 Samvel Khalatyan. All rights reserved
//
// Use of this source code is governed by a MIT-style license that can be
// found in the LICENSE file.

#ifndef TOOLS
#define TOOLS

#include <numeric>

namespace tools
{
    template<typename T>
        T sum(const T *from, const T &number_of_elements, T init)
            // calculate a sum of consequent elements
        {
            return std::accumulate(from, from + number_of_elements, init);
        }
}

#endif
