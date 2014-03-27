//  Emerging Object Code 3/26/14 9:22 PM                                                 
//                                      +--------+ 
//                                      | TOUCH  | 
//                                      | SENSOR | 
//                                      |        | 
//                                      +------  | 
//                 ARDUINO                       | 
//              +-----------+                    | 
//              |        GND|-----------------+  | 
//              |           |                 |  | 
//              |         13|                 |  | 
//              |         12|                 |  | 
//              |        ~11|-[R220]--[LED>]--O  | 
//              |        ~10|-[R220]--[LED>]--O  | 
//  +--[PHOTO]--|5V       ~9|-[R220]--[LED>]--O  | 
//  |           |GND       8|                 |  | 
//  O---[R10K]--|GND       7|                 |  | 
//  |           |         ~6|-[R220]--[LED>]--O  | 
//  +-----------|A0       ~5|-[R220]--[LED>]--O  | 
//              |A1        4|----[R1M]--------+--O 
//              |A2       ~3|-[R220]--[LED>]--+  | 
//              |A3        2|--------------------+ 
//              |A4        1|                      
//              +-----------+                      
//         
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
