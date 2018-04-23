#include <stdbool.h>
#include <stdint.h>

#include "inc/tm4c123gh6pm.h"
#include "inc/hw_types.h"
#include "inc/hw_gpio.h"
#include "inc/hw_memmap.h"
#include "inc/hw_sysctl.h"
#include "driverlib/gpio.h"
#include "driverlib/rom.h"
#include "driverlib/sysctl.h"
#include "driverlib/pin_map.h"
#include "driverlib/can.h"
#include "driverlib/interrupt.h"
#include "driverlib/uart.h"

void UARTIntHandler(void)
{
	uint32_t ui32Status;
	ui32Status = ROM_UARTIntStatus(UART0_BASE, true); //get interrupt status
	ROM_UARTIntClear(UART0_BASE, ui32Status); //clear the asserted interrupts
	while(ROM_UARTCharsAvail(UART0_BASE)) //loop while there are chars
	{
		char c = ROM_UARTCharGetNonBlocking(UART0_BASE);
		//ROM_UARTCharPutNonBlocking(UART0_BASE, c); //echo character
		if (c=='y'){
			ROM_GPIOPinWrite(GPIO_PORTF_BASE, GPIO_PIN_2, GPIO_PIN_2); //turn led on
			ROM_UARTCharPutNonBlocking(UART0_BASE, 'L');		
			ROM_UARTCharPutNonBlocking(UART0_BASE, 'E');	
			ROM_UARTCharPutNonBlocking(UART0_BASE, 'D');	
			ROM_UARTCharPutNonBlocking(UART0_BASE, ' ');	
			ROM_UARTCharPutNonBlocking(UART0_BASE, 'O');	
			ROM_UARTCharPutNonBlocking(UART0_BASE, 'N');
			ROM_UARTCharPutNonBlocking(UART0_BASE, '\n'); 			
		}else if (c=='n'){
			ROM_GPIOPinWrite(GPIO_PORTF_BASE, GPIO_PIN_2, 0); //turn off LEDf	
			ROM_UARTCharPutNonBlocking(UART0_BASE, 'L');		
			ROM_UARTCharPutNonBlocking(UART0_BASE, 'E');	
			ROM_UARTCharPutNonBlocking(UART0_BASE, 'D');	
			ROM_UARTCharPutNonBlocking(UART0_BASE, ' ');	
			ROM_UARTCharPutNonBlocking(UART0_BASE, 'O');	
			ROM_UARTCharPutNonBlocking(UART0_BASE, 'F');	
			ROM_UARTCharPutNonBlocking(UART0_BASE, 'F');
			ROM_UARTCharPutNonBlocking(UART0_BASE, '\n'); 	
		}
		//ROM_SysCtlDelay(ROM_SysCtlClockGet() / (1000 * 3)); //delay ~1 msec
	}
}

int main(void) {
	ROM_SysCtlClockSet(SYSCTL_SYSDIV_4 | SYSCTL_USE_PLL | SYSCTL_OSC_MAIN | SYSCTL_XTAL_16MHZ);
	ROM_SysCtlPeripheralEnable(SYSCTL_PERIPH_UART0);
	ROM_SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOA);
	ROM_GPIOPinConfigure(GPIO_PA0_U0RX);
	ROM_GPIOPinConfigure(GPIO_PA1_U0TX);
	ROM_GPIOPinTypeUART(GPIO_PORTA_BASE, GPIO_PIN_0 | GPIO_PIN_1);
	ROM_SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOF); //enable GPIO port for LED
	ROM_GPIOPinTypeGPIOOutput(GPIO_PORTF_BASE, GPIO_PIN_2); //enable pin for LED PF2
	ROM_UARTConfigSetExpClk(UART0_BASE, ROM_SysCtlClockGet(), 115200,
	(UART_CONFIG_WLEN_8 | UART_CONFIG_STOP_ONE | UART_CONFIG_PAR_NONE));
	ROM_IntMasterEnable(); //enable processor interrupts
	ROM_IntEnable(INT_UART0); //enable the UART interrupt
	ROM_UARTIntEnable(UART0_BASE, UART_INT_RX | UART_INT_RT); //only enable RX and TX interrupts
	ROM_UARTCharPut(UART0_BASE, 'S');
	ROM_UARTCharPut(UART0_BASE, 't');
	ROM_UARTCharPut(UART0_BASE, 'a');
	ROM_UARTCharPut(UART0_BASE, 'r');
	ROM_UARTCharPut(UART0_BASE, 't');
	ROM_UARTCharPut(UART0_BASE, 'e');
	ROM_UARTCharPut(UART0_BASE, 'd');
	ROM_UARTCharPut(UART0_BASE, '!');
	ROM_UARTCharPut(UART0_BASE, '\n');
	while (1) //let interrupt handler do the UART echo function
	{
		//if (ROM_UARTCharsAvail(UART0_BASE)) ROM_UARTCharPut(UART0_BASE, ROM_UARTCharGet(UART0_BASE));
	}
}
