/**************************************************************/
/* Author  : Bishoy Nabil                                     */
/* Version : V01                                              */
/* Date    : 14 Jan 2020                                      */
/**************************************************************/

#ifndef CLCD_INTERFACE
#define CLCD_INTERFACE

/* Description: This API shall intialize LCD */
void CLCD_voidInitialize(void);

/* Description: This API shall display data on LCD */
void CLCD_voidWriteData(u8 Copy_u8Data);

/* Description: This API shall execute command on LCD */
void CLCD_voidWriteCmd(u8 Copy_u8Cmd);

void CLCD_voidWriteString(const char *Copy_pchString);

void CLCD_voidGoToXYPos(u8 Copy_u8XPos, u8 Copy_u8YPos);

#define CLCD_U8_LINE_ONE 0
#define CLCD_U8_LINE_TWO 1
#define CLCD_U8_LINE_TWO_ADD_OFFSET 0x40
#define CLCD_U8_SET_DDRAM_ADDRESS_CMD 0x80

#endif
