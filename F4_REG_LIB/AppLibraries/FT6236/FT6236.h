/*!
 * FT6236.h
 */

#ifndef FT6236_H
#define FT6236_H

#ifdef __cplusplus
extern "C"{
#endif

#include "I2C_F4xx.h"

#define FT6236_ADDR 0x38           // I2C address
#define FT6236_G_FT5201ID 0xA8     // FocalTech's panel ID
#define FT6236_REG_NUMTOUCHES 0x02 // Number of touch points

#define FT6236_NUM_X 0x33 // Touch X position
#define FT6236_NUM_Y 0x34 // Touch Y position

#define FT6236_REG_MODE 0x00        // Device mode, either WORKING or FACTORY
#define FT6236_REG_CALIBRATE 0x02   // Calibrate mode
#define FT6236_REG_WORKMODE 0x00    // Work mode
#define FT6236_REG_FACTORYMODE 0x40 // Factory mode
#define FT6236_REG_THRESHHOLD 0x80  // Threshold for touch detection
#define FT6236_REG_POINTRATE 0x88   // Point rate
#define FT6236_REG_FIRMVERS 0xA6    // Firmware version
#define FT6236_REG_CHIPID 0xA3      // Chip selecting
#define FT6236_REG_VENDID 0xA8      // FocalTech's panel ID

#define FT6236_VENDID 0x11  // FocalTech's panel ID
#define FT6206_CHIPID 0x06  // FT6206 ID
#define FT6236_CHIPID 0x36  // FT6236 ID
#define FT6236U_CHIPID 0x64 // FT6236U ID

#define FT6236_DEFAULT_THRESHOLD 128 // Default threshold for touch detection

bool TouchInit(I2C *i2c, uint8_t thresh);
uint8_t Touched(void);
void GetPoint(uint8_t n);
uint16_t GetX(void);
uint16_t GetY(void);

#ifdef __cplusplus
}
#endif

#endif
