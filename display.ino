void display() {
    // If light is true it means the light should be on.
    if ( light ){
    ledFade[3] = 200;
    } else {
    ledFade[3] = 0;
    }
  for (int thisPin = 0; thisPin < pinCount; thisPin++)  {
    analogWrite(ledPins[thisPin],ledFade[thisPin]);
  }
}
