void monitor() { 
  Serial.print("light = ");
  Serial.print(lightValue);
  Serial.print("\t touch = "); // The "\t" character is a tab space to clean up the read out.
  Serial.println(capSense);
  digitalWrite(aLED, aLEDstate); 
  aLEDstate = !aLEDstate;    
}

void startUp() {
   Serial.println("\n");
  for (int thisPin = 0; thisPin < pinCount; thisPin++) { 
    digitalWrite(ledPins[thisPin], HIGH);   
    delay(30);              
    digitalWrite(ledPins[thisPin], LOW);
Serial.print(thisPin);    
  }
  for (int thisPin = pinCount - 1; thisPin >= 0; thisPin--) { 
    digitalWrite(ledPins[thisPin], HIGH);
    delay(30);
    digitalWrite(ledPins[thisPin], LOW);
    Serial.print(thisPin);
  }
   Serial.println(" STARTUP!");
}
