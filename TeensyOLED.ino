/*********************************************************************
~ TeensyOLED test ~
  Version 0.1

_____________________________
OLED connections

OLED MOSI0 on pin 11
OLED SCK0 on pin 13
OLED_DC on pin 6 //32
OLED_RST on pin 7 //33
OLED_CS on pin 8 //34
_____________________________

*/
#include <U8g2lib.h>
#include <U8x8lib.h>
#include <Arduino.h>

#ifdef U8X8_HAVE_HW_SPI
#include <SPI.h>
#endif
#ifdef U8X8_HAVE_HW_I2C
#include <Wire.h>
#endif

const int ledPin = 13;

// MOST IMPORTANT UG82 LINE OF CODE HERE
// declaring pinout via a "constructor" for Teensy 3.5/6 for U8g2lib.h OLED library

//U8G2_SH1106_128X64_NONAME_F_4W_SW_SPI u8g2(U8G2_R0, /* clock=*/ 13, /* data=*/ 11, /* cs=*/ 34, /* dc=*/ 32, /* reset=*/ 33);  
U8G2_SSD1306_128X64_NONAME_F_4W_SW_SPI u8g2(U8G2_R0, /* clock=*/ 13, /* data=*/ 11, /* cs=*/ 34, /* dc=*/ 32, /* reset=*/ 33);  



void setup(void) {

  // initialize the digital pin as an output.
  pinMode(ledPin, OUTPUT);
  
  delay(10);

  digitalWrite(ledPin, HIGH);    // set the LED off
  
  SPI.begin();
  delay(500);
  digitalWrite(ledPin, LOW);    // set the LED off
  
  u8g2.begin();
  u8g2.enableUTF8Print();
  u8g2.setFont(u8g2_font_helvB14_tf); // choose a suitable font
  u8g2.drawStr(1,20,"TeensyOLED");  // write something to the internal memory

  u8g2.setFont(u8g2_font_baby_tf); // choose a suitable font
  u8g2.drawStr(103,7,"v 0.1");  // write something to the internal memory
  
  u8g2.setFont(u8g2_font_9x15_tf); // choose a suitable font
  u8g2.drawStr(4,40,"Hello World");  // write something to the internal memory
  
  u8g2.sendBuffer();          // transfer internal memory to the display
  delay(5000);
  u8g2.clearBuffer();
  
}

void loop(void) {
  digitalWrite(ledPin, LOW);    // set the LED off
  u8g2.setFont(u8g2_font_helvB14_tf); // choose a suitable font
  u8g2.drawStr(1,20,"TeensyOLED"); 
  u8g2.setFont(u8g2_font_baby_tf); // choose a suitable font
  u8g2.drawStr(103,7,"v 0.1");  // write something to the internal memory 
  u8g2.setFont(u8g2_font_9x15_tf); // choose a suitable font
  u8g2.drawStr(4,40,"Hello World"); 
  u8g2.sendBuffer();          // transfer internal memory to the display
  delay(2000);
  u8g2.clearBuffer();
}

