gcc -o ex2 ex2.c
./ex2 &
timeout 11 vmstat 1
rm ex2