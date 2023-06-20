

#include "FT6236.h"
#include "STM_LOG.h"


//static const char *TAG = "STM32_LOG";

I2C *_i2c;
static uint8_t touches;
static uint16_t touchX[2], touchY[2], touchID[2];
static uint16_t X, Y;

void writeRegister8(uint8_t reg, uint8_t val);
uint8_t readRegister8(uint8_t reg);
void readData(void);

void readData(void){
    uint8_t i2cdat[16];

    _i2c -> Memory_Receive((FT6236_ADDR << 1), 0, 1, i2cdat, 16);

    touches = i2cdat[0x02];
    if ((touches > 2) || (touches == 0)){
        touches = 0;
    }

    for (uint8_t i = 0; i < 2; i++){
        touchX[i] = i2cdat[0x03 + i * 6] & 0x0F;
        touchX[i] <<= 8;
        touchX[i] |= i2cdat[0x04 + i * 6];
        touchY[i] = i2cdat[0x05 + i * 6] & 0x0F;
        touchY[i] <<= 8;
        touchY[i] |= i2cdat[0x06 + i * 6];
        touchID[i] = i2cdat[0x05 + i * 6] >> 4;
    }
}

uint8_t readRegister8(uint8_t reg){
    uint8_t x = 0;

    _i2c -> Memory_Receive((FT6236_ADDR << 1), reg, 1, &x, 1);

    return x;
}

void writeRegister8(uint8_t reg, uint8_t val){
	uint8_t x = val;

	_i2c -> Memory_Transmit((FT6236_ADDR << 1), reg, 1, &x, 2);
}

bool TouchInit(I2C *i2c, uint8_t thresh){
	_i2c = i2c;

    writeRegister8(FT6236_REG_THRESHHOLD, thresh);
    uint8_t tmp = readRegister8(FT6236_REG_VENDID);
    if (tmp != FT6236_VENDID){
        return false;
    }

    uint8_t id = readRegister8(FT6236_REG_CHIPID);
    if ((id != FT6236_CHIPID) && (id != FT6236U_CHIPID) && (id != FT6206_CHIPID)){
        return false;
    }

    return true;
}

uint8_t Touched(void){
    uint8_t n = readRegister8(FT6236_REG_NUMTOUCHES);
    if (n > 2) n = 0;
    return n;
}

void GetPoint(uint8_t n){
    readData();
	X = touchX[n];
	Y = touchY[n];
}

uint16_t GetX(void){
	return X;
}
uint16_t GetY(void){
	return Y;
}
