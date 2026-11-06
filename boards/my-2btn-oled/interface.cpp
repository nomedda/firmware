#include "core/display.h"
#include "core/powerSave.h"
#include "core/utils.h"
#include <interface.h>

#define LONG_PRESS_MS 700

void _setup_gpio() {
    pinMode(4, INPUT_PULLUP); // Left / Esc
    pinMode(5, INPUT_PULLUP); // Right / Select

    pinMode(10, OUTPUT);      // CC1101 CS
    digitalWrite(10, HIGH);
}

int getBattery() { return 0; }
bool isCharging() { return false; }
void _setBrightness(uint8_t brightval) { (void)brightval; }

void InputHandler(void) {
    static unsigned long pressStart4 = 0;
    static unsigned long pressStart5 = 0;
    static bool long4 = false;
    static bool long5 = false;
    static bool was4 = false;
    static bool was5 = false;

    const uint32_t now = millis();

    bool btn4 = digitalRead(4) == LOW;
    bool btn5 = digitalRead(5) == LOW;

    // ----- GPIO 4 -----
    if (btn4 && !was4) {
        pressStart4 = now;
        long4 = false;
    }
    if (btn4 && !long4 && (now - pressStart4 > LONG_PRESS_MS)) {
        long4 = true;
        if (!wakeUpScreen()) {
            AnyKeyPress = true;
            EscPress = true;              // долгое = Esc
        }
    }
    if (!btn4 && was4 && !long4) {
        if (!wakeUpScreen()) {
            AnyKeyPress = true;
            PrevPress = true;             // короткое = Влево (меню)
            UpPress = true;               // в подменю = Вверх
            PrevPagePress = true;
        }
    }
    was4 = btn4;

    // ----- GPIO 5 -----
    if (btn5 && !was5) {
        pressStart5 = now;
        long5 = false;
    }
    if (btn5 && !long5 && (now - pressStart5 > LONG_PRESS_MS)) {
        long5 = true;
        if (!wakeUpScreen()) {
            AnyKeyPress = true;
            SelPress = true;              // долгое = Select
        }
    }
    if (!btn5 && was5 && !long5) {
        if (!wakeUpScreen()) {
            AnyKeyPress = true;
            NextPress = true;             // короткое = Вправо (меню)
            DownPress = true;             // в подменю = Вниз
            NextPagePress = true;
        }
    }
    was5 = btn5;
}

void powerOff() {}
void checkReboot() {}
