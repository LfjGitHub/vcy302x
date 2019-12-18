#include <stdlib.h>
#include <panic.h>
#include <string.h>
#include <i2c.h>
#include "cym.h"


#if defined(DEBUG_CYM_ENABLED)
#define CYM_DEBUG(x)     printf x
#else
#define CYM_DEBUG(x)
#endif
/*
typedef struct{
	char *cmd;
	char *action;
	char *ok;
	char *fail;
}cx2092x_string_t;

cx2092x_string_t cx2092x_list[]={
	{"Test1Sequence","./cxdish flash Test1.sfs iflash.bin","Test1Finish\n","Test1Failed\n"},
	{"Test2Sequence","./cxdish sendcmd 0xD308632C 0x00000040 0x000002C0  0x000002C1","Test2Finish\n","Test2Failed\n"},
	{"Test3Sequence","./cxdish flash Test3.sfs iflash.bin","Test3Finish\n","Test3Failed\n"},
	{"Test4Sequence","NULL","Test4Finish\n","Test4Failed\n"},
    {"NULL","NULL","NULL","NULL"},
};
*/
#define I2C_READ_BYTES_TO_ACK_OVERHEAD   3
#define I2C_READ_TX_LENGTH      1 
#define I2C_READ_RX_LENGTH      1

#define I2C_WRITE_BYTES_TO_ACK_OVERHEAD  1
#define I2C_WRITE_TX_LENGTH     2
#define I2C_WRITE_RX_LENGTH     0

#define CYM_DEFAULT_ADDRESS    0xAE

void CymRead(uint8 reg, uint8 *data)
{
    uint16 acknowledged = I2cTransfer(CYM_DEFAULT_ADDRESS, &reg, I2C_READ_TX_LENGTH, data, I2C_READ_RX_LENGTH);

    PanicFalse(acknowledged == I2C_READ_RX_LENGTH + I2C_READ_BYTES_TO_ACK_OVERHEAD);
}


void CymContinuousRead(uint8 reg, uint8 number_of_registers, uint8 *data)
{
    uint16 acknowledged = I2cTransfer(CYM_DEFAULT_ADDRESS, &reg, I2C_READ_TX_LENGTH, data, number_of_registers);

    PanicFalse(acknowledged == number_of_registers + I2C_READ_BYTES_TO_ACK_OVERHEAD);
}

void CymWrite(uint8 reg, uint8 data)
{
    uint8 packet[2];
    uint16 acknowledged;

    //CYM_DEBUG(( "reg=%x,data=%x\n", reg,data ));
    packet[0] = reg;
    packet[1] = data;
    acknowledged = I2cTransfer(CYM_DEFAULT_ADDRESS, packet, I2C_WRITE_TX_LENGTH, NULL, I2C_WRITE_RX_LENGTH);
    //CYM_DEBUG(( "acknowledged: %d\n", acknowledged ));
    PanicFalse(acknowledged == I2C_WRITE_TX_LENGTH + I2C_WRITE_BYTES_TO_ACK_OVERHEAD);

}

