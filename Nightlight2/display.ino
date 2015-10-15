int anime01() { // a function to reduce the brightness of leds so they fade out.
    int currentTime = millis(); // check the time
    if (currentTime - prevLedTime >= ledSpeed) { //if enough time has gone by:
        ledsDir[ledState] = 0;
        ledState++;
        if (ledState == 6) ledState = 0;
        ledsDir[ledState] = 3;
        prevLedTime = currentTime;
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
        analogWrite(leds[n], ledsVal[n]);
    }
}

int updateLED() {
    unsigned long currentMillis = millis();
    if (currentMillis - fadePreviousMillis >= fadeSpeed) {
        for (int i = 0; i < pinCount; i++) {
            switch (ledsDir[i]) {
                case 0: // stay at 0 or fade down to 0
                    if (ledsVal[i] > 0) ledsVal[i] = ledsVal[i] - ledsDecay[i];
                    break;
                case 1: // fading up and down - up
                    ledsVal[i]++;
                    if (ledsVal[i] >= 255) ledsDir[i] = 2;
                    break;
                case 2: // fading up and down - down
                    ledsVal[i]--;
                    if (ledsVal[i] <= 0) ledsDir[i] = 1;
                    break;
                case 3: // stay at 255 or fade up to 255
                    if (ledsVal[i] < 255) ledsVal[i] = ledsVal[i] + ledsAttack[i];
                    break;
                default:
                    Serial.println("default");
                    break;
            }
            int x = map(ledsVal[i], 0, 255, 0, maxBrightness);
            analogWrite(leds[i], x);
            Serial.println(ledsVal[1]);
            fadePreviousMillis = currentMillis;
        }
    }
}

