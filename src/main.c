/**
 * main.c
 */

#include "inc/tm4c123gh6pm.h"
#include <stdint.h>

void UART0Tx(char c);
void delayMs(int n);

void UARTIntHandler(void)
{

}

int main(void)
{
   SYSCTL_RCGCUART_R |= 1; /* provide clock to UART0 */
   SYSCTL_RCGCGPIO_R |= 1; /* enable clock to PORTA */

   /* UART0 initialization */
   UART0_CTL_R = 0;        /* disable UART0 */
   UART0_IBRD_R = 104;     /* 16MHz/16=1MHz, 1MHz/104=9600 baud rate */
   UART0_FBRD_R = 11;      /* fraction part, see Example 4-4 */
   UART0_CC_R = 0;         /* use system clock */
   UART0_LCRH_R = 0x60;    /* 8-bit, no parity, 1-stop bit, no FIFO */
   UART0_CTL_R = 0x301;    /* enable UART0, TXE, RXE */
   /* UART0 TX0 and RX0 use PA0 and PA1. Set them up. */
   GPIO_PORTA_DEN_R = 0x03;     /* Make PA0 and PA1 as digital */
   GPIO_PORTA_AFSEL_R = 0x03;   /* Use PA0,PA1 alternate function */
   GPIO_PORTA_PCTL_R = 0x11;    /* configure PA0 and PA1 for UART */

    delayMs(500);            /* wait for output line to stabilize */

   for(;;)
   {
       UART0Tx('Y');
       UART0Tx('E');
       UART0Tx('S');
       UART0Tx(' ');
   }
}

/* UART0 Transmit */
/* This function waits until the transmit buffer is available then */
/* writes the character in the transmit buffer. It does not wait */
/* for transmission to complete. */

/* delay n milliseconds (16 MHz CPU clock) */
void delayMs(int n)
{
 int i, j;
 for(i = 0 ; i < n; i++)
 for(j = 0; j < 3180; j++)
{} /* do nothing for 1 ms */
}

void UART0Tx(char c)
{
  while((UART0_FR_R & 0x20) != 0); /* wait until Tx buffer not full */
   UART0_DR_R = c;                 /* before giving it another byte */
}

/* Append delay functions and SystemInit() here */





