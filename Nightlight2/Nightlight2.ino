// Set up capacitive sensor
#include <CapacitiveSensor.h> // the capacitive sensor library
CapacitiveSensor   cs_4_2 = CapacitiveSensor(4, 2); //setup pins 4 and 2 for the sensor. 2 has the probe.

// Set up LED display
int ledState;
int ledSpeed = 6000; // Speed at which the LEDs animate.
byte maxBrightness = 255; // Maximum brightness for LEDs.
byte ledsVal[] = {0, 0, 0, 0, 0, 0}; // The brightness value of all of the pins.
byte ledsDir[] = {0, 0, 0, 0, 0, 0};
/*
 * You can set a behavior for an LED.
 * 0 = fade out or stay off.
 * 1 = fade off and on starting upwards.
 * 2 = fade off and on starting downwards.
 * 3 = fade up or stay on.
 * Example:
 * ledsVal[2] = 127;
 * ledsDir[2] = 3;
 * These two lines would set the LED on pin 6 to medium brightness and tell it to fade up to max brightness.
 */

 // Variables for writing to the LEDs. You should not need to change these:
int leds[] = { 3, 5, 6, 9, 10, 11}; // array of all the pwm pins
int fadeSpeed = 0; // length of time for when to change the fade out of the led
int fadePreviousMillis;
int pinCount = 6; // how many pwm pins
int ledPin = 13; // use the Arduino's built-in led for debugging
int prevLedTime; // a variable for the fade timing

// Variables for logic
int i; // a variable later use in the logic
int prevTime; // a variable for the logic timing
int interval = 500; // length of time for logic time
int touched;
int stateVar;
int lightVar;
int darkVar;

void setup() {
  for (int thisPin = 0; thisPin < pinCount; thisPin++) { // set the 6 led pins to output
    pinMode(leds[thisPin], OUTPUT);
  }
  pinMode(ledPin, OUTPUT); // set the debug led to output
  Serial.begin(9600);
  Serial.println();
 // debug();
}

void loop() {
  darkVar = darkSense();
  touchSense(); // call the function "touchSense" and put the result in touched
  logic(); // call the function "logic"
// debug();
  fade(); // call the function "fade"
  pulseLED();
  // display(); // call the function "display"

}

