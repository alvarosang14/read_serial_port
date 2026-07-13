#!/bin/bash
cmake -B build/build_win -DCMAKE_TOOLCHAIN_FILE=cmake/toolchain-mingw64.cmake
cmake --build build/build_win

cmake -B build/build_ubu
cmake --build build/build_ubu