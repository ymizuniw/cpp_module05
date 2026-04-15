#!/bin/bash

root_dir=$(pwd)

ex_array=("ex00" "ex01" "ex02" "ex03")

cleanup() {
    i=0;
    while [ "$i" -le 3 ]; do
        cd "$root_dir/${ex_array[i]}"
        make fclean
        rm -f *_shrubbery
        i=$(expr $i + 1)
    done
}

cleanup