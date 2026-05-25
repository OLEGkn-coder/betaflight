#include "target.h"
#include "platform.h"
#include "config/config.h"

void targetConfiguration(void)
{
    setConfigValue(GYRO_1_BUSTYPE, SPI);
    setConfigValue(GYRO_1_SPIPIN, SPI1);

    setConfigValue(BARO_BUSTYPE, I2C);
    setConfigValue(BARO_I2C_DEVICE, 2);

    setConfigValue(ADC_DEVICE, 1);

    setConfigValue(PINIO_CONFIG, "1,1,1,1");
    setConfigValue(PINIO_BOX, "40,255,255,255");

    setConfigValue(MOTOR_PWM_PROTOCOL, DSHOT600);
}
