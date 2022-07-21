/*  Author  : Fatma                          */
/*  Date    : 28 February 2022               */
/*  version : V1                             */

#include "BIT_MATH.h"
#include "STD_TYPES.h"

#include "RCC_interface.h"
#include "DIO_interface.h"
#include "STK_interface.h"
#include "SPI_interface.h"

void main(void) {
	/*Initialize clock system*/
	MRCC_voidInitSysClock();

	/*Enable peripheral GPIOA on APB2  */
	MRCC_voidEnableClock(APB2, IOPA);

	/*Enable peripheral GPIOB on APB2  */
	MRCC_voidEnableClock(APB2, IOPB);

	/*Enable peripheral SPI1 on APB2 bus */
	MRCC_voidEnableClock(APB2, SPI1);

	/* set the DIO pin directions */
	MGPIO_voidSetPinDirection(GPIOA, 7, OUTPUT_SPEED_2MHZ_AFPP); /* MOSI output */
	MGPIO_voidSetPinDirection(GPIOA, 6, INPUT_FLOATING); /* MISO output */
	MGPIO_voidSetPinDirection(GPIOA, 5, OUTPUT_SPEED_2MHZ_AFPP); /* CLK output  */

	/*Initialize SPI*/
	MSPI1_voidInit();

	u8 receiver, button;

	MGPIO_voidSetPinDirection(GPIOB, PIN0, INPUT_PULLUP_PULLDOWN); /* PIN0 output */
	MGPIO_voidSetPinValue(GPIOB, PIN0, HIGH);

	while (1) {
		button = MGPIO_u8GetPinValue(GPIOB, PIN0);
		if (button == LOW) {
			MSPI1_voidSendReceiveSynch('1', &receiver);

		} else {
			MSPI1_voidSendReceiveSynch('0', &receiver);
		}
	}
}
