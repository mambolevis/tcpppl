tcpppl
======

TC++PL (The C++ Programming Language 4th edition) exercises


Project uses Google Test framework:

    https://code.google.com/p/googletest/

Make sure you have it installed and compiled on the system as a dynamic
library. The instructions for OSX are below.

    1. Create Environment variable that points to the source code and
       put it into .XXXrc file:

        export GTEST_DIR=/path/to/google/test/source/dir

    2. Compile the Google Test code:

        clang++ -isystem ${GTEST_DIR}/include -I${GTEST_DIR} -pthread \
                -DGTEST_CREATE_SHARED_LIBRARY=1 \
                -c ${GTEST_DIR}/src/gtest-all.cc

    3. Create a shared library for Google Test:

        clang++ -shared -W1,-soname,libgtest.so.1.7 -o libgtest.so.1.7 \
                gtest-all.o

    4. Make sure path to library is searchable by the system. Setup
       appropriately DYLD_LIBRARY_PATH (or LD_LIBRARY_PATH for *nix systems)
       in the .XXXrc file:

        export DYLD_LIBRARY_PATH=$GTEST_DIR:$DYLD_LIBRARY_PATH

    5. Go to tcppl project and compile it with Makefile:

        for _opt in lib prog test; do make $_opt -j8; done


FOLDER STRUCTURE
================

Each exercise has implemented as a unique executable src/<EXERCISE>.cpp, e.g.
for the exercise 7.6 the executable is src/7.6.cpp. The source file contains
the exercise description.

Some parts of the exercises are either reusable, can be even referenced from
another exercises, or just a good idea to keep OO concepts separate. In such
cases accompaniying interface can be found in interface/<EXERCISE>.h,
while implementation is available in src/<EXERCISE>.cc.
    
In the above example of exercise 7.6 additional two files exist:

    interface/7.6.h 
    src/7.6.cc

test folder contains short programs with tests of some code.
