#!/bin/bash

root_dir=$(pwd)

ex_array=("ex00" "ex01" "ex02" "ex03")

cleanup() {
    i=0;
    while [ "$i" -le 3 ]; do
        cd "$root_dir/${ex_array[i]}"
        make fclean
        ./test
        i=$(expr $i + 1)
    done
}

execute() {
    i=0;
    while [ "$i" -le 3 ]; do
        cd "$root_dir/${ex_array[i]}"
        make re
        ./test
        if [ $? != 0 ]; then
            cleanup
            exit 1
        fi
        i=$(expr $i + 1)
    done
}

execute
echo "All tests are passed!"