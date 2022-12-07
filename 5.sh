#!/bin/bash

read -p "Enter your marks: " mark

echo -n "you have got "
if [ $mark -gt 100 -o $mark -lt 0 ]; then
    echo "INVALID input"
     exit 0
fi
if [ $mark -ge 80 -a $mark -le 100 ]; then
 echo "A+"
elif [ $mark -ge 60 -a $mark -le 79 ]; then
   echo "A"
elif [ $mark -ge 50 -a $mark -le 59 ]; then
   echo "B"
else echo "Fail"
fi
