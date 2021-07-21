#include "ard_APA102.h"

#define charSpacing 1
#define symbolWidth 8

void solidSquare(CRGB borderColor){
  for(int i = 1; i< symbolWidth-1;i++){
    for (int j = 1; j< symbolWidth-1;j++){
      leds[XY(i,j)]= borderColor;
    }
  }
}

void arrow(CRGB color){

}

void rollingBorder(CRGB borderColor){
  static byte borderBuffer[symbolWidth] = {1,0,0,0,0,0,0,0};
  static byte borderBufferPointer = 0;

// 
  //int currentPosition = borderBuffer[borderBufferPointer];
  for(int i = 0; i < symbolWidth;i++){
    leds[XY(i,0)] = borderColor;
    leds[XY(7,i)] = borderColor;
    leds[XY(7-i,7)] = borderColor;
    leds[XY(0,7-i)] = borderColor;
    //FastLED.delay(200);
    FastLED.show();
  }
  for(int i = 1; i < symbolWidth-1;i++){
    leds[XY(i,0)] = CRGB::Black;
    leds[XY(7,i)] = CRGB::Black;
    leds[XY(7-i,7)] = CRGB::Black;
    leds[XY(0,7-i)] = CRGB::Black;
    //FastLED.delay(200);
    FastLED.show();
  }
  borderBufferPointer= (borderBufferPointer+1) %symbolWidth;
}

void staticText(byte message, CRGB fgColor, CRGB bgColor){
  static byte currentMessageChar = 0;
  static byte currentCharColumn = 0;
  static CRGB currentColor;
  static byte bitBuffer[kMatrixWidth] = {0}; // 
  //static byte bitBufferPointer = 0; // points to column to render

  currentMessageChar = 0;
  currentCharColumn = 0;
  selectFlashString(message);
  loadCharBuffer(loadStringChar(message,currentMessageChar));
  for(byte i= 0; i < kMatrixWidth; i++) bitBuffer[i] = 0; 

  CRGB pixelColor;
  for (byte x = 8; x < kMatrixWidth; x++){
    if (currentCharColumn > (4+charSpacing)){
      currentCharColumn = 0;
      currentMessageChar++;
      char nextChar= loadStringChar(message,currentMessageChar);
      if (nextChar ==0){ // null char at end of string
        currentMessageChar = 0;
        nextChar = loadStringChar(message,currentMessageChar);
      }
      loadCharBuffer(nextChar);
    }
    for(byte y =0; y < kMatrixHeight;y++){
        if(bitRead(bitBuffer[x % kMatrixWidth],y) == 1){
          pixelColor = fgColor;
        }
        else pixelColor = bgColor;
        // Update CRGB struct leds
        leds[XY(x,y)] = pixelColor; 
    }
  }
}



// Scroll a text string
int scrollText(byte message, CRGB fgColor, CRGB bgColor) {
  static byte currentMessageChar = 0;
  static byte currentCharColumn = 0;
  static CRGB currentColor;
  static byte bitBuffer[kMatrixWidth] = {0}; // 
  static byte bitBufferPointer = 0; // points to column to render
  
  if (bitBufferPointer >= 24) {
    return 0;
  }


  currentMessageChar = 0;
  currentCharColumn = 0;
  selectFlashString(message);
  loadCharBuffer(loadStringChar(message, currentMessageChar));
  for (byte i = 0; i < kMatrixWidth; i++) bitBuffer[i] = 0; 

  if (currentCharColumn < 5) { // characters are 5 pixels wide
    bitBuffer[(bitBufferPointer + kMatrixWidth - 1) % kMatrixWidth] = charBuffer[currentCharColumn]; // character
  } else {
    bitBuffer[(bitBufferPointer + kMatrixWidth - 1) % kMatrixWidth] = 0; // space
  }

  CRGB pixelColor;
  for (byte x = 8; x < kMatrixWidth; x++) {
    for (byte y = 0; y < kMatrixHeight; y++) { // characters are 5 pixels tall
      if (bitRead(bitBuffer[(bitBufferPointer + x) % kMatrixWidth], y) == 1) {
          pixelColor = fgColor;
      }
      else 
      {
        pixelColor = bgColor;
      }
      leds[XY(x, y)] = pixelColor;
    }
  }

  currentCharColumn++;
  if (currentCharColumn > (4 + charSpacing)) {
    currentCharColumn = 0;
    currentMessageChar++;
    char nextChar = loadStringChar(message, currentMessageChar);
    if (nextChar == 0) { // null character at end of strong
      currentMessageChar = 0;
      nextChar = loadStringChar(message, currentMessageChar);
    }
    loadCharBuffer(nextChar);
  }

  bitBufferPointer++;
  

}


void scrollTextZero() {
  scrollText(0, CRGB::DarkOrange, CRGB::Black);
}

void scrollTextOne() {
  scrollText(1, CRGB::Amethyst, CRGB::Black);
}