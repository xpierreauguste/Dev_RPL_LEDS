#include "ard_WS.h"


#define FASTLED_INTERNAL //Get rid of version message
// RGB Shades data output to LEDs is on pin 5
#define LED_PIN0  3
#define LED_PIN1  4
// RGB Shades color order (Green/Red/Blue)
#define COLOR_ORDER GRB
#define CHIPSET     WS2812

// Global maximum brightness value, maximum 255
#define MAXBRIGHTNESS 30
#define STARTBRIGHTNESS 20

// Cycle time (milliseconds between pattern changes)
#define cycleTime 15000

#include "messages.h"
#include "font.h"
#include "XYmap.h"
#include "utils.h"
#include "effects.h"

// Declare Constants 
functionList effectList[] = {
                             scrollTextZero,
                             scrollTextOne
                            };

const byte numEffects = (sizeof(effectList)/sizeof(effectList[0]));
String command;

void setup() {

  if (currentEffect > (numEffects - 1)) currentEffect = 0;
  // Write FastLED config data 
  FastLED.addLeds<CHIPSET, LED_PIN0, COLOR_ORDER>(leds0, LAST_VISIBLE_LED+1);
  FastLED.addLeds<CHIPSET, LED_PIN1, COLOR_ORDER>(leds1, LAST_VISIBLE_LED+1);
  FastLED.setBrightness(30); 
  solidSquare(CRGB::Green);
}

void loop() {

  currentMillis = millis(); // save current timer value
    // switch to a new effect every cycleTime milliseconds
  if (currentMillis - cycleMillis > cycleTime && autoCycle == true) {
    cycleMillis = currentMillis;
    
    if (++currentEffect >= numEffects) currentEffect = 0; // loop to start of effect list
    effectInit = false; // trigger effect initialization when new effect is selected
    
  }
  // run the currently selected effect every effectDelay milliseconds
  if (currentMillis - effectMillis > effectDelay) {
    effectMillis = currentMillis;
    scrollTextZero();
  }

  /* -------------Receive Command-------------- */
  
  
  
  /* -------------Display Border--------------- */
  //revolvingPixel(CRGB::Bisque);
  //rollingBorder(CRGB::DimGrey);
  //staticBorder(CRGB::Green);

  /* -------------Display Symbol--------------- */
  solidSquare(CRGB::DarkGreen);

  /* -------------Display Text---------------- */
  // 

  FastLED.show();
  // Delay until next update
  //FastLED.delay(100);
  //FastLED.show();

}

