/*
 * SPI_cfg.h
 *
 *  Created on: Oct 17, 2018
 *      Author: Mohamed
 */

#ifndef SPI_DRV_SPI_CFG_H_
#define SPI_DRV_SPI_CFG_H_

// SPI REGISTERS
#define SPCR (*(volatile u8 *)0x2D)
#define SPSR (*(volatile u8 *)0x2E)
#define SPDR (*(volatile u8 *)0x2F)
#endif /* SPI_DRV_SPI_CFG_H_ */
