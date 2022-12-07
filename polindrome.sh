#!/bin/bash

read -p "Enter total number of terms for the series : " n;

first=22;

for((i=1;i<=n;i++))
do
   echo "$first ";
   first=$(($first+20));
done
