int anime01() { // a function to reduce the brightness of leds so they fade out.
    int currentTime = millis(); // check the time
    if (currentTime - prevLedTime >= animeSpeed) { //if enough time has gone by:
        ledsDir[ledState] = 0;
        Serial.println(ledState);
        ledState++;
        if (ledState == 6) ledState = 0;
        ledsDir[ledState] = 3;
        prevLedTime = currentTime;
    }
}

int anime02() {
    int currentTime = millis(); // check the time
    if (currentTime - prevLedTime >= animeSpeed) { //if enough time has gone by:
        if (ledState == 3) ledState = 0;
        switch (ledState) {
            case 0:
                for (int i = 0; i < 6; i++) {
                    ledsVal[i] = 1000 / 6 * i;
                    ledsDir[i] = 1;
                }
                break;
            case 1:
                ledsDir[0] = 3;
                ledsDir[1] = 3;
                ledsDir[2] = 3;
                ledsDir[3] = 0;
                ledsDir[4] = 0;
                ledsDir[5] = 0;
                break;
            case 2:
                long randomNumber = random(6);
                ledsDir[randomNumber] = 1;
                ledsAttack[randomNumber] = 50;
                ledsDecay[randomNumber] = 50;
                break;
        }
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
    Serial.print(darkState);
    Serial.println();
}
/*
   int display() { // send the ledFade amount to each of the leds
   for (int n = 0; n < 6; n++) {
   analogWrite(leds[n], ledsVal[n]);
   }
   }
 */
int updateLED() {
    switch (lightVar) { // Check to see if the lights should be on or off.
        case (0):
            if (maxBrightness > 0) maxBrightness = maxBrightness - onoffSpeed;
            maxBrightness = max(maxBrightness, 0);
            break;
        case (1):
            if (maxBrightness < 255) maxBrightness = maxBrightness + onoffSpeed;
            maxBrightness = min(maxBrightness, 255);
            break;
    }
    unsigned long currentMillis = millis();
    if (currentMillis - fadePreviousMillis >= fadeSpeed) {
        for (int i = 0; i < pinCount; i++) {
            switch (ledsDir[i]) {
                case 0: // stay at 0 or fade down to 0
                    if (ledsVal[i] > 0) ledsVal[i] = ledsVal[i] - ledsDecay[i];
                    break;
                case 1: // fading up and down - up
                    ledsVal[i]++;
                    if (ledsVal[i] >= 1000) ledsDir[i] = 2;
                    break;
                case 2: // fading up and down - down
                    ledsVal[i]--;
                    if (ledsVal[i] <= 0) ledsDir[i] = 1;
                    break;
                case 3: // stay at 1000 or fade up to 1000
                    if (ledsVal[i] < 1000) ledsVal[i] = ledsVal[i] + ledsAttack[i];
                    break;
                default:
                    Serial.println("default");
                    break;
            }
            int x = map(ledsVal[i], 0, 1000, 0, maxBrightness);
            analogWrite(leds[i], x);
            fadePreviousMillis = currentMillis;
        }
            Serial.println(ledsVal[1]);
    }
}

