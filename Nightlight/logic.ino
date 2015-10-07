int logic() {
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

