#!/bin/bash
export PATH=$PATH:$HOME/Documents/Courses/ARM/workplace/gcc-arm-none-eabi-5_4-2016q3/bin
cd ~/Documents/Courses/ARM/workplace/tiva-template/
sudo rm -r build/
make
cd ~/Documents/Courses/ARM/workplace/lm4tools/lm4flash/
sudo ./lm4flash ~/Documents/Courses/ARM/workplace/tiva-template/build/main.bin
