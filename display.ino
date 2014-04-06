void display() {
    switch (lightState) {
        case 0: // Lights off.
            ledFade[0] = 0;
            break;

        case 1: // Lights fade up.
            break;

        case 2: // Lights on.
            ledFade[0] = 255;
            break;

        case 3: // Lights fade out.
            break;
    }
    analogWrite(ledPins[1],ledFade[0]);
}
