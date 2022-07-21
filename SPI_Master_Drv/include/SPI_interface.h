#ifndef SPI_INTERFACE_H
#define SPI_INTERFACE_H


void MSPI1_voidInit(void);

void MSPI1_voidSendReceiveSynch(u8 Copy_u8DataToTransmit, u8 *Copy_DataToReceive);


#endif
