void touchSense() {
  long start = millis(); // Start a timer which the touch sensor needs.
  capSense = cs_4_2.capacitiveSensor(30);  // Read the touch sensor and store the value.
  if ( capSense >= touchLimit ) {
      touch = true;
  } else {
  touch = false;
  }
  }
void lightSense() {
  lightValue = analogRead(lightPin);
  if ( lightValue <= darkLimit ) {
      dark = true;
  } else {
      dark = false;
  }
}
