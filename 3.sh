#!/bin/bash

num=15
dum=3
echo "Number 1 is $num";
echo "Number 2 is $dum";

var=`expr $num + $dum`;
echo "Value of sum is $var";
var=`expr $num - $dum`;
echo "Value of substract is $var"
var=`expr $num \* $dum`;
echo "Value of mul is $var"
var=`expr $num / $dum`;
echo "Value of division is $var"
