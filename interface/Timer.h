// Created by Samvel Khalatyan on Nov 26, 2013
// Copyright (c) 2013 Samvel Khalatyan. All rights reserved
//
// Use of this source code is governed by a MIT-style license that can be
// found in the LICENSE file.

#ifndef TIMER
#define TIMER

#include <chrono>
#include <memory>

#include "interface/estd_chrono.h"

namespace tools
{
    template<typename D=std::chrono::microseconds>
        class Timer
            // measure duration of code block
            //
            // usage:
            //      MicroTimer t;
            //      // ... some code
            //      std::chrono::microseconds us {t.duration()};
        {
            private:
                using system_clock = std::chrono::system_clock;

            public:
                using precision = D;

                // automatically start timer
                //
                Timer():
                    _time_point{system_clock::now()}
                {}

                // Prevent copying
                //
                Timer(const Timer &) = delete;
                Timer &operator =(const Timer &) = delete;

                void stop()
                    // stop timer and keep duration in D units
                {
                    if (!_duration)
                        _duration.reset(new D{duration()});
                }

                D duration() const
                    // calculated elapsed time if timer is still running
                    // otherwise return duration
                {
                    if (!_duration)
                        return std::chrono::duration_cast<D>(
                                system_clock::now() - _time_point);
                    else
                        return *_duration;
                }

            private:
                std::chrono::system_clock::time_point _time_point;
                std::unique_ptr<D> _duration;
        };

    // standard printing
    //
    using estd::operator<<;

    template<typename D>
        std::ostream &operator <<(std::ostream &os, const Timer<D> &t)
            // estd chrono knows how to print different durations
        {
            return os << t.duration();
        }

    // aliases to useful timers
    //
    using MilliTimer = Timer<std::chrono::milliseconds>;
    using MicroTimer = Timer<std::chrono::microseconds>;
    using NanoTimer = Timer<std::chrono::nanoseconds>;
}

#endif
