#!/bin/bash

set -e
clear

./compiler compiler.c -o compiler
./compiler login.c -o login

printf "\n--- EJECUCIÓN ---\n"
./login javier 1234
./login hacker 1111

rm login

printf "\n"
