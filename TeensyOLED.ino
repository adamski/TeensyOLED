/*********************************************************************
~ TeensyOLED test ~
  Version 0.2

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
//U8G2_SSD1306_128X64_NONAME_F_4W_SW_SPI u8g2(U8G2_R0, /* clock=*/ 13, /* data=*/ 11, /* cs=*/ 34, /* dc=*/ 32, /* reset=*/ 33);  
U8G2_SSD1306_128X64_NONAME_F_4W_HW_SPI u8g2(U8G2_R0, /* cs=*/ 34, /* dc=*/ 32, /* reset=*/ 33);  


u8g2_uint_t x, y, xMax, yMax;
u8g2_uint_t rad;
int xDirection, yDirection;
const char* versionString = "v 0.2";
const float dt = 1.0f / 60;

const float acceleration = 9.8f;
float xVelocity, xPosition;
float yVelocity, yPosition;


void setup(void) {

  xVelocity = 16;
  xPosition = 10;
  yVelocity = yPosition = 0;
  x = y = 0;
  xMax = 127; //u8g2.getDisplayWidth();
  yMax = 63; //u8g2.getDisplayHeight();
  rad = 5;

  xDirection = 1;
  yDirection = 1;
  
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
  u8g2.drawStr(103,7,versionString);  // write something to the internal memory
  
  u8g2.setFont(u8g2_font_9x15_tf); // choose a suitable font
  u8g2.drawStr(4,40,"Hello World");  // write something to the internal memory
  
  u8g2.sendBuffer();          // transfer internal memory to the display
  delay(2000);
  u8g2.clearBuffer();
  digitalWrite(ledPin, LOW); 
  
}

void loop() {
    
  u8g2.drawDisc(x, y, rad, U8G2_DRAW_ALL);     // transfer internal memory to the display
  u8g2.sendBuffer();
  //delay(1);

  if (xDirection == 1 && x + rad + xDirection > xMax)
    xDirection = -1;
  else if (xDirection == -1 && x - rad - xDirection < 0)
    xDirection = 1;

  if (yDirection == 1 && y + rad + yDirection > yMax)
    yDirection = -1;
  else if (yDirection == -1 && y - rad - yDirection < 0)
    yDirection = 1;

  yVelocity += acceleration * dt;
  yPosition += yVelocity * dt;

  //x += xDirection;
  //y += yDirection;
  y = int(yPosition + 0.5);

  if (y >= yMax - rad)
    yVelocity = -32;

  xVelocity += 0.9f * dt;
  xPosition += xVelocity * dt;

  x = int(xPosition + 0.5);

  if (x == xMax - rad || x == rad)
    xVelocity = -xVelocity;
  

  u8g2.clearBuffer();
}
