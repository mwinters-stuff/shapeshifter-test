#!/bin/bash

mkdir build
cmake --no-warn-unused-cli \
  -DCMAKE_EXPORT_COMPILE_COMMANDS:BOOL=TRUE \
  -DCMAKE_BUILD_TYPE:STRING=Debug \
  -H$(pwd) \
  -B$(pwd)/build \
  -G "Unix Makefiles"
cmake --build build --config Debug --target shapeshifter-test -j 18 --
cmake --build build --config Debug --target shapeshifter-test-tests -j 18 --