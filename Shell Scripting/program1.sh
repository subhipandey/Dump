#!/bin/sh

echo "Enter value of a:";
read a
echo "Enter value of b:";
read b
sum=`expr $a + $b`;
sum1=`expr $a - $b`;
echo "Addition is $sum";
echo "Substraction is $sum1";