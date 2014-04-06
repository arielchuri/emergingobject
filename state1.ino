void state1() {
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
}
