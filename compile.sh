#!/bin/sh
echo "Compilando.."
cd build
cmake ..
make
./testShader
exit
