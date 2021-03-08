#/bin/bash
echo "\t\t1.cpp => a.out"
g++ 1.cpp -static && du -sb a.out && ./a.out
echo "\t\t1.c => a.out"
gcc 1.c -static && du -sb a.out && ./a.out
echo "\t\t1.s => a.out"
gcc -m32 -no-pie 1.s && du -sb a.out && ./a.out
