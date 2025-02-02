#!/bin/sh
set -e

set_env() {
    export CC=/usr/bin/clang-18
    export CXX=/usr/bin/clang++-18
}

build() {
    rm -rf output build
    cmake -S . -B build
    cmake --build build -j 8
}

set_env
build
