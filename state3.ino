void state3 () {
    touchSense();
    if ( touch == true ){ // If so change state and start a timer.
        state = 2;
        touchTimer = 100;
        switch (lightState) {
            case 0:
                lightState = 2;
                break;
            case 1:
                lightState = 0;
                break;
            case 2:
                lightState = 0;
                break;
            case 3:
                lightState = 2;
                break;
        }
    }
    touchTimer--;
    if ( touchTimer == 0 ){ // If the timer has finished change state.
      lightSense();
      if ( dark == true ) { // Switch to either day or night mode.
          state = 1;
          lightState = 2;
      } else {
          state = 0;
          lightState = 0;
      }
    }
}
