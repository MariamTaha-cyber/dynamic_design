/*
 * Micro_2.c
 *
 *  Created on: Oct 15, 2019
 *      Author: Mariam Taha
 */

#include "lcd.h"
#include "uart.h"
#include "TIMER.h"

TIMER_cnfg_t Timer_confg={TIMER1,OUTCOMP,INTERRUPT_ON,Prescaler_1024,IN_CLK,NA,0X00,1000,CHANNEL_A,NA,NA,NA,NA,INITIALISED};

#define start 0x01

int main(void)
{
	uint64 distance=0;
	uint8 speed=0;
	uint8 start_flag=0;

	UART_init();
	LCD_init();

	switch_init(PORTB,PB2);
	switch_init(PORTC,PC4);

	DDRB |= (1u << PB4);
	PORTB &= ~(1u << PB4);
	LCD_clearScreen();
	LCD_displayString("Distance= ");
	LCD_goToRowColumn(0,15);
	LCD_displayCharacter('m');

	while(UART_recieveByte()!=start);
	TIMER_init(&Timer_confg);

	while(1)
	{
		speed = UART_recieveByte();

		if(!(switch_status(PORTC, PC4)))
		{
			_delay_ms(30);
			if(!(switch_status(PORTC, PC4)))
			{
				start_flag=1;
			}
		}


		if(!(switch_status(PORTB, PB2)))
		{
			_delay_ms(30);
			if(!(switch_status(PORTB, PB2)))
			{
				distance = 0;
				start_flag=0;
			}
		}


		if(start_flag==1)
		{
			distance += (speed);
			LCD_goToRowColumn(0,9);
			LCD_intgerToString(distance);
		}

	}

	return 0;
}


