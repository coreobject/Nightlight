int logic() {
  switch (stateVar) {
    case (0): // daytime and lights are off
      lightVar = 0;
      if (maxBrightness > 0) maxBrightness--;
      if (touched == 1) {
        stateVar = 1;
        touched = 2;
      }
      break;
    case (1): // touched
      lightVar = 1;
      if (maxBrightness < 255) maxBrightness++;
      if (touched == 1) {
        stateVar = 0;
        touched = 2;
      }
      break;
  }
}

