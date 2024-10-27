/*
 * BNO055.c
 *
 *  Created on: Mar 1, 2023
 *      Author: El-Wattaneya
 */
#include <stdint.h>
#include <stdbool.h>
#include "Bit_Math.h"
#include "Std_Types.h"
#include "I2C0.h"
#include "BNO055.h"
#include "DELAY.h"


void bno055_tx (u8 reg, u8 data){

    s16 comres = 0;
    // Tell the master module what address it will place on the bus when
    // communicating with the slave.
    I2CMasterSlaveAddrSet(I2C0_BASE, _BNO055_SLAVE_ADDRESS, false);

    //send the slave address, control bit, and registar address for where to write to
    I2CMasterDataPut(I2C0_BASE, reg);

    //Initiate send of data from the MCU
    I2CMasterControl(I2C0_BASE, I2C_MASTER_CMD_BURST_SEND_START);

    // Wait until MCU is done transferring.
    while(I2CMasterBusy(I2C0_BASE));

      // send the information to write
    I2CMasterDataPut(I2C0_BASE, data);

      // Initiate send of data from the MCU
    I2CMasterControl(I2C0_BASE, I2C_MASTER_CMD_BURST_SEND_FINISH);

      // Wait until MCU is done transferring
    while(I2CMasterBusy(I2C0_BASE));

      if(I2CMasterErr(I2C0_BASE)==I2C_MASTER_ERR_NONE)
      {
        comres = 0; // Success
      }
      else
      {
        comres = -1; // Error
      }

}

void bno055_rx (u8 reg, u8 *str,u8 data_len){
// from datasheet page 92
    u16 i=0;
    s16 comres = 0;
    // This function is used to select the device to read from
    // false == write to slave
    I2CMasterSlaveAddrSet(I2C0_BASE, _BNO055_SLAVE_ADDRESS, false);

    // Set the I2C Bus to tell the device which first register is meant to be read
    I2CMasterDataPut(I2C0_BASE, reg);

    // send slave address, control bit, and register address byte to slave device
    I2CMasterControl(I2C0_BASE, I2C_MASTER_CMD_BURST_SEND_START);

    //wait for MCU to finish transaction
    while(I2CMasterBusy(I2C0_BASE));
    for(i = 0;i<(data_len); i++)
    {
      if(i == 0)
      {
        // Start Communication
          I2CMasterSlaveAddrSet(I2C0_BASE, _BNO055_SLAVE_ADDRESS, true);
          I2CMasterControl(I2C0_BASE, I2C_MASTER_CMD_BURST_RECEIVE_START);

      }
      else if(i == data_len-1)
      {
        // Read the last byte
        I2CMasterControl(I2C0_BASE, I2C_MASTER_CMD_BURST_RECEIVE_FINISH);
      }
      else
      {
        // read middle byte
        I2CMasterControl(I2C0_BASE, I2C_MASTER_CMD_BURST_RECEIVE_CONT);
      }

      while(I2CMasterBusy(I2C0_BASE));

      // put read data in data array
      str[i] = I2CMasterDataGet(I2C0_BASE);

      if (I2CMasterErr(I2C0_BASE)==I2C_MASTER_ERR_NONE)
      {
        comres = 0; // success
      }
      else
      {
        comres = -1; // error occured, end comms and exit
        I2CMasterControl(I2C0_BASE, I2C_MASTER_CMD_BURST_RECEIVE_FINISH);
        while(I2CMasterBusy(I2C0_BASE));
        i = data_len;
      }
    }//I2CMasterControl(ui32Base, I2C_MASTER_CMD_BURST_SEND_STOP);
  }


void bno055_init (){

    initI2C0();
    bno055_tx (_OPR_MODE, _NDOF_MODE);
    delay(50);//from  any other mode to config_mode wait 19ms page 21

}

void bno055_eul_angles (s16 *angle){
 //page 51,52
    s16 val = 0;//-ve no considered -1
    u16 i = 0;
    u8 eul[8];
    bno055_rx (_EUL_YAW_LSB, eul, 6);//6 registers of eul angles, begin with LSB reg

    for(i=0;i<3;i++)
    {
        val = eul[i*2+1];//idx=1: eul_ang_yaw_lsb, idx=3: eul_ang_roll_lsb, idx=5: eul_ang_pitch_lsb
        val = val << 8;//shifted 8 bits to the right for the received msb values
        val |= eul[i*2];//idx=0: eul_ang_yaw_msb, idx=2: eul_ang_roll_msb, idx=4: eul_ang_pitch_msb
        angle[i] = (val/16);//for one degree -> 16 bits
    }
}

void bno055_gyro_data (s16 *ang_vel){

//page 51,52
     s16 val = 0;//-ve no considered -1
     u16 i = 0;
     u8 gyro[8];
     bno055_rx (_GYR_DATA_X_LSB, gyro, 6);//6 registers of gyro_data, begin with LSB reg

     for(i=0;i<3;i++){
         val = gyro[i*2+1];//idx=1: gyro_x_lsb, idx=3: gyro_y_lsb, idx=5: gyro_z_lsb
         val = val<<8;//shifted 8 bits to the right for the received msb values
         val |= gyro[i*2];//idx=0: gyro_x_msb, idx=2: gyro_y_msb, idx=4: gyro_z_msb
         ang_vel[i] = (val/16);//for one degree/s -> 16 bits

     }
}

void bno055_lin_acc (s16 *accel){

//page 51,52
     s16 val = 0;//-ve no considered -1
     u16 i = 0;
     u8 acc[8];
     bno055_rx (_LIA_DATA_X_LSB, acc, 6);//6 registers of acc_direction, begin with LSB reg

     for(i=0;i<3;i++){
         val = acc[i*2+1];//idx=1: lin_acc_x_lsb, idx=3: lin_acc_y_lsb, idx=5: lin_acc_z_lsb
         val = val<<8;//shifted 8 bits to the right for the received msb values
         val |= acc[i*2];//idx=0: lin_acc_x_msb, idx=2: lin_acc_y_msb, idx=4: lin_acc_z_msb
         accel[i] = (val/100);//for one m/s^2 -> 100 bits

     }
}


