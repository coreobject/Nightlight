int fade() { // a function to reduce the brightness of leds so they fade out.
  int currentTime = millis(); // check the time
  if (currentTime - prevFadeTime >= fadeSpeed) { //if enough time has gone by:
    for (int n = 0; n < 6; n++) { // for each index in the ledFade array
      if (ledFade[n] >= 1) { // if it is greater then 0
        ledFade[n] = ledFade[n] - 1; // subtract 1
      }
    }
    prevFadeTime = currentTime;
  }
}

int debug() { // receive a variable when called and put it into "x"
    Serial.print("stateVar =\t");
    Serial.print(stateVar);
    Serial.print("\ttouched =\t");
    Serial.print(touched);
    Serial.print("\tlightVar =\t");
    Serial.print(lightVar);
    Serial.print("\tdarkVar =\t");
    Serial.print(darkVar);
    Serial.println();
}

int display() { // send the ledFade amount to each of the leds
  for (int n = 0; n < 6; n++) {
    analogWrite(leds[n], ledFade[n]);
  }
}

