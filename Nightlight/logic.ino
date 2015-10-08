int logic() {

  switch (stateVar) {
    case (0): // daytime and lights are off
      if (touched == 1) {
        stateVar = 1;
        touched = 2;
      }
    //break;
    case (1): // touched
      if (touched == 1) {
        stateVar = 0;
        touched = 2;
      }
      lightVar = 1;
      break;
  }




  int currentTime = millis(); //check the time
  if (currentTime - prevTime >= interval) { // if enough has gone by:
    ledFade[i] = 60; // set one of the leds to 255
    i++; // add 1 so it will be the next led
    if (i == 6) { // there is no led 6 so roll back to 0
      i = 0;
    }
    prevTime = currentTime;
  }
}

