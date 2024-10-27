/*
 * UART_Program.c
 *
 *  Created on: Feb 11, 2023
 *      Author: OMAR
 */
#include "Std_Types.h"
#include "Bit_Math.h"

#include "UART_CFG.h"
#include "UART_Interface.h"
#include "UART_Registers.h"

#include <stdbool.h>
#include <stdint.h>
#include "inc/hw_memmap.h"
#include "driverlib/gpio.h"
#include "driverlib/pin_map.h"
#include "driverlib/sysctl.h"

static volatile u32* Reg;

static void SelectChannel ()
{
    switch (UART_CHANNEL)
    {
    case UART0:
        Reg=UART0_Base;
        break;
    case UART1:
        Reg=UART1_Base;
        break;
    case UART2:
        Reg=UART2_Base;
        break;
    case UART3:
        Reg=UART3_Base;
        break;
    case UART4:
        Reg=UART4_Base;
        break;
    case UART5:
        Reg=UART5_Base;
        break;
    case UART6:
        Reg=UART6_Base;
        break;
    case UART7:
        Reg=UART7_Base;
        break;
    default:
        break;
    }
}
void UART_INIT ()
{
    SysCtlPeripheralEnable(SYSCTL_PERIPH_UART0);
    SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOA); // Enable the GPIOA peripheral
    GPIOPinConfigure(GPIO_PA0_U0RX); // Configure PA0 for U0RX
    GPIOPinConfigure(GPIO_PA1_U0TX); // Configure PA1 for U0TX
    GPIOPinTypeUART(GPIO_PORTA_BASE, GPIO_PIN_0 | GPIO_PIN_1); // Set the pin type to UART

    /*Select Channel*/
    SelectChannel ();

    /*Disable UART*/
    CLR_BIT(*((u8*)Reg+UART_CTL_offset),CTL_ENABLE);

    /*9600 Baud Rate*/
    *((u32*)(((u8*)Reg+UART_IBRD_offset))) = 325;
    *((u8*)Reg+UART_FBRD_offset) = 33;

    /*8 Bit Word Length*/
    *((u8*)Reg+UART_LCRH_offset)|= ((*((u8*)Reg+UART_LCRH_offset) & (0xFFFFFF9F)) | WORD_LENGTH<<5);

    SET_BIT(*((u8*)Reg+UART_LCRH_offset),LCRH_Enable_FIFOs);

    /*One Stop Bit*/
    CLR_BIT(*((u8*)Reg+UART_LCRH_offset),LCRH_Two_Stop_Bits_Select);

    //Enable UART and Enable RX, TX
    *((u32*)(((u8*)Reg+UART_CTL_offset)))=0x301;
}

void UART_Send (u8 Data)
{
    while (CHK_BIT(*((u8*)Reg+UART_flag),flag_TXFF) != 0){}
    *Reg = Data ;
}

u8 UART_Recieve ()
{
    while (CHK_BIT(*((u8*)Reg+UART_flag),flag_RXFE) != 0){}
    return *((u8*)Reg);
}
