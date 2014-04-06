//  Emerging Object Code 3/26/14 9:22 PM                                                 
// SENSORS:=============================
#include <CapacitiveSensor.h>  //Load the capSense Library which the touch sensor uses.
CapacitiveSensor   cs_4_2 = CapacitiveSensor(4,2); // Set up the touch sensor on pins 4 and 2.
long capSense; // A variable to store the value from the touch sensor.
boolean touch = false; // Keeps track if touch sensor was touched.
int touchLimit = 300; // How high the touch sensor must read to be touched.
int touchTimer;
int lightPin = A0; // The pin with the light sensor.
int lightValue = 0; // Variable to store the reading from the light sensor.
boolean dark = false; // Keeps track of when it is dark out.
int darkLimit = 300; // Limit for the light sensor. When the value is less then this number it is considered dark. Change this to make it more or less sensitive to the dark.

// LIGHTS:===========================
int ledPins[] = { // An array of variables with each of the LED pin numbers.
  11, 10, 9, 6, 5, 3 }; 
int pinCount = 6; // The number of LEDs.
int lightState;
int ledFade[6];
int aLED = 13; // The onboard LED.
boolean aLEDstate; // A variable to keep track of the state of the onboard LED.
 
// LOGIC:==============================
int state = 0;
/*
 state 0 - not touched, not in darkness
 state 1 - not touched, in darkness
 state 2 - touched, not in darkness
 state 3 - untouched, not in darkness
 state 4 - touched, in darkness
 state 5 - untouched, in darkness
 */

void setup() {
  Serial.begin(9600);
  pinMode(aLED, OUTPUT);
  for (int thisPin = 0; thisPin < pinCount; thisPin++)  {
    pinMode(ledPins[thisPin], OUTPUT);    
  }
  startUp(); 
}
 
//===============LOOP================//
 
void loop() {
    statemachine();
    display();
    monitor(); 
}
 
//==============ENDLOOP==============//
