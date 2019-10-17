/*
 * Micro_2.c
 *
 *  Created on: Oct 15, 2019
 *      Author: Mariam Taha
 */

#include "Measurement_ECU.h"

TIMER_cnfg_t Timer_confg={TIMER1,OUTCOMP,INTERRUPT_ON,Prescaler_1024,IN_CLK,NA,0X00,1000,CHANNEL_A,NA,NA,NA,NA,INITIALISED};

#define start 0x01

int main(void)
{
	uint64 distance=0;
	uint8 speed=0;
	uint8 start_flag=0;

	Measurement_ECU_init();

	switch_init(PORTC,0);
	switch_init(PORTC,1);

	screen_init();


	while(UART_recieveByte()!=start);
	TIMER_init(&Timer_confg);

	while(1)
	{
		speed = UART_recieveByte();

		if(!switch_status(PORTC,0))
		{
			_delay_ms(30);
			if(!switch_status(PORTC,0))
			{
				start_flag=1;
			}
		}


		if(!switch_status(PORTC,1))
		{
			_delay_ms(30);
			if(!switch_status(PORTC,1))
			{
				start_flag=0;
			}
		}


		if(start_flag==1)
		{
			distance = calculations(speed);
			display_distance(distance);
		}

	}

	return 0;
}


