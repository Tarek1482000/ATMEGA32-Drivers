/******************************************************************************
 *
 * Module: I2C
 *
 * File Name: twi.h
 *
 * Description: I2C communication protocol for AVR
 *
 * Author: Tarek Ahmed
 *
 *******************************************************************************/

#ifndef TWI_H_
#define TWI_H_

#include "../mcu_config/std_types.h"
/*******************************************************************************
 *                                Definitions                                  *
 *******************************************************************************/
/* I2C Status Bits in the TWSR Register */
#define TWI_START         0x08 /* start has been sent */
#define TWI_REP_START     0x10 /* repeated start */
#define TWI_MT_SLA_W_ACK  0x18 /* Master transmit ( slave address + Write request ) to slave + ACK received from slave. */
#define TWI_MT_SLA_R_ACK  0x40 /* Master transmit ( slave address + Read request ) to slave + ACK received from slave. */
#define TWI_MT_DATA_ACK   0x28 /* Master transmit data and ACK has been received from Slave. */
#define TWI_MR_DATA_ACK   0x50 /* Master received data and send ACK to slave. */
#define TWI_MR_DATA_NACK  0x58 /* Master received data but doesn't send ACK to slave. */



/*******************************************************************************
 *                             Types Declaration                                  *
 *******************************************************************************/

typedef enum
{
	FIRST=0x01 , SECOND=0x02 , THIRD=0x03, FORTH=0x04
}TWI_Address;



typedef enum
{
	FOUR_HAUNDRED_KBITS_S=0X02 , ONE_HAUNDRED_KBITS_S=0X20 /* 32 */
}TWI_BaudRate;


typedef struct
{
	TWI_Address address;
	TWI_BaudRate bit_rate;
}TWI_ConfigType;



/*******************************************************************************
 *                              Functions Prototypes                           *
 *******************************************************************************/

void TWI_init(const TWI_ConfigType *Config_Ptr);
void TWI_start(void);
void TWI_stop(void);
void TWI_writeByte(uint8 data);
uint8 TWI_readBiteWithACK(void);
uint8 TWI_readByteWithNACK(void);
uint8 TWI_getStatus(void);

#endif /* TWI_H_ */
