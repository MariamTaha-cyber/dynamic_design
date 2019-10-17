/*
 * switch.c
 *
 *  Created on: Oct 18, 2019
 *      Author: Mariam Taha
 */


#include "switch.h"

void switch_init(uint8 Port,uint8 Pin)
{
	switch(Port)
	{
	case PORTA: DDRA &=~(1<<Pin);
	PORTA |=(1<<Pin);
	break;
	case PORTB: DDRB &=~(1<<Pin);
	PORTB |=(1<<Pin);
	break;
	case PORTC: DDRC &=~(1<<Pin);
	PORTC |=(1<<Pin);
	break;
	case PORTD: DDRD &=~(1<<Pin);
	PORTD |=(1<<Pin);
	break;
	}
}

uint8 switch_status(uint8 Port,uint8 Pin)
{
	uint8 status;
	switch(Port)
	{
	case PORTA: status=PINA &(1<<Pin);
	break;
	case PORTB: status=PINB &(1<<Pin);;
	break;
	case PORTC: status=PINC &(1<<Pin);
	break;
	case PORTD: status=PIND &(1<<Pin);
	break;
	}

	return status;
}
