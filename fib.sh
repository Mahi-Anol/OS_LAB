#!/bin/bash
read -p "Enter first term of range : " first
read -p "Enter Second term of range : " second
f=0;
s=1;
if [ $second -lt $first ]; then
   echo "Invalid range "
   exit 1
fi
flag=1;
for((i=1;i<=second;i++))
do
  if [ $i -lt $first ]; then
    temp=$(($f+$s));
    f=$s;
    s=$temp;
  else
   if [ $flag -eq 1 ]; then
      echo -n "$f "
      flag=2;
   elif [ $flag -eq 2 ];then
      echo -n "$s "
        flag=3
    else
       temp=$(($f+$s));
       f=$s;
       s=$temp;
      echo -n "$temp ";
     fi
  fi
done
echo
