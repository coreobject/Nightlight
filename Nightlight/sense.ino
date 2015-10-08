int touchSense(){ // a function to check the touch sensor and return the result
  long start = millis();
  long result =  cs_4_2.capacitiveSensor(30);
  return result;
}

int darkSense(){
  int result = analogRead(A0);
  return result;
}

