#!/bin/bash
pal()
{
	number=$1
	n=$1
	reverse=0
	while [ $n -gt 0 ]
	do
	a=`expr $n % 10 `
	n=`expr $n / 10 `
	reverse=`expr $reverse \* 10 + $a`
	done
	if [ $number -eq $reverse ]
	then
	    echo "Number is palindrome"
	else
	    echo "Number is not palindrome"
	fi
}
flag=1
while [ $flag -eq 1 ]
do
    read -p "Enter a number : " num;
    pal $num
    echo -n "Do you want to try again ?(Y/n) : "
    read a
    if [ "$a" == "Y" ]; then
       flag=1;
    else
      flag=0;
    fi
done
