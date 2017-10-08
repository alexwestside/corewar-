#!/usr/bin/env bash


FILES=/nfs/2016/o/orizhiy/norm_corewar_new/test_bot/*
PATH_TO_ASM=/nfs/2016/o/orizhiy/norm_corewar_new/
cor=".cor"
s=".s"

make
for f in $FILES
do
#    echo $(basename ${f%.*})${s}
    echo "Processing $f file..."
    echo "ASMM:          "
    ./asm ${f}
    echo "ASM_ORIGIN:    "
    ./exe/./asm ${f}
    diff ./test_bot/$(basename ${f%.*})${cor} $(basename ${f%.*})${cor}
     echo "____________________________________________________________________________________________________________________________"
done
for f in $FILES
do
    echo "Deleting $f.cor files..."
    rm -f ./test_bot/$(basename ${f%.*})${cor}
    rm -f $(basename ${f%.*})${cor}
done
make fclean