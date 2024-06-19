#!/bin/bash

# debug
# set -x

# exit on first error
set -e

rm -i main{.s,.ll,_opt.ll,_llvm,_gcc,_clang} || true
ls -l

echo "continue? [y]" 
read ans
if [ "${ans}" == "n" ]; then
    echo "exiting ..."
    exit
fi

echo "build continued ..."

# llvm
clang -S -emit-llvm main.c -o main.ll
opt -O2 main.ll -o main_opt.ll
llc main_opt.ll -o main.s
clang main.s -o main_llvm

# gcc -c main.s -o main.o
# gcc main.o -o main

# clang
# clang main.c -o main_clang
clang main.c -g -o main_clang

# gcc
gcc main.c -o main_gcc



