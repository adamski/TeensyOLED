// Copyright (c) 2015, 2016 Max Stadler, Patrick Dowling
//
// Original Author : Max Stadler
// Heavily modified: Patrick Dowling (pld@gurkenkiste.com)
//
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in all
// copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
// SOFTWARE.

// Main startup/loop for PSQ firmware

//#include <ADC.h>
//#include <EEPROM.h>

#include "src/drivers/display.h"
#include "util/util_debugpins.h" 
#include "util/util_misc.h" 
#include "OC_DAC.h"

/* unsigned long LAST_REDRAW_TIME = 0; */
/* uint_fast8_t MENU_REDRAW = true; */
/* OC::UiMode ui_mode = OC::UI_MODE_MENU; */

/*  --------------------- UI timer ISR -------------------------   */

IntervalTimer UI_timer;

/* void FASTRUN UI_timer_ISR() { */
/*   OC_DEBUG_PROFILE_SCOPE(OC::DEBUG::UI_cycles); */
/*   OC::ui.Poll(); */
/*  */
/*   OC_DEBUG_RESET_CYCLES(OC::ui.ticks(), 2048, OC::DEBUG::UI_cycles); */
/* } */

void setup() {
  delay(10);
  SPI_init();
  delay(500);
  //SERIAL_PRINTLN("* PSQ BOOTING...");
  /* SERIAL_PRINTLN("* %s", OC_VERSION); */

  display::Init();

  GRAPHICS_BEGIN_FRAME(true);

  graphics.print("Hello World");

  GRAPHICS_END_FRAME();

  /* SERIAL_PRINTLN("* Starting CORE ISR @%luus", OC_CORE_TIMER_RATE); */
  /*  */
  /* // Display splash screen and optional calibration */
  /* bool reset_settings = false; */
  /* ui_mode = OC::ui.Splashscreen(reset_settings); */
  /*  */
  /* if (ui_mode == OC::UI_MODE_CALIBRATE) { */
  /*   OC::ui.Calibrate(); */
  /*   ui_mode = OC::UI_MODE_MENU; */
  /* } */
  /* OC::ui.set_screensaver_timeout(OC::calibration_data.screensaver_timeout); */
  /*  */
  /* // initialize apps */
  /* OC::apps::Init(reset_settings); */
}

/*  ---------    main loop  --------  */

void FASTRUN loop() {

  while (true) {
  }
}
