/*******************************************************************************
Copyright (c) 2018 Qualcomm Technologies International, Ltd.

FILE NAME
    power_smb1352_i2c.h

DESCRIPTION
    Handle SMB1352 i2c access.
*/

#ifndef CYM_I2C_H_
#define CYM_I2C_H_

/****************************************************************************
NAME
    CymRead

DESCRIPTION
    Read register from the SMB1352

RETURNS
    void
*/
void CymRead(uint8 reg, uint8 *data);

/****************************************************************************
NAME
    CymContinuousRead

DESCRIPTION
    Do a continous read of the registers from the SMB1352

RETURNS
    void
*/
void CymContinuousRead(uint8 reg, uint8 number_of_registers, uint8 *data);

/****************************************************************************
NAME
    CymWrite

DESCRIPTION
    Write to a register on the SMB1352

RETURNS
    void
*/

void CymWrite(uint8 reg, uint8 data);

/****************************************************************************
NAME
    CymWriteEnable

DESCRIPTION
    Enable / disable volatile writes to the SMB1352

RETURNS
    void
*/

void CymWriteEnable(bool enable);

#endif /* POWER_SMB1352_I2C_H_ */
