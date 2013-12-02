// Created by Samvel Khalatyan on Nov 28, 2013
// Copyright (c) 2013 Samvel Khalatyan. All rights reserved
//
// Use of this source code is governed by a MIT-style license that can be
// found in the LICENSE file.

#ifndef EXERCISE_7_6
#define EXERCISE_7_6

#include <cxxabi.h> // for demangle

#include <string>

namespace ex_7_6
{
    template<typename T>
        struct Info{};

    template<typename T>
        std::string type_name(const Info<T> &type)
        {
            int status;
            char *name {abi::__cxa_demangle(typeid(T).name(),
                                                      NULL,
                                                      NULL,
                                                      &status)};
            std::string name_ {name};
            std::free(name);

            return name_;
        }

    namespace print
    {
        namespace size
        {
            template<typename T>
                std::ostream &operator<<(std::ostream &os, const Info<T> &type)
                    // automatically print name and size of the type
                {
                    return os << type_name(type) << ": " << sizeof(T) << " B";
                }
        }
    }
}

#endif
