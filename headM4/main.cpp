#include "mbed.h"
#include "rtos.h"
#include "statistics.hpp"
#include "grideye.hpp"
#include "CO2.hpp"
#include "USB.hpp"
#include "health.hpp"
//#include "gpdma.h"
//#include "dsp.h"

int main (void) {
	CO2Init(p17, p18);	//p17=TX, p18=RX

    I2C i2c0(p32,p31);	//sda, scl
    I2C i2c1(p9,p10);
    GridEYEInit(&i2c0, &i2c1);

    USBInit();

    Thread tUSB(USBTask);

    Thread tStatistics(CpuLoadTask, NULL, osPriorityIdle);

    Thread tCO2Caller(CO2TaskCaller);

    Thread tGridEYECaller(GridEYETaskCaller);

    Thread::wait(osWaitForever);
}
