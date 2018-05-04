#!/bin/bash
export PATH=$PATH:$HOME/Documents/Courses/ARM/workplace/gcc-arm-none-eabi-7-2017-q4-major/bin
cd ~/Documents/Courses/ARM/workplace/
sudo rm -r build/
make
cd ~/Documents/Courses/ARM/workplace/lm4flash/
sudo ./lm4flash ~/Documents/Courses/ARM/workplace/build/main.bin
