/*
 * main.c
 *
 *  Created on: Sep 29, 2018
 *      Author: Mohamed
 */

#include "../LIB/STD_TYPES.h"
#include "../LIB/BIT_MATH.h"
#include "../DIO_DRV/DIO_Int.h"
#include "../SPI_Drv/SPI_Int.h"

void main(void)
{
	SPI_vidInitSlave();

	DIO_SetPinDir(PORTC,PIN_0, OUTPUT);

	DIO_SetPinVal( PORTC, PIN_0, LOW);

	 u8 result=0;

	while(1){

	 result=SPI_u8Tranceiver_Slave(3);

	if(result=='1')
	{
		 DIO_SetPinVal( PORTC, PIN_0, HIGH);
	}

	else
	{
		 DIO_SetPinVal( PORTC, PIN_0, LOW);
	}
	}
}

