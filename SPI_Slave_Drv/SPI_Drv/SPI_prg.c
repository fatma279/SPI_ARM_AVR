/*
 * SPI_prg.c
 *
 *  Created on: Oct 17, 2018
 *      Author: Mohamed
 */


#include "../LIB/STD_TYPES.h"
#include "../LIB/BIT_MATH.h"
#include "../DIO_DRV/DIO_Int.h"

#include "SPI_cfg.h"

void SPI_vidInitSlave(void)
{
	/*Register SPCR configuration*/
	/*Enable the SPI by setting Bit 6 – SPE: SPI Enable in register SPCR*/
	/*Choose the Data order to be MSB by setting Bit 5 – DORD: Data Order */
	/*Select the SPI as Slave, Clear Bit 4 – MSTR: Master/Slave Select*/
	/*Choose the CPOL=0 and CPHA= 0, Bit 3 – CPOL: Clock Polarity, Bit 2 – CPHA: Clock Phase*/
	/*Choose prescaler value= 16 , Clear SPR1, set SPR0 */
	SET_BIT(SPCR,6);
	CLR_BIT(SPCR,5);
	CLR_BIT(SPCR,4);
	CLR_BIT(SPCR,3);
	CLR_BIT(SPCR,2);
	CLR_BIT(SPCR,1);
	SET_BIT(SPCR,0);


	/*MOSI -> PB5 as Input*/
	DIO_SetPinDir(PORTB,PIN_5,INPUT);
	/*MISO -> PB6 as Output*/
	DIO_SetPinDir(PORTB,PIN_6, OUTPUT);
	/*SCK-> PB7 as Input*/
	DIO_SetPinDir(PORTB,PIN_7, INPUT);
	/*SS -> PB4 as Input*/
	DIO_SetPinDir(PORTB,PIN_4,INPUT);

}

u8 SPI_u8Tranceiver_Slave(u8 Loc_u8data)
{
	volatile u8 spsr;
	/*Store the data in SPDR Register*/
	SPDR=Loc_u8data;
	/* Wait for reception complete, wait till SPIF Flag is set*/
	while(GET_BIT(SPSR,7)==0);
	/*Dummy read for SPSR register to clear the SPIF: SPI Interrupt Flag*/
	spsr=SPSR;
	/* Return data register */
	return SPDR;

}
