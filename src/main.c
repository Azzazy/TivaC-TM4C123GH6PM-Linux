#include <stdint.h>
#include <stdbool.h>
#include "inc/hw_memmap.h"
#include "inc/hw_types.h"
#include "driverlib/rom.h"
#include "driverlib/sysctl.h"
#include "driverlib/gpio.h"
#include "dmostd.c"

void Lcd_command(unsigned char data)
{
	ROM_GPIOPinWrite(GPIO_PORTD_BASE, GPIO_PIN_0|GPIO_PIN_1,0x00);

	//ROM_GPIOPinWrite(GPIO_PORTB_BASE, GPIO_PIN_0|GPIO_PIN_1|GPIO_PIN_2|GPIO_PIN_3|GPIO_PIN_4|GPIO_PIN_5|GPIO_PIN_6|GPIO_PIN_7, data);//LCD data
	ROM_GPIOPinWrite(GPIO_PORTB_BASE, GPIO_PIN_4|GPIO_PIN_5|GPIO_PIN_6|GPIO_PIN_7, data);//LCD data
	ROM_GPIOPinWrite(GPIO_PORTD_BASE, GPIO_PIN_0|GPIO_PIN_1,0x00);
	ROM_SysCtlDelay(1000);
	ROM_GPIOPinWrite(GPIO_PORTD_BASE, GPIO_PIN_0|GPIO_PIN_1,0x02);//enabling lcd by high to low pulse
	ROM_SysCtlDelay(3000);
	ROM_GPIOPinWrite(GPIO_PORTD_BASE, GPIO_PIN_0|GPIO_PIN_1,0x00);
}

void Lcd_data(unsigned char data)
{
	ROM_GPIOPinWrite(GPIO_PORTD_BASE, GPIO_PIN_0|GPIO_PIN_1,0x00);

	//ROM_GPIOPinWrite(GPIO_PORTB_BASE, GPIO_PIN_0|GPIO_PIN_1|GPIO_PIN_2|GPIO_PIN_3|GPIO_PIN_4|GPIO_PIN_5|GPIO_PIN_6|GPIO_PIN_7, data);//LCD data
	ROM_GPIOPinWrite(GPIO_PORTB_BASE, GPIO_PIN_4|GPIO_PIN_5|GPIO_PIN_6|GPIO_PIN_7, data);//LCD data
	ROM_GPIOPinWrite(GPIO_PORTD_BASE, GPIO_PIN_0|GPIO_PIN_1,0x01);
	ROM_SysCtlDelay(1000);
	ROM_GPIOPinWrite(GPIO_PORTD_BASE, GPIO_PIN_0|GPIO_PIN_1,0x02);//enabling lcd by high to low pulse
	ROM_SysCtlDelay(3000);
	ROM_GPIOPinWrite(GPIO_PORTD_BASE, GPIO_PIN_0|GPIO_PIN_1,0x03);
}

void Lcd_Init()
{
	Lcd_command(0x38);
	delay(1000);
	Lcd_command(0x38);
	delay(1000);
	Lcd_command(0x06);
	delay(1000);
	Lcd_command(0x0E);
	delay(1000);
	Lcd_command(0x01);
	delay(1000);
	//0x38, 0x38, 0x06, 0x0E, 0x01
}

void Lcd_String_Display(char *str)
{
	while(*str)
	{
		Lcd_data(*str);
		str++;
	}
}


int main(void)
{
	ROM_SysCtlClockSet(SYSCTL_SYSDIV_16|SYSCTL_USE_PLL|SYSCTL_XTAL_16MHZ|SYSCTL_OSC_MAIN);

	ROM_SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOD);
	ROM_SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOB);

	ROM_GPIOPinTypeGPIOOutput(GPIO_PORTB_BASE, GPIO_PIN_0|GPIO_PIN_1|GPIO_PIN_2|GPIO_PIN_3| GPIO_PIN_4| GPIO_PIN_5| GPIO_PIN_6| GPIO_PIN_7);
	ROM_GPIOPinTypeGPIOOutput(GPIO_PORTD_BASE, GPIO_PIN_0|GPIO_PIN_1);

	//GPIOPinWrite(GPIO_PORTD_BASE, GPIO_PIN_0|GPIO_PIN_1,0x00);

	Lcd_Init();
	Lcd_String_Display("hai how are you....");

}
