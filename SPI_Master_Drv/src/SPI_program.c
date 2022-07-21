#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "DIO_interface.h"
#include "SPI_interface.h"
#include "SPI_config.h"
#include "SPI_private.h"

void MSPI1_voidInit(void) {
	/*
	 Register CR1 configuration
	 Enable the SPI
	 Choose the Data order to be MSB
	 Select the SPI as Master
	 Choose the CPOL=0 idle clock is low and CPHA= 0 write first
	 slave management is enable and SSI=1
	 Choose prescaler value= 16 , Set bit3 & bit4 to , Clear bit5
	 */
	MSPI1->CR1 = 0X035C;

	/* disable multi-master mode , SS output is enabled */
	SET_BIT(MSPI1->CR2, 2);
}

void MSPI1_voidSendReceiveSynch(u8 Copy_u8DataToTransmit, u8 *Copy_DataToReceive) {
	/* Clear For Slave Select Pin */
	MGPIO_voidSetPinValue(MSPI1_SLAVE_PIN, LOW);

	/* Send Data */
	MSPI1->DR = Copy_u8DataToTransmit;

	/* Wait Busy Flag to finish */
	while (GET_BIT(MSPI1 -> SR, 7) == 1)
		;

	/* Return to the received data */
	*Copy_DataToReceive = MSPI1->DR;

	/* Set Salve Select Pin */
	MGPIO_voidSetPinValue(MSPI1_SLAVE_PIN, HIGH);
}

