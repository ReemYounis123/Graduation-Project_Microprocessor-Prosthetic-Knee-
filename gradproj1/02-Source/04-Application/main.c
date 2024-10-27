

/**
 * main.c
 */
#include "Std_Types.h"
#include <stdbool.h>
#include <stdint.h>
#include "BNO055.h"
#include "I2C0.h"
#include "inc/hw_memmap.h"
#include "driverlib/sysctl.h"
#include "driverlib/gpio.h"
#include "driverlib/pin_map.h"
#include "driverlib/sysctl.h"



int main(void)
{
    SysCtlClockSet(SYSCTL_SYSDIV_4 | SYSCTL_USE_PLL | SYSCTL_XTAL_16MHZ | SYSCTL_OSC_MAIN);
    UART_INIT ();
    bno055_init();


    while(1)
    {
        s16 angles[3];
        s16 yaw,roll,pitch;
        s16 ang_vel[3];
        s16 ang_vel_x,ang_vel_y,ang_vel_z;
        s16 accel[3];
        s16 accel_x,accel_y,accel_z;
        bno055_eul_angles (angles);
        bno055_gyro_data (ang_vel);
        bno055_lin_acc (accel);
        yaw = angles[YAW];
        roll = angles[ROLL];
        pitch = angles[PITCH];
        ang_vel_x = ang_vel[ANG_VEL_X];
        ang_vel_y = ang_vel[ANG_VEL_Y];
        ang_vel_z = ang_vel[ANG_VEL_Z];
        accel_x = accel[LIN_ACC_X];
        accel_y = accel[LIN_ACC_Y];
        accel_z = accel[LIN_ACC_Z];
        UART_Send (yaw);
        UART_Send (roll);
        UART_Send (pitch);
        SysCtlDelay(2000000);
    }

}
