#!/bin/sh
echo "Compilando.."
cd build
cmake ..
make
./shader-opengl
exit
