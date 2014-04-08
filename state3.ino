void state3 () { // next i will get rid of the states.
    touchSense();
    if ( touch == true ){ // If so change state and start a timer.
        state = 2;
        touchTimer = 100;
        switch (lightState) {
            case 0: // The light is off so fade it up.
                lightState = 2;
                break;
            case 1: // The light is fading up so fade it down.
                lightState = 0;
                break;
            case 2: // The light is on so fade it out. 
                lightState = 0;
                break;
            case 3: // The light is fading out so fade it up.
                lightState = 2;
                break;
        }
    }
    touchTimer--;
    /*
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
    */
}
