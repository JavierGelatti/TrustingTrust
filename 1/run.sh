#!/bin/bash

set -euo pipefail

clear

./compiler compiler.c -o compiler
./compiler programa.c -o programa

printf "\n--- EJECUCIÓN ---\n"
./programa
rm programa

printf "\n"
