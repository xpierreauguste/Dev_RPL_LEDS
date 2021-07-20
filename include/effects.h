//   Each function should have the following components:
//    * Must be declared void with no parameters or will break function pointer array
//    * Check effectInit, if false then init any required settings and set effectInit true
//    * Set effectDelay (the time in milliseconds until the next run of this effect)
//    * All animation should be controlled with counters and effectDelay, no delay() or loops
//    * Pixel data should be written using leds[XY(x,y)] to map coordinates to the RGB Shades layout
#include "ard_WS.h"
#define textCanvas 24
#define NORMAL 0
#define charSpacing 1




void rollingBorder(CRGB borderColor){
  static byte borderBuffer[symbolWidth] = {1,0,0,0,0,0,0,0};
  static byte borderBufferPointer = 0;

// 
  //int currentPosition = borderBuffer[borderBufferPointer];
  for(int i = 0; i < symbolWidth;i++){
    leds0[XY(i,0)] = borderColor;
    leds0[XY(7,i)] = borderColor;
    leds0[XY(7-i,7)] = borderColor;
    leds0[XY(0,7-i)] = borderColor;
    //FastLED.delay(200);
    FastLED.show();
  }
  for(int i = 1; i < symbolWidth-1;i++){
    leds0[XY(i,0)] = CRGB::Black;
    leds0[XY(7,i)] = CRGB::Black;
    leds0[XY(7-i,7)] = CRGB::Black;
    leds0[XY(0,7-i)] = CRGB::Black;
    //FastLED.delay(200);
    FastLED.show();
  }
  borderBufferPointer= (borderBufferPointer+1) %symbolWidth;
}

void solidSquare(CRGB borderColor){
  for(int i = 1; i< symbolWidth-1;i++){
    for (int j = 1; j< symbolWidth-1;j++){
      leds0[XY(i,j)]= borderColor;
      leds1[XY(i,j)]= borderColor;
    }
  }
  //FastLED.show();
} 

void staticBorder(CRGB borderColor){
  for (int i = 0; i<symbolWidth;i++){
    leds0[XY(i,0)] = borderColor;
  }
  for (int i = 0; i<symbolWidth;i++){
    leds0[XY(7,i)] = borderColor;
  }
  for (int i = 0; i<symbolWidth;i++){
    leds0[XY(7-i,7)] = borderColor;
  }
  for (int i = 0; i<symbolWidth;i++){
    leds0[XY(0,7-i)] = borderColor;
  }
  FastLED.show();
}


int xx =0;
int yy =0;
void revolvingPixel(CRGB color){
  if((xx==0) && (yy==0)){
    for(int i=0; i<symbolWidth;i++){
      leds0[XY(i-1,0)].setRGB(0,0,0);
      leds0[XY(i,0)]= color;
      leds1[XY(i-1,0)].setRGB(0,0,0);
      leds1[XY(i,0)]= color;
      FastLED.show();
    }
    xx = 7;
  }
  else if( (xx==7) && (yy==0)){
    for(int j=0; j<symbolWidth;j++){
      leds0[XY(7,j-1)].setRGB(0,0,0);
      leds0[XY(7,j)]= color;
      leds1[XY(7,j-1)].setRGB(0,0,0);
      leds1[XY(7,j)]= color;
      FastLED.show();
    }
    yy = 7;
  }
  else if( (xx==7) && (yy==7)){
    for(int j=0; j<symbolWidth;j++){
      leds0[XY(7-(j-1),7)].setRGB(0,0,0);
      leds0[XY(7-j,7)]= color;
      leds1[XY(7-(j-1),7)].setRGB(0,0,0);
      leds1[XY(7-j,7)]= color;
      FastLED.show();
    }
    xx = 0;
  }
  else if( (xx==0) && (yy==7)){
    for(int j=0; j<symbolWidth;j++){
      leds0[XY(0,7-(j-1))].setRGB(0,0,0);
      leds0[XY(0,7-j)]= color;
      leds1[XY(0,7-(j-1))].setRGB(0,0,0);
      leds1[XY(0,7-j)]= color;
      FastLED.show();
    }
    yy = 0;
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

  if(effectInit == false){
    effectInit = true;
    effectDelay = 35;
    currentMessageChar = 0;
    currentCharColumn = 0;
    selectFlashString(message);
    loadCharBuffer(loadStringChar(message, currentMessageChar));
    for (byte i = 0; i < kMatrixWidth; i++) bitBuffer[i] = 0; 
  }

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
          //leds0[XY(x, y)] = leds0[XY(x, y)].setRGB(255,170,0);
          //leds1[XY(x, y)] = leds0[XY(x, y)].setRGB(255,170,0);
      }
      else 
      {
        pixelColor = bgColor;
        //leds0[XY(x, y)] = leds0[XY(x, y)].setRGB(0,0,0);
        //leds1[XY(x, y)] = leds1[XY(x, y)].setRGB(0,0,0);
      }
      leds0[XY(x, y)] = pixelColor;
      leds1[XY(x, y)] = pixelColor;
    }
//.setRGB(255,170,0)
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