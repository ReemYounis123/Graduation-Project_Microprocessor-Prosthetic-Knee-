/*
 * UART_Registers.h
 *
 *  Created on: Feb 11, 2023
 *      Author: OMAR
 */

#ifndef UART_REGISTERS_H_
#define UART_REGISTERS_H_

#define UART0_Base        ((volatile u32*)(0x4000C000))
#define UART1_Base        ((volatile u32*)(0x4000D000))
#define UART2_Base        ((volatile u32*)(0x4000E000))
#define UART3_Base        ((volatile u32*)(0x4000F000))
#define UART4_Base        ((volatile u32*)(0x40010000))
#define UART5_Base        ((volatile u32*)(0x40011000))
#define UART6_Base        ((volatile u32*)(0x40012000))
#define UART7_Base        ((volatile u32*)(0x40013000))

#define UART_DATA_offset             (0x0)

#define UART_IBRD_offset             (0x024)

#define UART_FBRD_offset             (0x028)

#define UART_LCRH_offset             (0x02C)
#define LCRH_Two_Stop_Bits_Select      3
#define LCRH_Enable_FIFOs              4

#define UART_flag                    (0x018)
#define flag_TXFF                      5
#define flag_RXFE                      4

#define UART_CTL_offset              (0x030)
#define CTL_ENABLE                     0
#define CTL_High_Speed_Enable          5
#define CTL_Transmit                   8
#define CTL_Recieve                    9

#define UART_RIS_offset             (0x03C)
#define RIS_TX                         5
#define RIS_RX                         4

#define UART_ICR_offset             (0x044)
#define ICR_TXIC                       5
#define ICR_RXIC                       4

#endif /* UART_REGISTERS_H_ */
