#ifndef Pins_Arduino_h
#define Pins_Arduino_h

#include "soc/soc_caps.h"
#include <stdint.h>

// ── USB ──────────────────────────────────────────────────────────
#define USB_VID 0x303A
#define USB_PID 0x1001
#define USB_as_HID 1

// ── UART0 (debug) ────────────────────────────────────────────────
static const uint8_t TX = 43;
static const uint8_t RX = 44;
#define SERIAL_TX 43
#define SERIAL_RX 44

// ── I2C (на всякий случай) ───────────────────────────────────────
#define GROVE_SDA 8
#define GROVE_SCL 18
static const uint8_t SDA = GROVE_SDA;
static const uint8_t SCL = GROVE_SCL;

// ── SPI для OLED (отдельная шина) ────────────────────────────────
#define TFT_SCLK  14
#define TFT_MOSI  15
#define TFT_MISO  -1
#define TFT_DC    17
#define TFT_CS    18
#define TFT_RST   16
#define TFT_BL    -1
#define TFT_WIDTH  128
#define TFT_HEIGHT 64

// ── SPI для CC1101 ───────────────────────────────────────────────
#define SPI_MOSI_PIN 12
#define SPI_SCK_PIN  13
#define SPI_MISO_PIN 11
#define SPI_SS_PIN   10
static const uint8_t MOSI = SPI_MOSI_PIN;
static const uint8_t MISO = SPI_MISO_PIN;
static const uint8_t SCK  = SPI_SCK_PIN;
static const uint8_t SS   = SPI_SS_PIN;

// ── CC1101 ───────────────────────────────────────────────────────
#define USE_CC1101_VIA_SPI
#define CC1101_GDO0_PIN  9
#define CC1101_SS_PIN    10
#define CC1101_MOSI_PIN  12
#define CC1101_SCK_PIN   13
#define CC1101_MISO_PIN  11

// ── Кнопки ───────────────────────────────────────────────────────
#define BTN_UP    4
#define BTN_DOWN  5
#define UP_BTN    4
#define DW_BTN    5
#define SEL_BTN   5
#define BTN_ACT   LOW

// ── Экран ────────────────────────────────────────────────────────
#define HAS_SCREEN 1
#define ROTATION   0
#define MINBRIGHT  0
#define BACKLIGHT  -1

#define DEVICE_NAME "\"My2BtnOLED\""

#endif
