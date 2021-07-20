// Assorted useful functions and variables
#include "ard_WS.h"

// Global variables
boolean effectInit = false; // indicates if a pattern has been recently switched
uint16_t effectDelay = 0; // time between automatic effect changes
unsigned long effectMillis = 0; // store the time of last effect function run
unsigned long cycleMillis = 0; // store the time of last effect change
unsigned long currentMillis; // store current loop's millis value
byte currentEffect = 0;
boolean autoCycle = true; //flag for autmatic effect changes
// Set every LED in the array to a specified color

typedef void (*functionList)();
extern const byte numEffects;



void fillAll(CRGB fillColor) {
  for (byte i = 0; i < NUM_LEDS; i++) {
    leds0[i] = fillColor;
    leds1[i] = fillColor;
  }
}

// Fade every LED in the array by a specified amount
void fadeAll(byte fadeIncr) {
  for (byte i = 64; i < NUM_LEDS; i++) {
    leds0[i] = leds0[i].fadeToBlackBy(fadeIncr);
    leds1[i] = leds1[i].fadeToBlackBy(fadeIncr);
  }
}
byte scrollX = 0;
void shift_left_border(){
    for(int i=0;i<20;i++){  
        leds0[i-2].setRGB(0,0,0);
        leds0[i].setRGB(255,255,0);
        FastLED.show();
    }
}
// Shift all pixels by one, right or left (0 or 1)
void scrollArray(byte scrollDir) {
  
    byte scrollX = 0;
    for (byte x = 1; x < kMatrixWidth; x++) {
      if (scrollDir == 0) {
        scrollX = kMatrixWidth - x;
      } else if (scrollDir == 1) {
        scrollX = x - 1;
      }
      
      for (byte y = 0; y < kMatrixHeight; y++) {
        leds0[XY(scrollX,y)] = leds0[XY(scrollX + scrollDir*2 - 1,y)];
        leds1[XY(scrollX,y)] = leds0[XY(scrollX + scrollDir*2 - 1,y)];
      }
    }
  
}
// Determine flash address of text string
unsigned int currentStringAddress = 0;
void selectFlashString(byte string) {
  currentStringAddress = pgm_read_word(&stringArray[string]);
}

// Fetch font character bitmap from flash
byte charBuffer[5] = {0};
void loadCharBuffer(byte character) {
  byte mappedCharacter = character;
  if (mappedCharacter >= 32 && mappedCharacter <= 95) {
    mappedCharacter -= 32; // subtract font array offset
  } else if (mappedCharacter >= 97 && mappedCharacter <= 122) {
    mappedCharacter -= 64; // subtract font array offset and convert lowercase to uppercase
  } else {
    mappedCharacter = 96; // unknown character block
  }
  
  for (byte i = 0; i < 5; i++) {
    charBuffer[i] = pgm_read_byte(Font[mappedCharacter]+i);
  }
  
}
// Fetch a character value from a text string in flash
char loadStringChar(byte string, byte character) {
  return (char) pgm_read_byte(currentStringAddress + character);
}
