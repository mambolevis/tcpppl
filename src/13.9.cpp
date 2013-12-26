// Created by Samvel Khalatyan on Dec 26, 2013
// Copyright (c) 2013 Samvel Khalatyan. All rights reserved
//
// Use of this source code is governed by a MIT-style license that can be
// found in the LICENSE file.
//
// (*2.5)   Write a function to invert a two-dimensional array. Hint: §7.4.2.

#include <iomanip>
#include <iostream>

using namespace std;

template<size_t N, size_t M>
ostream &operator <<(ostream &os, int (&arr)[N][M])
{
    for(size_t n {0}; N > n; ++n)
    {
        for (size_t m {0}; M > m; ++m)
            os << setw(3) << arr[n][m] << ' ';
        os << endl;
    }

    return os;
}

template<size_t N>
void invert(int (&arr)[N][N])
    // it only makes sence to invert square matrices otherwise type mismatch
    // of c-style array will take place:
    //
    //      a[N][M] != a[M][N]
    //
    // unless the array is created with operator new().
{
    cout << "-- invert array of size " << N << 'x' << N << endl;

    for(size_t r {0}; N > r; ++r)
        for(size_t c {r + 1}; N > c; ++c)
        {
            int tmp = arr[r][c];
            arr[r][c] = arr[c][r];
            arr[c][r] = tmp;
        }
}

int main(int, char *[])
    // create array, fill with numbers, print, invert and print again.
{
    const size_t N {20};
    int arr[N][N];
    for(size_t r {0}; N > r; ++r)
        for(size_t c {0}; N > c; ++c)
            arr[r][c] = r * N + c + 1;

    cout << arr << endl;

    invert(arr);

    cout << arr << endl;
}
