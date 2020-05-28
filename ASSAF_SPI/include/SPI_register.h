/* Module Name : SPI
 * File Name   : SPI_register.h
 * Author      : Bishoy Nabil
 * Version     : 1.0
 * Date        : 22/4/2020 */

#ifndef SPI_REGISTER_H
#define SPI_REGISTER_H

typedef struct{
	u32 CR1;
	u32 CR2;
	u32 SR;
	u32 DR;
	u32 CRCPR;
	u32 RXCRCR;
	u32 TXCRCR;
	u32 I2SCFGR;
	u32 I2SPR;
}SPIReg_t;

#define SPI1                             ((volatile SPIReg_t *const)0x40013000)


#endif
