void display() {
    switch (lightState) {
        case 0: // Lights off.
            ledFade[0] = 0;
            ledFade[1] = 10;
            break;

        case 1: // Lights fade up.
            break;

        case 2: // Lights on.
            ledFade[0] = 255;
            ledFade[1] = 0;
            break;

        case 3: // Lights fade out.
            break;
    }
  for (int thisPin = 0; thisPin < pinCount; thisPin++)  {
    analogWrite(ledPins[thisPin],ledFade[thisPin]);
  }
}
