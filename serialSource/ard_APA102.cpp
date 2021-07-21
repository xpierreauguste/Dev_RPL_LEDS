// Includes 
#include <Arduino.h>
#include <FastLED.h>

// Define Constants 
#define CLK_PIN 5
#define DATA_PIN 10
#define COLOR_ORDER     BGR
#define CHIPSET         APA102
#define NUM_LEDS 256
CRGB leds[NUM_LEDS]; // struct: value type stack

// Local headers

#include "messages.h"
#include "font.h"
#include "XYmap.h"
#include "utils.h"
#include "effects.h"
#include "serial.h"



void setup(){
    Serial.begin(9600);
    FastLED.addLeds<CHIPSET,DATA_PIN,CLK_PIN,BGR>(leds,NUM_LEDS);
    FastLED.setBrightness(10);
    Serial.println("Commands: 0, r, g, b");

}


void loop(){
    handleSerial();
    FastLED.show();
}