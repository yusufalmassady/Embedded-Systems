
#ifndef SPI_INTERFACE_H_  
#define SPI_INTERFACE_H_

void SPI_voidInitMaster(void);


void SPI_voidInitSlave(void);


u8  SPI_u8Transceive(u8 Copy_u8Data);

void SPI_u8MasterTransceive(u8 *Copy_u8RecCharr, u8 *Copy_u8Charr,u8 Copy_u8Size);

void SPI_u8SlaveTransceive(u8 *Copy_u8RecCharr, u8 *Copy_u8Charr);

#endif
