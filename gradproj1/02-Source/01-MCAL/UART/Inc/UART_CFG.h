/*
 * UART_CFG.h
 *
 *  Created on: Feb 11, 2023
 *      Author: OMAR
 */

#ifndef UART_CFG_H_
#define UART_CFG_H_

#define WORD_LENGTH           _8_BIT

#define HIGH_SPEED_Select     DISABLE

#define UART_CHANNEL          UART0

typedef enum {
    _5_BIT,
    _6_BIT,
    _7_BIT,
    _8_BIT,
}WordLength;

typedef enum {
    DISABLE,   /* system clock divided by 16  */
    ENABLE,    /* system clock divided by 8   */
}HIGH_SPEED;

typedef enum
{
    UART0,
    UART1,
    UART2,
    UART3,
    UART4,
    UART5,
    UART6,
    UART7,
}CHANNEL;

#endif /* UART_CFG_H_ */
