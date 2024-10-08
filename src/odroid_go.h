#ifndef _ODROID_GO_H_
#define _ODROID_GO_H_

#if defined(ESP32)

#include <Arduino.h>
#include <SPI.h>
#include "utility/Config.h"

#include "utility/Display.h"
#include "utility/Button.h"
// #include "utility/Speaker.h"
// #include "utility/battery.h"

extern "C" {
#include "esp_sleep.h"
}

class ODROID_GO {

 public:
    void begin(unsigned long baud = 115200);
    void update();
    uint8_t checkButtons();

    #define DEBOUNCE_MS 5
    Button JOY_Y = Button(BUTTON_JOY_Y, true, DEBOUNCE_MS);
    Button JOY_X = Button(BUTTON_JOY_X, true, DEBOUNCE_MS);
    Button BtnA = Button(BUTTON_A_PIN, true, DEBOUNCE_MS);
    Button BtnB = Button(BUTTON_B_PIN, true, DEBOUNCE_MS);
    Button BtnMenu = Button(BUTTON_MENU, true, DEBOUNCE_MS);
    Button BtnVolume = Button(BUTTON_VOLUME, true, DEBOUNCE_MS);
    Button BtnSelect = Button(BUTTON_SELECT, true, DEBOUNCE_MS);
    Button BtnStart = Button(BUTTON_START, true, DEBOUNCE_MS);

    ILI9341 lcd = ILI9341();
    // SPEAKER Speaker;
    // Battery battery;

    void command( const uint8_t *data, size_t len);

/*

    setTextFont( u8)    'f':d1
    setTextSize( u8)    's':d1
    setTextColor( u16)  'c':d2

    setCursor(i16,i16)  'p':d4(d2,d2)
    fillRect( i32,i32,i32,i32,u32) 'fill':d20 (d4,d4,d4,d4,d4 )

    drawPixel( u32 x, u32 y, u32color)

    print("String")

    pub_str_ch
    cmd:
    chLen:
    chStr:
    data:

    // sender

    pub #gocmd  payload



*/
};

extern ODROID_GO GO;
#define go GO

#else
#error "This library only supports boards with ESP32 processor."
#endif

#endif
