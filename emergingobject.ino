//  Emerging Object Code 3/26/14 9:22 PM                   @sparklelabs.com                              
// SENSORS:=============================//
#include <CapacitiveSensor.h>  //Load the capSense Library which the touch sensor uses.
CapacitiveSensor   cs_4_2 = CapacitiveSensor(4,2); // Set up the touch sensor on pins 4 and 2.
long capSense; // A variable to store the value from the touch sensor.
int touchLimit = 300; // How high the touch sensor must read to be touched.
boolean touch = false; // Keeps track if touch sensor was touched.
int touchTimer; // We user a timer to have the touch sensor make sure there is a long enough touch call it a real touch.
int lightPin = A0; // The pin with the light sensor.
int lightValue = 0; // Variable to store the reading from the light sensor.
boolean night = false; // Keeps track of when it is dark out.
int darkLimit = 400; // Limit for the light sensor. When the value is less then this number it is considered night. Change this to make it more or less sensitive to the dark.

// LIGHTS:===========================//
int ledPins[] = { // An array of variables with each of the LED pin numbers.
  11, 10, 9, 6, 5, 3 }; 
int pinCount = 6; // The number of LEDs.
boolean light = false; If this is true then the lights are on.
int ledFade[6]; // An array to keep track of the brightness of each LED.
int aLED = 13; // The onboard LED.
boolean aLEDstate; // A variable to keep track of the state of the onboard LED.
 
// SETUP:==============================// 
void setup() {
  Serial.begin(9600); // Turns on the serial port.
  pinMode(aLED, OUTPUT); // Set the onboard LED to output.
  for (int thisPin = 0; thisPin < pinCount; thisPin++)  { // Set each LED pin as output.
    pinMode(ledPins[thisPin], OUTPUT);    
  }
  startUp(); // This functions blinks all of the LEDs as well as has the routine for writing to the serial port.
}
 
//===============LOOP================//
void loop() {
    touchSense(); // Check the touch sensor. If it is touch for long enough "touch" will be true.
    if (touch == true) { // If it is true we will...
        light = !light; // toggle the lights and...
        touch = false; // set "touch" back to false so that we do not toggle the lights again.
    } else { // If "touch" is not true we can check the light sensor.
        if (night) { // This is set up so that the light sensor will not override the users input with the touch sensor.
            // If it is currently night...
            lightSense(); // Check the light sensor.
            if ( night == false && light ) { // If it has become day and the light is on...
                light = false; // turn the light off.
            }
        } else { // If it is day time...
            lightSense(); // check the light sensor...
            if ( night == true && light == false ) { // If it is now night time and the light is off...
                light = true; // Turn the light on.
            }
        }
    }
    display(); // This routine decides which LEDs should be on and at what brightness.
    monitor(); // Writes variables to the serial port for debugging. Comment it out when you don't need it.
}
 
//==============ENDLOOP==============//
