/* Module Name : USART
 * File Name   : USART_program.c
 * Author      : Bishoy Nabil
 * Version     : 1.0
 * Date        : 13/4/2020 */
#include "USART_interface.h"
#include "USART_config.h"
#include "USART_register.h"

#define STOPBITS_CLEARMASK ((u32)0xFFFFCFFF)
#define PCE_PS_CLEARMASK   ((u32)0xFFFFF9FF)//used for parity
#define M_CLEARMASK        ((u32)0xFFFFEFFF)//Word length

#define UE_ENABLE_MASK     ((u32)0x00002000)//USART enable bit mask

/* array of five structures each one contains the addresses of a certain USART channel */
volatile USARTReg_t * const USART_ChannelsArray[5] = {USART1,USART2,USART3,USART4,USART5};

extern ErrorStatus USART_Init(u8 copy_u8USARTNum)
{
	/* set the USART enable bit */
	(USART_ChannelsArray[copy_u8USARTNum]->CR1) = (USART_ChannelsArray[copy_u8USARTNum]->CR1) | UE_ENABLE_MASK;
	/* set the baudrate in the baudrate register */
	(USART_ChannelsArray[copy_u8USARTNum]->BRR) = ((u32)BAUDRATE);
	/* clears the stopbit bits */
	(USART_ChannelsArray[copy_u8USARTNum]->CR2) = (USART_ChannelsArray[copy_u8USARTNum]->CR2) & STOPBITS_CLEARMASK;
	/* configure the stopbit bits */
	(USART_ChannelsArray[copy_u8USARTNum]->CR2) = (USART_ChannelsArray[copy_u8USARTNum]->CR2) | STOP_BITS;
	/* clears the wordlength and parity bits */
	(USART_ChannelsArray[copy_u8USARTNum]->CR1) = (USART_ChannelsArray[copy_u8USARTNum]->CR1) & PCE_PS_CLEARMASK & M_CLEARMASK;
	/* configure the wordlength and parity bits */
	(USART_ChannelsArray[copy_u8USARTNum]->CR1) = (USART_ChannelsArray[copy_u8USARTNum]->CR1) | PARITY | WORD_LENGTH;
	/* enables the TXEIE interrupt and the RXNEIE interrupt */
	(USART_ChannelsArray[copy_u8USARTNum]->CR1) = (USART_ChannelsArray[copy_u8USARTNum]->CR1) | RXNE_INTERRUPT | TXE_INTERRUPT;

	return OK;
}

extern ErrorStatus USART_Send(u8 copy_u8USARTNum, u8 copy_u8Data)
{
	ErrorStatus Local_ErrorStatus = OK;
	/* writes the required byte in the data register */
	USART_ChannelsArray[copy_u8USARTNum]->DR = (u32)copy_u8Data;
	return Local_ErrorStatus;
}

extern ErrorStatus USART_Receive(u8 copy_u8USARTNum, u8* copy_pu8ReceivedData)
{
	ErrorStatus Local_ErrorStatus = OK;
	/* reads the received byte from the data register */
	*copy_pu8ReceivedData = USART_ChannelsArray[copy_u8USARTNum]->DR;
	return Local_ErrorStatus;
}

extern Status USART_Config(u8 copy_u8USARTNum, u16 copy_u16BaudRate, u32 copy_u32StopBits, u32 copy_u32Parity, u32 copy_u32WordLength)
{
	Status Local_Status = IDLE;
	/* write the baudrate in the baudrate register */
	(USART_ChannelsArray[copy_u8USARTNum]->BRR) = copy_u16BaudRate;
	/* clears the stopbit bits */
	(USART_ChannelsArray[copy_u8USARTNum]->CR2) = (USART_ChannelsArray[copy_u8USARTNum]->CR2) & STOPBITS_CLEARMASK;
	/* configure the stopbit bits */
	(USART_ChannelsArray[copy_u8USARTNum]->CR2) = (USART_ChannelsArray[copy_u8USARTNum]->CR2) | copy_u32StopBits;
	/* clears the wordlength and parity bits */
	(USART_ChannelsArray[copy_u8USARTNum]->CR1) = (USART_ChannelsArray[copy_u8USARTNum]->CR1) & PCE_PS_CLEARMASK & M_CLEARMASK;
	/* configure the wordlength and parity bits */
	(USART_ChannelsArray[copy_u8USARTNum]->CR1) = (USART_ChannelsArray[copy_u8USARTNum]->CR1) | copy_u32Parity | copy_u32WordLength;
	return Local_Status;
}

extern ErrorStatus USART_SetFlags(u8 copy_u8USARTNum, u32 copy_u32Flag)
{
	/* sets required flag */
	(USART_ChannelsArray[copy_u8USARTNum]->CR1) |= copy_u32Flag;
	return OK;
}

extern ErrorStatus USART_ReadFlags(u8 copy_u8USARTNum, u32 copy_u32Flag, u8* copy_pu8FlagValue)
{
	/* reads required flag */
	*copy_pu8FlagValue = ((USART_ChannelsArray[copy_u8USARTNum]->SR)>>copy_u32Flag) & (0x00000001);
	return OK;
}
