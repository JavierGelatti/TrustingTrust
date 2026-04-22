#!/bin/bash

set -euo pipefail

clear
./compiler programa.c -o programa

# Podría verse el diff, pero en general resulta más claro simplemente ver todo el código generado:
./programa

# Para ejecutar esto automáticamente:
#watchexec -c -e c ./run.sh

# Para mostrar el diff:
#./programa > salida.txt
#diff --color programa.c salida.txt

