#!/bin/bash

read -p "Enter total number of terms for the series : " n;
first=22;
sum=0;
for((i=1;i<=n;i++))
do
   if [ $i -eq 1 ];then
   echo -n "$first"
   
   else  echo -n "+$first";
   fi
   sum=$(($sum+$first));
   first=$(($first+20));
done
echo " =  $sum"
echo
echo "so the value of this series is $sum"
echo
