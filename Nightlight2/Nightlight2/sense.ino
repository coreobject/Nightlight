int touchSense(int x){ // a function to check the touch sensor and return the result
    long start = millis();
    long touchVar =  cs_4_2.capacitiveSensor(30);
    switch (x) {
        case 0:
            if (touchVar >= 1000) return 1;
            break;
        case 1:
            return 1;
            break;
        case 2:
            if (touchVar < 1000) return 0;
            break;
    }
}

int darkSense(){
  int result = analogRead(A0);
  return result;
}
