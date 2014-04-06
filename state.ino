void statemachine() {
 switch (state) {
  case 0: // not touched, not in darkness. Day Mode.
    lightSense(); // Check if it is dark 
    if ( dark == true ){
      state = 1; // If it is dark change state and set the LED brightness high.
      lightState = 2;
    }
    touchSense(); // Check the touch sensor
    if ( touch == true ){ // If touched change state, light the LED, and start a timer.
      state = 2;
      touchTimer = 100;
      lightState = 2;
    }
    break; 
 
  case 1: // not touched, in darkness. Night Mode.
    lightSense(); // Check if it becomes light.
    if ( dark == false ){ // If it does, change state and dim LEDs.
      state = 0;
      lightState = 0;
    }
    touchSense(); // Check if touched.
    if ( touch == true ){ // If so change state and start a timer.
      state = 2;
      touchTimer = 100;
      lightState = 0;
    }
    break;
 
  case 2: // touched.
    touchSense(); // Check the touch sensor.
    touchTimer--; // Decrement the touch timer.
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
    if ( touch == false && touchTimer <= 90){
      state = 3; 
    }
    break;
 
  case 3: // untouched, 
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
    break;

  case 4: 
    break;

 }
}
