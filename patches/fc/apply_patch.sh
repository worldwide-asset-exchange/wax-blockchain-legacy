#!/usr/bin/env bash
TARGET=../../libraries/fc/CMakeLists.txt

cp $TARGET ${TARGET}.bak_$(date +%s)
patch $TARGET < ./CMakeLists.txt.patch

echo Done.
