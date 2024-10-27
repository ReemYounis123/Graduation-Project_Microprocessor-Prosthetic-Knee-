/*
 * UART_Interface.h
 *
 *  Created on: Feb 11, 2023
 *      Author: OMAR
 */

#ifndef UART_INTERFACE_H_
#define UART_INTERFACE_H_

static void SelectChannel ();

void UART_INIT ();

void UART_Send (u8 Data);

u8 UART_Recieve ();


#endif /* UART_INTERFACE_H_ */
