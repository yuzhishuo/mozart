#!/bin/sh

exec_file="${PWD}/build/problem_b"
in_file="${PWD}/test/in.t"
out_file="${PWD}/test/out.t"

if [ -n "$exec_file" ]; then
    $exec_file $in_file $out_file
    more $out_file
else
    echo "Test case should execution after CMake build"
    exit -1
fi