/*******************************************************************************
Copyright (c) 2017 Qualcomm Technologies International, Ltd.
Part of 6.3.0

FILE NAME
    anc_data.c

DESCRIPTION
    Encapsulation of the ANC VM Library data.
*/

#include "anc_config_data.h"
#include "anc_data.h"

#include <stdlib.h>
#include <string.h>

/******************************************************************************/
bool ancDataSetSidetoneGain(uint16 sidetone_gain)
{
    UNUSED(sidetone_gain);
    return FALSE;
}

uint16 ancDataGetSidetoneGain(void)
{
    return 0;
}

void ancConfigDataUpdateOnStateChange(void)
{

}

void ancConfigDataUpdateOnModeChange(void)
{

}
