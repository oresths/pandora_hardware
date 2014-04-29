#ifndef HEALTH_HPP_
#define HEALTH_HPP_

#include "grideye.hpp"
#include "CO2.hpp"
#include "USB.hpp"
#include "PeripheralNames.h"

#define HEALTH_SIGNAL 0x1

#define I2C_SI 3	///I2C Serial Interrupt flag
#define I2C_STOP 4	///I2C STOP flag
#define I2C_START 5	///I2C START flag

void CO2HealthTask(void const *args);

void GridEYEHealthTask(void const *args);

void clearHealthyCO2() ;

void clearHealthyGridEYE();

void HealthyCO2valueSet(float value);

void HealthyGridEYEvaluesSet(uint8_t values[], uint8_t grideye_num);

void repairCO2(uint8_t count);

void repairI2C(uint8_t count, int i2c_base);

#endif /* HEALTH_HPP_ */
