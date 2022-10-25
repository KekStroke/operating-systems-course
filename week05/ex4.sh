#!/bin/bash
rm ex4.txt

gcc ex4.c -pthread -o ex4


echo 1 thread >> ex4.txt
{ time ./ex4 10000000 1 >> ex4.txt ; } 2>> ex4.txt
echo >> ex4.txt ; echo >> ex4.txt ; 
echo 2 threads >> ex4.txt
{ time ./ex4 10000000 2 >> ex4.txt ; } 2>> ex4.txt
echo >> ex4.txt ; echo >> ex4.txt ; 
echo 4 threads >> ex4.txt
{ time ./ex4 10000000 4 >> ex4.txt ; } 2>> ex4.txt
echo >> ex4.txt ; echo >> ex4.txt ; 
echo 10 threads >> ex4.txt
{ time ./ex4 10000000 10 >> ex4.txt ; } 2>> ex4.txt
echo >> ex4.txt ; echo >> ex4.txt ; 
echo 100 threads >> ex4.txt
{ time ./ex4 10000000 100 >> ex4.txt ; } 2>> ex4.txt

rm ex4
# Write the script for compiling and running your program as specified in the task description.
