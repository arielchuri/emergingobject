void touchSense() {
  long start = millis(); // Start a timer which the touch sensor needs.
  capSense = cs_4_2.capacitiveSensor(30);  // Read the touch sensor and store the value.
  // Next we check if the value was high enough to be considered a touch.
  if ( capSense >= touchLimit ) {
      // If it is, we check that it has stayed high enough for a few readings.
      if ( touchTimer == 2 ) {
          touch = true;
      } 
      touchTimer++;
  } else {
      touch = false;
      touchTimer = 0;
  }
}
// Check the light sensor and change the value of light based on the reading.
void lightSense() {
  lightValue = analogRead(lightPin);
  if ( lightValue <= darkLimit ) {
      night = true;
  } else {
      night = false;
  }
}
