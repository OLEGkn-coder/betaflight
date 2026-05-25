#include "platform.h"
#include "config/config.h"

const char * const defaultCliSettings[] = {
    "board_name VYRIY4V4",

    "resource GYRO_EXTI 1 C04",
    "resource GYRO_CS 1 A04",

    "resource SPI_SCK 1 A05",
    "resource SPI_SDI 1 A06",
    "resource SPI_SDO 1 A07",

    "resource I2C_SCL 2 B10",
    "resource I2C_SDA 2 B11",

    "resource OSD_CS 1 B12",

    "resource BEEPER 1 C05",
    "resource LED_STRIP 1 C09",

    "resource ADC_BATT 1 C00",
    "resource ADC_RSSI 1 C02",
    "resource ADC_CURR 1 C01",

    "resource SERIAL_TX 1 A09",
    "resource SERIAL_RX 1 A10",

    "resource SERIAL_TX 2 A02",
    "resource SERIAL_RX 2 A03",

    "resource SERIAL_TX 3 C10",
    "resource SERIAL_RX 3 C11",

    "resource SERIAL_TX 4 A00",
    "resource SERIAL_RX 4 A01",

    "resource SERIAL_TX 5 C12",
    "resource SERIAL_RX 5 D02",

    "resource SERIAL_TX 6 C06",
    "resource SERIAL_RX 6 C07",

    "resource MOTOR 1 B06",
    "resource MOTOR 2 B07",
    "resource MOTOR 3 B08",
    "resource MOTOR 4 B09",

    "resource PINIO 1 B05",

    "timer B06 AF2",
    "timer B07 AF2",
    "timer B08 AF2",
    "timer B09 AF2",

    "timer B05 AF2",
    "timer C09 AF3",

    "dma SPI_SDO 2 0",
    "dma SPI_TX 2 0",
    "dma ADC 1 0",

    "set gyro_1_bustype = SPI",
    "set gyro_1_spibus = 1",

    "set baro_bustype = I2C",
    "set baro_i2c_device = 2",

    "set adc_device = 1",

    "set pinio_config = 1,1,1,1",
    "set pinio_box = 40,255,255,255",

    "set motor_pwm_protocol = DSHOT600",

    NULL
};
