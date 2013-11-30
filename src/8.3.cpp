// Created by Samvel Khalatyan on Nov 30, 2013
// Copyright (c) 2013 Samvel Khalatyan. All rights reserved
//
// Use of this source code is governed by a MIT-style license that can be
// found in the LICENSE file.
//
// (*1) Use an alias (using) to define the types:
//          - unsigned char
//          - const unsigned char
//          - pointer to integer
//          - pointer to pointer to char
//          - pointer to array of char
//          - array of 7 pointers to int
//          - pointer to an array of 7 pointers to int
//          - array of 8 arrays of 7 pointers to int

#include <iostream>

#include "interface/8.3.h"

using std::cout;
using std::endl;

int main(int, char *[])
{
	cout << "unsigned char: " << ex_8_3::rc << endl;
	cout << "const unsigned char: " << ex_8_3::crc << endl;
	cout << "pointer to integer: " << ex_8_3::rpi << ' ' <<
        *ex_8_3::rpi << endl;

	cout << "pointer to pointer to char: " << ex_8_3::rppc << ' ' <<
        *ex_8_3::rppc << ' ' << **ex_8_3::rppc << endl;

	cout << "pointer to array of char: " << ex_8_3::rpc << ' ' <<
        *ex_8_3::rpc << endl;

	cout << "array of 7 pointers to int: " <<
        ex_8_3::rapi << ' ' << *ex_8_3::rapi << endl;

	cout << "pointer to an array of 7 pointers to int: " <<
        ex_8_3::rpapi << ' ' << 
        *ex_8_3::rpapi << ' ' <<
        *ex_8_3::rpapi[0] << endl;

	cout << "array of 8 arrays of 7 pointers to int: " << 
        ex_8_3::raapi << endl;
}

/*
unsigned char: C
const unsigned char: C
pointer to integer: 0x102eb8234 10
pointer to pointer to char: 0x102eb8248 H H
pointer to array of char: abc a
array of 7 pointers to int: 0x102eb8270 0x0
pointer to an array of 7 pointers to int: 0x102eb8270 0x102eb8270 0x0
array of 8 arrays of 7 pointers to int: 0x102eb82b0
*/
