/*
 * BNO055.h
 *
 *  Created on: Mar 1, 2023
 *      Author: El-Wattaneya
 */

#ifndef BNO055_H_
#define BNO055_H_

#include "Bit_Math.h"
#include "Std_Types.h"
#include "driverlib/i2c.h"
#include "inc/tm4c123gh6pm.h"
#include "inc/hw_i2c.h"
#include "inc/hw_memmap.h"
#include "inc/hw_types.h"
#include "inc/hw_gpio.h"
#include "driverlib/sysctl.h"
#include "driverlib/gpio.h"
#include "driverlib/pin_map.h"

// #define _BNO055_SLAVE_ADDRESS (0x29)
#define _BNO055_SLAVE_ADDRESS (0x29) // shifted one bit to the left
#define _OPR_MODE             (0x3D)
#define _NDOF_MODE            (0x0C)
#define _GYR_DATA_X_LSB       (0x14)
#define _GYR_DATA_X_MSB       (0x15)
#define _GYR_DATA_Y_LSB       (0x16)
#define _GYR_DATA_Y_MSB       (0x17)
#define _GYR_DATA_Z_LSB       (0x18)
#define _GYR_DATA_Z_MSB       (0x19)
#define _EUL_YAW_LSB          (0x1A)
#define _EUL_YAW_MSB          (0x1B)
#define _EUL_ROLL_LSB         (0x1C)
#define _EUL_ROLL_MSB         (0x1D)
#define _EUL_PITCH_LSB        (0x1E)
#define _EUL_PITCH_MSB        (0x1F)
#define _LIA_DATA_X_LSB       (0x28)
#define _LIA_DATA_X_MSB       (0x29)
#define _LIA_DATA_Y_LSB       (0x2A)
#define _LIA_DATA_Y_MSB       (0x2B)
#define _LIA_DATA_Z_LSB       (0x2C)
#define _LIA_DATA_Z_MSB       (0x2D)


#define YAW       (0)
#define ROLL      (1)
#define PITCH     (2)

#define ANG_VEL_X (0)
#define ANG_VEL_Y (1)
#define ANG_VEL_Z (2)

#define LIN_ACC_X (0)
#define LIN_ACC_Y (1)
#define LIN_ACC_Z (2)


void bno055_tx (u8 reg , u8 data);
void bno055_rx (u8 reg , u8 *str ,u8 data_len);
void bno055_init ();
void bno055_eul_angles (s16 *angle);
void bno055_gyro_data (s16 *ang_vel);
void bno055_lin_acc (s16 *accel);

#endif //02_SOURCE_02_HAL_BNO055_IMU_INC_BNO055_H_
