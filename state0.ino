void state0() {
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
}
