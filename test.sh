#!/usr/bin/env bash


FILES=/nfs/2016/m/maksenov/CLionProjects/my_new_corewar/M_N_COR/test_bot/*
PATH_TO_ASM=/nfs/2016/m/maksenov/CLionProjects/my_new_corewar/M_N_COR/
cor=".cor"
s=".s"
do=false

make
for f in $FILES
do
#    echo $(basename ${f%.*})${s}
    echo "Processing $f file..."
    echo "ASMM:          "
    if ./asm ${f} | grep -q "Writing"; then
        ${do}=true
    fi
    ./asm ${f}
#    ./asm ${f}
    echo "ASM_ORIGIN:    "
#    ./exe/./asm ${f}
    if ./exe/./asm ${f} | grep -q "Writing"; then
        ${do}=true
#        echo "matched"
    fi
    ./exe/./asm ${f}
    if ${do} = true; then
        diff ./test_bot/$(basename ${f%.*})${cor} $(basename ${f%.*})${cor}
    fi
    echo "____________________________________________________________________________________________________________________________"
done
for f in $FILES
do
    echo "Deleting $f.cor files..."
    rm -f ./test_bot/$(basename ${f%.*})${cor}
    rm -f $(basename ${f%.*})${cor}
done
make fclean