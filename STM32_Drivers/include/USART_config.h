/* Module Name : USART
 * File Name   : USART_config.h
 * Author      : Bishoy Nabil
 * Version     : 1.0
 * Date        : 14/4/2020 */

#ifndef USART_CONFIG_H_
#define USART_CONFIG_H_

#define BAUDRATE                        BR_115200
#define PARITY                          NO_PARITY
#define STOP_BITS                       STOPBITS_ONE
#define WORD_LENGTH                     DATABITS_8
#define TXE_INTERRUPT                   TX_INTERRUPT_ENABLED
#define RXNE_INTERRUPT                  RX_INTERRUPT_ENABLED

#endif /* USART_CONFIG_H_ */
