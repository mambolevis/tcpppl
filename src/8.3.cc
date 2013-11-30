// Created by Samvel Khalatyan on Nov 30, 2013
// Copyright (c) 2013 Samvel Khalatyan. All rights reserved
//
// Use of this source code is governed by a MIT-style license that can be
// found in the LICENSE file.

#include "interface/8.3.h"

unsigned char uc {'C'};

unsigned char &ex_8_3::rc {uc};

const unsigned char &ex_8_3::crc {uc};

int i {10};
int *pi {&i};

int *&ex_8_3::rpi {pi};

char c {'H'};
char *pc {&c};
char **ppc {&pc};
char **&ex_8_3::rppc {ppc};

char ac[] {'a', 'b', 'c'};
char *pac {ac};
char *&ex_8_3::rpc {pac};

ex_8_3::a7pint api {};
ex_8_3::a7pint &ex_8_3::rapi {api};

ex_8_3::a7pint *papi {&api};
ex_8_3::a7pint *&ex_8_3::rpapi {papi};

ex_8_3::a8a7pint aapi {};
ex_8_3::a8a7pint &ex_8_3::raapi {aapi};
