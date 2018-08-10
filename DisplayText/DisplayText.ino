// DisplayText - DisplayText.ino
//
// Description:
// Prints text to an SSD1306 display module using the U8x8 text library.
//
// Created by John Woolsey on 06/23/2018.
// Copyright © 2018 Woolsey Workshop.  All rights reserved.


#include <Arduino.h>
#include <U8x8lib.h>
#ifdef U8X8_HAVE_HW_SPI
#include <SPI.h>
#endif
#ifdef U8X8_HAVE_HW_I2C
#include <Wire.h>
#endif


// U8x8 text library constructor for SunFounder OLED SSD1306 Display Module.
// Use the constructor compatible with your display module.
// See https://github.com/olikraus/u8g2/wiki/u8x8setupcpp for constructor list.
// 128x64 display with hardware I2C and no reset pin
U8X8_SSD1306_128X64_NONAME_HW_I2C display(/* reset = */ U8X8_PIN_NONE);


void setup(void) {
   display.begin();  // initialize U8x8 text library for selected display module
}


void loop(void) {
   display.setFont(u8x8_font_victoriabold8_r);  // set text font (8x8 pixels)
   display.drawString(0, 0, "Hello, Arduino!");  // print text to screen (column 0, row 0)
   delay(2000);  // update screen every 2 seconds
}
