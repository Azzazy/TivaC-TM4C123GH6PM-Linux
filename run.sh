#!/bin/bash
export PATH=$PATH:$PWD/gcc-arm-none-eabi-7-2017-q4-major/bin
sudo rm -r build/
make
sudo ./lm4flash/lm4flash /build/main.bin
