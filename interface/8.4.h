// Created by Samvel Khalatyan on Nov 30, 2013
// Copyright (c) 2013 Samvel Khalatyan. All rights reserved
//
// Use of this source code is governed by a MIT-style license that can be
// found in the LICENSE file.

#ifndef EXERCISE_8_4
#define EXERCISE_8_4

#include <iostream>

namespace ex_8_4
{
    namespace tools
    {
        template<typename T>
            void *cast(T *p)
            {
                return static_cast<void *>(p);
            }

        template<typename T>
            void *cast(const T *p)
            {
                return static_cast<void *>(const_cast<T *>(p));
            }
    }

    template<typename T>
        void run(std::initializer_list<T> &&list)
        {
            using std::cout;
            using std::endl;

            using tools::cast;

            std::default_random_engine e{
                std::chrono::system_clock::now().time_since_epoch().count()};
            std::uniform_int_distribution<int> d{0, list.size() - 1};
            auto index = std::bind(d, e);

            for(int i {0}; 10 > i; ++i)
            {
                int i1 = index();
                int i2 = index();

                const T *p1 = &*list.begin() + i1;
                const T *p2 = &*list.begin() + i2;

                cout << '[' << i1 << "]-[" << i2 << "] == " <<
                    cast(p1) << " - " << cast(p2) <<
                    " = " << std::abs(p1 - p2) << endl;
            }
        }
}

#endif
