// Created by Samvel Khalatyan on Nov 24, 2013
// Copyright (c) 2013 Samvel Khalatyan. All rights reserved
//
// Use of this source code is governed by a MIT-style license that can be
// found in the LICENSE file.

#ifndef THREAD_SAFE_PRINT
#define THREAD_SAFE_PRINT

#include <mutex>

#include <iostream>

namespace tools
{
    namespace thread_safe_print {
        template<typename T>
            void nonlocking_print(const T &value)
            {
                std::cout << value << std::endl;
            }

        template<typename T, typename... Tail>
            void nonlocking_print(const T &value, Tail... tail)
            {
                std::cout << value << ' ';
                nonlocking_print(tail...);
            }

        std::mutex cout_mutex;
        template<typename T, typename... Tail>
            void print(const T &value, Tail... tail)
                // thread safe print to cout: acquire lock and start print
            {
                std::unique_lock<std::mutex> lock(cout_mutex);
                nonlocking_print(value, tail...);
            }
    }

    using thread_safe_print::print;
}

#endif
