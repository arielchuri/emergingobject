#include <CapacitiveSensor.h>  //Load the capSense Library which the touch sensor uses.
CapacitiveSensor   cs_4_2 = CapacitiveSensor(4,2); // Set up the touch sensor on pins 4 and 2.
long capSense; // A variable to store the value from the touch sensor.
 
int ledPins[] = { 
  11, 10, 9, 6, 5, 3 }; 
int pinCount = 6;        
 
int lightPin = A0;  
int lightValue = 0;   
 
int aLED = 13;        
boolean aLEDstate;   
 
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
  long start = millis(); // Start a timer which the touch sensor needs.
  capSense = cs_4_2.capacitiveSensor(30);  // Read the touch sensor and store the value.
  lightValue = analogRead(lightPin);
  monitor(); 
}
 
//==============ENDLOOP==============//
 

 

