#!/bin/bash

read -p "Enter a number " num

fun()
{
    local x=$1
    if [ $x -eq 0 ]; then
       echo 1
    else
       echo $(($x*$(fun $(($x-1)))))
    fi
}
echo "Value of $num! is $(fun $num)"
