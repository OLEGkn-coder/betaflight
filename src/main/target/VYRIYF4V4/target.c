#include "pg/pg.h"
#include "target.h"
#include "fc/config.h"

void targetConfiguration(void)
{
    // ГІРОСКОП ТА ШИНА SPI 
    cliExec("set gyro_1_bustype = SPI");
    cliExec("set gyro_1_spibus = 1");
    cliExec("set gyro_1_sensor_align = CW90");
    cliExec("resource GYRO_EXTI 1 C04");
    cliExec("resource GYRO_CS 1 A04");
    cliExec("resource SPI_SCK 1 A05");
    cliExec("resource SPI_SDI 1 A06");
    cliExec("resource SPI_SDO 1 A07");

    // UART ПОРТИ (Всі 6 портів з твого дампу)
    cliExec("resource SERIAL_TX 1 A09");
    cliExec("resource SERIAL_RX 1 A10");
    cliExec("resource SERIAL_TX 2 A02");
    cliExec("resource SERIAL_RX 2 A03");
    cliExec("resource SERIAL_TX 3 C10");
    cliExec("resource SERIAL_RX 3 C11");
    cliExec("resource SERIAL_TX 4 A00");
    cliExec("resource SERIAL_RX 4 A01");
    cliExec("resource SERIAL_TX 5 C12");
    cliExec("resource SERIAL_RX 5 D02");
    cliExec("resource SERIAL_TX 6 C06");
    cliExec("resource SERIAL_RX 6 C07");

    // I2C ТА ІНШІ СЕНСОРИ
    cliExec("resource I2C_SCL 2 B10");
    cliExec("resource I2C_SDA 2 B11");
    cliExec("resource ADC_BATT 1 C00");
    cliExec("resource ADC_CURR 1 C01");
    cliExec("resource ADC_RSSI 1 C02");
    cliExec("resource BEEPER 1 C05");
    cliExec("resource LED_STRIP 1 C09");

    // OSD ТА КАМЕРА
    cliExec("resource OSD_CS 1 B12");
    cliExec("resource CAMERA_CONTROL 1 B03");
    cliExec("set osd_displayport_device = AUTO");

    // МОТОРИ
    cliExec("resource MOTOR 1 B06");
    cliExec("resource MOTOR 2 B07");
    cliExec("resource MOTOR 3 B08");
    cliExec("resource MOTOR 4 B09");
    cliExec("set motor_pwm_protocol = DSHOT600");
    cliExec("set dshot_burst = ON");

    // РЕЛЕ ТА СЕРВО (ТОЧНО ПО ТВОЄМУ ДАМПУ)
    cliExec("resource SERVO 2 B05"); 
    cliExec("resource PINIO 1 B05");
    cliExec("set pinio_config = 1,1,1,1");
    cliExec("set pinio_box = 40,255,255,255"); 

    // ПРИЙМАЧ ТА ОСНОВНІ НАЛАШТУВАННЯ
    cliExec("set serialrx_provider = CRSF");
    cliExec("set motor_kv = 1960");
}
