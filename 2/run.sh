#!/bin/bash

set -e
clear

./compiler compiler.c -o compiler
./compiler login.c -o login

printf "\n--- EJECUCIÓN ---\n"
./login javier 1342

printf "\n"

./login javier 1111
./login diego 1111
./login flor 1111
./login franco 1111

rm login

printf "\n"
