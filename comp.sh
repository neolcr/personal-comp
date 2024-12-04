#!/bin/zsh

cmake -S . -B build/
cmake --build build
./build/hydro src/test.hy
