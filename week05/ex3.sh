#!/bin/bash
rm ex3.txt

gcc ex3.c -pthread -o ex3


echo 1 thread >> ex3.txt
{ time ./ex3 10000000 1 >> ex3.txt ; } 2>> ex3.txt
echo >> ex3.txt ; echo >> ex3.txt ; 
echo 2 threads >> ex3.txt
{ time ./ex3 10000000 2 >> ex3.txt ; } 2>> ex3.txt
echo >> ex3.txt ; echo >> ex3.txt ; 
echo 4 threads >> ex3.txt
{ time ./ex3 10000000 4 >> ex3.txt ; } 2>> ex3.txt
echo >> ex3.txt ; echo >> ex3.txt ; 
echo 10 threads >> ex3.txt
{ time ./ex3 10000000 10 >> ex3.txt ; } 2>> ex3.txt
echo >> ex3.txt ; echo >> ex3.txt ; 
echo 100 threads >> ex3.txt
{ time ./ex3 10000000 100 >> ex3.txt ; } 2>> ex3.txt

rm ex3

# Write the script for compiling and running your program as specified in the task description.
