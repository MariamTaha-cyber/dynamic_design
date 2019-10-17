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
	case PORT_A: DDRA &=~(1<<Pin);
	PORTA |=(1<<Pin);
	break;
	case PORT_B: DDRB &=~(1<<Pin);
	PORTB |=(1<<Pin);
	break;
	case PORT_C: DDRC &=~(1<<Pin);
	PORTC |=(1<<Pin);
	break;
	case PORT_D: DDRD &=~(1<<Pin);
	PORTD |=(1<<Pin);
	break;
	}
}

uint8 switch_status(uint8 Port,uint8 Pin)
{
	uint8 status;
	switch(Port)
	{
	case PORT_A: status=PINA &(1<<Pin);
	break;
	case PORT_B: status=PINB &(1<<Pin);;
	break;
	case PORT_C: status=PINC &(1<<Pin);
	break;
	case PORT_D: status=PIND &(1<<Pin);
	break;
	}

	return status;
}
