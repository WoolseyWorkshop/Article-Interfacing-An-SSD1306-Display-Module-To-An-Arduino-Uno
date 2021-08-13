// DisplayGraphics - DisplayGraphics.ino
//
// Description:
// Prints text and graphics to an SSD1306 display module using the U8g2 graphics
// library.
//
// Created by John Woolsey on 06/23/2018.
// Modified by John Woolsey on 08/13/2021.
// Copyright (c) 2018 Woolsey Workshop.  All rights reserved.


#include <Arduino.h>
#include <U8g2lib.h>
#ifdef U8X8_HAVE_HW_SPI
#include <SPI.h>
#endif
#ifdef U8X8_HAVE_HW_I2C
#include <Wire.h>
#endif


#define DISPLAY_I2C_ADDRESS 0x3C


// U8g2 graphics library constructor for SunFounder OLED SSD1306 Display Module
// Use the constructor compatible with your display module.
// See https://github.com/olikraus/u8g2/wiki/u8g2setupcpp for constructor list.
// 128x64 display with hardware I2C, no mirroring or rotation, and no reset pin
U8G2_SSD1306_128X64_NONAME_1_HW_I2C display(/* rotation/mirror = */ U8G2_R0);


// Draws LED schematic symbol with size of 60x24
void drawLED(int centerX, int centerY) {
   display.drawTriangle(centerX - 10, centerY + 12, centerX + 10, centerY + 2, centerX - 10, centerY - 8);
   display.drawLine(centerX + 10, centerY - 8, centerX + 10, centerY + 12);
   display.drawLine(centerX - 30, centerY + 2, centerX - 10, centerY + 2);
   display.drawLine(centerX + 10, centerY + 2, centerX + 30, centerY + 2);
   display.drawLine(centerX, centerY - 6, centerX + 3, centerY - 10);
   display.drawTriangle(centerX + 6, centerY - 12, centerX + 6, centerY - 8, centerX + 2, centerY - 12);
   display.drawLine(centerX - 22, centerY + 8, centerX - 18, centerY + 8);
   display.drawLine(centerX - 20, centerY + 6, centerX - 20, centerY + 10);
   display.drawLine(centerX + 18, centerY + 8, centerX + 22, centerY + 8);
}


void setup() {
   display.setI2CAddress(DISPLAY_I2C_ADDRESS * 2);  // required if display does not use default address of 0x3C
   display.begin();  // initialize U8g2 graphics library for selected display module
}


void loop() {
   int displayWidth = display.getDisplayWidth();  // width of display
   int displayHeight = display.getDisplayHeight();  // height of display
   display.firstPage();  // enable display rendering using page buffering
   do {
      // Draw text
      display.setFont(u8g2_font_ncenB10_tr);  // set text font (11 pixel height)
      display.drawStr((displayWidth - display.getStrWidth("Woolsey")) / 2, 11, "Woolsey");  // center text at top of screen
      display.drawStr((displayWidth - display.getStrWidth("Workshop")) / 2, 61, "Workshop");  // center text at bottom of screen

      // Draw LED symbol
      drawLED(displayWidth / 2, (displayHeight / 2) - 2);  // place symbol in middle of screen (between text)
   } while (display.nextPage());  // render current page
   delay(2000);  // update screen every 2 seconds
}
