// Created by Samvel Khalatyan on Nov 26, 2013
// Copyright (c) 2013 Samvel Khalatyan. All rights reserved
//
// Use of this source code is governed by a MIT-style license that can be
// found in the LICENSE file.

#ifndef TIMER
#define TIMER

#include <chrono>
//#include <iosfwd>
#include <memory>

namespace tools
{
    class Timer
    {
        public:
            // automatically start timer
            //
            Timer():
                _time_point {std::chrono::system_clock::now()}
            {}

            // stop timer
            //
            void stop();

            // number of seconds passed
            //
            operator unsigned long() const;

        private:
            std::chrono::system_clock::time_point _time_point;
            std::unique_ptr<std::chrono::milliseconds> _duration;
    };

    // standard printing
    //
    std::ostream &operator <<(std::ostream &, const Timer &);
}

#endif
