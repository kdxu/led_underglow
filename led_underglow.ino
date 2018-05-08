#include <Adafruit_NeoPixel.h>
#define MAX_VAL 30  
#define DELAY_TIME 50
 
Adafruit_NeoPixel strip = Adafruit_NeoPixel(60, 6, NEO_GRB + NEO_KHZ800);
 
void setup() {
  strip.begin();
  strip.show(); 
}
 
void loop() {
  rainbowCycle(DELAY_TIME);
}
 
 
// Slightly different, this makes the rainbow equally distributed throughout
void rainbowCycle(uint8_t wait) {
  uint16_t i, j;
 
  for(j=0; j<256*5; j++) { // 5 cycles of all colors on wheel
    for(i=0; i< strip.numPixels(); i++) {
      strip.setPixelColor(i, Wheel(((i * 256 / strip.numPixels()) + j) & 255));
    }
    strip.show();
    delay(wait);
  }
}
 
// Input a value 0 to 255 to get a color value.
// The colours are a transition r - g - b - back to r.
uint32_t Wheel(byte WheelPos) {
  if(WheelPos < 85) {
   return strip.Color((WheelPos * 3)*MAX_VAL/255, (255 - WheelPos * 3)*MAX_VAL/255, 0);
  } else if(WheelPos < 170) {
   WheelPos -= 85;
   return strip.Color((255 - WheelPos * 3)*MAX_VAL/255, 0, (WheelPos * 3)*MAX_VAL/255);
  } else {
   WheelPos -= 170;
   return strip.Color(0, (WheelPos * 3)*MAX_VAL/255, (255 - WheelPos * 3)*MAX_VAL/255);
  }
}

