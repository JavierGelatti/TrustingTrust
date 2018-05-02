#!/bin/bash

set -e

clear
./compiler programa.c -o programa

printf "\n--- SALIDA ---\n"
./programa

printf "\n---- DIFF ----\n"
./programa > salida
colordiff -s programa.c salida
printf "\n"

rm salida
rm programa
