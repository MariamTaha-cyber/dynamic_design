/*
 * MC1.c
 *
 *  Created on: Oct 15, 2019
 *      Author: Randa
 */

#include "lcd.h"
#include "keypad.h"
#include "TIMER.h"
#include "uart.h"
#include "switch.h"

#define startTimer 0x01

void displayTime();

int main(void)
{
	uint8 speed = 0;
	uint8 flagInc = 0;
	uint8 flagDec = 0;

	switch_init(PORTB,PB2);
	switch_init(PORTC,PC4);

	UART_init();
	LCD_init();
	LCD_clearScreen();
	LCD_displayString("Time ");

	LCD_goToRowColumn(1,0);
	LCD_displayString("Speed: ");
	speed = KeyPad_getPressedKey();
	LCD_goToRowColumn(1,6);
	LCD_intgerToString(speed);

	TIMER_cnfg_t timer = {TIMER1, OUTCOMP, INTERRUPT_ON, Prescaler_1024, IN_CLK, NA, 0x00, 1000, CHANNEL_A, NA, NA, NA, NA, INITIALISED};
	UART_sendByte(startTimer);
	TIMER_init(&timer);

	while(1)
	{
		if(oneSecFlag == 1)
		{
			UART_sendByte(speed);
			oneSecFlag = 0;
		}

		if(!(switch_status(PORTC, PC4)))
		{
			_delay_ms(30);
			if(!(switch_status(PORTC, PC4)))
			{
				if(flagInc == 0)
				{
					speed++;
					LCD_goToRowColumn(1,6);
					LCD_intgerToString(speed);
					flagInc = 1;
				}
			}
		}
		else
		{
			flagInc = 0;
		}
		if(!(switch_status(PORTB, PB2)))
		{
			_delay_ms(30);
			if(!(switch_status(PORTB, PB2)))
			{
				if(flagDec == 0)
				{
					speed--;
					LCD_goToRowColumn(1,6);
					LCD_intgerToString(speed);
					LCD_displayCharacter(' ');
					flagDec = 1;
				}
			}
		}
		else
		{
			flagDec = 0;
		}

		displayTime();
	}
}

void displayTime()
{
	LCD_goToRowColumn(0, 5);
	LCD_intgerToString(hours / 10);
	LCD_intgerToString(hours % 10);
	LCD_goToRowColumn(0, 7);
	LCD_displayCharacter(':');

	LCD_goToRowColumn(0, 8);
	LCD_intgerToString(minutes / 10);
	LCD_intgerToString(minutes % 10);
	LCD_goToRowColumn(0, 10);
	LCD_displayCharacter(':');

	LCD_goToRowColumn(0, 11);
	LCD_intgerToString(seconds / 10);
	LCD_intgerToString(seconds % 10);
}
