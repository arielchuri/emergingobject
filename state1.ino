void state1() {
    darkLimit = darkLimit + 200; // Change the darklimit so the reading cannot bounce around if it hovers near the darklimit.
    lightSense(); // Check if it becomes light.
    darkLimit = darkLimit - 200;
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
