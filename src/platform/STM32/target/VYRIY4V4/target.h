#pragma once

#define TARGET_BOARD_IDENTIFIER "VYRF4V4"
#define USBD_PRODUCT_STRING "Betaflight - VYRIYF4V4"

#define STM32F405

#define USE_SPI
#define USE_SPI_DEVICE_1

#define GYRO_SPI_INSTANCE          SPI1
#define GYRO_CS_PIN               PA4
#define GYRO_EXTI_PIN             PC4

#define SPI1_SCK_PIN              PA5
#define SPI1_SDI_PIN              PA6
#define SPI1_SDO_PIN              PA7

#define OSD_SPI_INSTANCE          SPI1
#define OSD_CS_PIN               PB12

#define USE_I2C
#define USE_I2C_DEVICE_2

#define I2C2_SCL_PIN             PB10
#define I2C2_SDA_PIN             PB11

#define USE_VCP

#define USE_UART1
#define UART1_TX_PIN            PA9
#define UART1_RX_PIN            PA10

#define USE_UART2
#define UART2_TX_PIN            PA2
#define UART2_RX_PIN            PA3

#define USE_UART3
#define UART3_TX_PIN            PC10
#define UART3_RX_PIN            PC11

#define USE_UART4
#define UART4_TX_PIN            PA0
#define UART4_RX_PIN            PA1

#define USE_UART5
#define UART5_TX_PIN            PC12
#define UART5_RX_PIN            PD2

#define USE_UART6
#define UART6_TX_PIN            PC6
#define UART6_RX_PIN            PC7

#define USE_MOTOR

#define MOTOR1_PIN              PB6
#define MOTOR2_PIN              PB7
#define MOTOR3_PIN              PB8
#define MOTOR4_PIN              PB9

#define MOTOR_PWM_PROTOCOL_DEFAULT DSHOT600

#define USE_BEEPER
#define BEEPER_PIN              PC5

#define USE_LED_STRIP
#define LED_STRIP_PIN           PC9

#define USE_ADC
#define ADC_BATT_PIN            PC0
#define ADC_RSSI_PIN            PC2
#define ADC_CURR_PIN            PC1

#define USE_PINIO
#define PINIO1_PIN              PB5

#define USE_EXTI
#define USE_ESCSERIAL
#define USE_DSHOT
#define USE_DSHOT_BITBANG
#define USE_USB_DETECT


#define TARGET_IO_PORTA 0xffff
#define TARGET_IO_PORTB 0xffff
#define TARGET_IO_PORTC 0xffff
#define TARGET_IO_PORTD 0xffff

#define FLASH_PAGE_SIZE ((uint32_t)0x4000)
#define USE_DSHOT_BITBANG_TELEMETRY
#define USE_DSHOT_BITBANG_SHARED
#undef USE_LEGACY_DSHOT_BITBANG

