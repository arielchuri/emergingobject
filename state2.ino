void state2 () {
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
}
