#pragma once

#ifndef TARGET_BOARD_IDENTIFIER
#define TARGET_BOARD_IDENTIFIER "VYRI"
#endif

#ifndef USBD_PRODUCT_STRING
#define USBD_PRODUCT_STRING     "Betaflight - VYRIY4V4"
#endif

#ifndef STM32F405
#define STM32F405
#endif

#define USE_I2C_DEVICE_1
#define USE_I2C_DEVICE_2
#define USE_I2C_DEVICE_3
#define USE_VCP
#define USE_UART1
#define USE_UART2
#define USE_UART3
#define USE_UART4
#define USE_UART5
#define USE_UART6
#define USE_INVERTER

#define USE_SPI_DEVICE_1
#define USE_SPI_DEVICE_2
#define USE_SPI_DEVICE_3

#define TARGET_IO_PORTA 0xffff
#define TARGET_IO_PORTB 0xffff
#define TARGET_IO_PORTC 0xffff
#define TARGET_IO_PORTD 0xffff
#define TARGET_IO_PORTE 0xffff
#define TARGET_IO_PORTF 0xffff

#define USE_I2C
#define I2C_FULL_RECONFIGURABILITY

#define USE_BEEPER
#define USE_LED

#define USE_SPI
#define SPI_FULL_RECONFIGURABILITY
#define USE_SPI_DMA_ENABLE_EARLY

#define USE_ADC
#define USE_EXTI

#define USE_CUSTOM_DEFAULTS
#define CUSTOM_CLI_SETTINGS_OFFSET 0

#define USE_PINIO
#define USE_PINIOBOX
#define USE_DSHOT_BITBAND
#define FLASH_PAGE_SIZE ((uint32_t)0x4000) // 16K sectors
