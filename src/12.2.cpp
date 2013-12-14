// Created by Samvel Khalatyan on Dec 13, 2013
// Copyright (c) 2013 Samvel Khalatyan. All rights reserved
//
// Use of this source code is governed by a MIT-style license that can be
// found in the LICENSE file.
//
// (*2) Allocate so much memory using new that bad_alloc is thrown.
//      Report how much memory was allocated and how much time it took.
//      Do this twice: once not writing to the allocated memory and once
//      writing to each element.

#include <functional>
#include <iomanip>
#include <iostream>
#include <memory>
#include <stdexcept>
#include <vector>

using namespace std;

int main(int argc, char *argv[])
    // it's very difficult to run out of memory on OS X 10.9.
    // Therefore the loop is limited
{
    cout << "sizeof(long double) = " << sizeof(long double) << "B" << endl;
    vector<shared_ptr<long double>> memory;
    long long vector_size {0};

    try
    {
        function<void()> f;
        if (argc > 1)
             f = [&memory]() mutable { 
                 memory.push_back(
                         shared_ptr<long double>{new long double{1.2}});
             };
        else
            f = [&memory]() mutable {
                     memory.push_back(
                             shared_ptr<long double>{new long double});
                 };

        for(size_t i {10000000}; i; --i)
            f();

        vector_size = memory.size();
        memory.clear();
    }
    catch(const std::bad_alloc &e)
    {
        vector_size = memory.size();
        memory.clear();
    }

    long long bytes = vector_size * sizeof(long double);
    cout << "application allocated:" << endl;
    cout << setw(10) << bytes << " B" << endl;
    cout << setw(10) << (bytes /= 1000) << " KB" << endl;
    cout << setw(10) << (bytes /= 1000) << " MB" << endl;
    cout << setw(10) << (bytes /= 1000) << " GB" << endl;
}
