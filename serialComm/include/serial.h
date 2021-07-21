#include "ard_APA102.h"

CRGB color;
int effect; 
void handleSerial(){
    /*
        Style choice: while loops handle all serial characters at once
        For "time sensitive code" safe to use an if statement
    */
    if (Serial.available() > 0){
        char incomingCharacter = Serial.read();
        switch(incomingCharacter){
            case '0':
                staticText(0,CRGB::DarkOrange,CRGB::Black);
                break;
            case 'g':
                solidSquare(CRGB::Green);
                break;
            case 'b':
                rollingBorder(CRGB::White);
                break;
            case 'r':
                solidSquare(CRGB::Red);
                break;
            
        }
    }
}