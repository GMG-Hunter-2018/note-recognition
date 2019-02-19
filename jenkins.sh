#!/bin/bash

set -e

echo "End Clone"

mkdir build-clang
cd build-clang
cmake ..\
    -DCMAKE_BUILD_TYPE=Debug\
    -DCMAKE_C_COMPILER=clang-8\
    -DCMAKE_CXX_COMPILER=clang++-8\
    -DCMAKE_{SHARED,EXE}_LINKER_FLAGS=-fuse-ld=lld\
    -DCMAKE_{C,CXX}_COMPILER_LAUNCHER=ccache\
    -GNinja
echo "End CMake"
ninja -j8
echo "End Build"
# bash tools/lint-clang.bash
echo "End Lint"
cd ..
