
#include <SPI.h>

#include "src/drivers/display.h"
#include "util/util_debugpins.h" 
#include "util/util_misc.h" 
#include "OC_DAC.h"

void setup() {
  delay(10);
  SPI.begin();
  SPI_init();
  delay(500);

  display::Init();

  GRAPHICS_BEGIN_FRAME(true);

  graphics.print("Hello World");

  GRAPHICS_END_FRAME();

}

/*  ---------    main loop  --------  */

void FASTRUN loop() {

  while (true) {
  }
}
