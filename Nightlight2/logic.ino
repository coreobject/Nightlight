int logic() {
    switch (stateVar) {
        case (0): // daytime and lights are off
            lightVar = 0;
            digitalWrite(ledPin, LOW);
            if (touched == 1) {
                lightVar = !lightVar;
                stateVar = 1;
                Serial.println("State 1");
                touched = 2;
            } else if (darkState == 1) {
                stateVar = 2;
            }
            break;
        case (1): // touched
            digitalWrite(ledPin, HIGH);
            if (touched == 1) {
                stateVar = 0;
                Serial.println("State 0");
                touched = 2;
            }
            break;
        case (2): // night time lights on
            lightVar = 1;
            if (touched == 1) {
                lightVar = !lightVar;
                stateVar = 1;
                Serial.println("State 1");
                touched = 2;
            } else if (darkState == 0) {
                stateVar = 0;
            }
    }
}

