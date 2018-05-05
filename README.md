TivaC TM4C123GH6PM Linux
==================
## Purpose
This is an educational project to get up and running with the TivaC on Linux. This is part of the thesis project of:  
- Dina Gamal
- Mark Maurice
- Mohamed Gamal
- Muhammad Azzazy
- Omar El-Kholy

## Resources
- Thanks to [Chris Miller](http://chrisrm.com/howto-develop-on-the-ti-tiva-launchpad-using-linux/), and all the people he mentioned, for helping preparing the enviornment
- A prefect course is tought by Dr.Valvano and Dr.Yerraballi on [edX](https://www.edx.org/course/embedded-systems-shape-the-world-microcontroller-inputoutput)
- The workshop workbook included from [TI](http://processors.wiki.ti.com/index.php/Getting_Started_with_the_TIVA%E2%84%A2_C_Series_TM4C123G_LaunchPad)
- The datasheet included from [TI](www.ti.com/lit/ds/symlink/tm4c123gh6pm.pdf)

## Specs
	Ubuntu 18.04 (x64)
	
## Running
1. Write your code in `src/main.c` 
2. Update the intrrupts in  `src/startup_gcc.c`
2. Go the directory where you unzipped and execute one of the following.  
	**To run normal file:**
	
		sudo ./run.sh
		
	**To run UART file and open the serial terminal:**
	
		sudo ./UART_run.sh
