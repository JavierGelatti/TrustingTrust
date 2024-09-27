#!/bin/bash

set -euo pipefail

clear
./compiler programa.c -o programa

./programa > salida.txt
