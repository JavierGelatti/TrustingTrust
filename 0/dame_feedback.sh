#!/bin/bash

set -e

clear
./compiler programa.c -o programa

printf "\n--- SALIDA ---\n"
./programa

printf "\n---- DIFF ----\n"
./programa > salida
colordiff -u -sd programa.c salida | diff-highlight
printf "\n"

rm salida
rm programa
