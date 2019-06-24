#!/bin/bash

set -e

clear
./compiler programa.c -o programa

./programa > salida

printf "\n---- DIFF ----\n"
colordiff -u programa.c salida | diff-highlight

printf "\n--- SALIDA ---\n"
cat salida

printf "\n"
if diff -q programa.c salida > /dev/null
then
    printf "\u001b[32mEl programa y la salida son iguales\u001b[0m\n"
else
    printf "\u001b[31mEl programa y la salida son distintos\u001b[0m\n"
fi

printf "\n"

rm salida
rm programa
