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

int debug(int x) { // receive a variable when called and put it into "x"
  Serial.println(x);
  if (touched == 1) {
    digitalWrite(13, HIGH);
  } else {
    digitalWrite(13, LOW);
  }
}

int display() { // send the ledFade amount to each of the leds
  for (int n = 0; n < 6; n++) {
    analogWrite(leds[n], ledFade[n]);
  }
}

