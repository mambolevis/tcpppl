// Created by Samvel Khalatyan on Nov 30, 2013
// Copyright (c) 2013 Samvel Khalatyan. All rights reserved
//
// Use of this source code is governed by a MIT-style license that can be
// found in the LICENSE file.

#include "interface/8.1.h"

char m[] = "hello";
char *ex_8_1::p {m};

int ex_8_1::a[10] {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
ex_8_1::ints &ex_8_1::ra {a};

const char *astrings[] {"hello", "from", "C++"};
const char **ex_8_1::ps {astrings};

char **ex_8_1::ppc {&p};

const int ex_8_1::num {10};

const int *ex_8_1::pn {&num};

int *const ex_8_1::cpn {a};
