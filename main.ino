#include <SevSeg.h>

const int buttonPin = 2;              // Button pin
const int vibrationPin = 3;           // Vibration sensor pin
const int displayPins[] = {4, 5, 6, 7};  // Pins connected to 4x7 segments display

SevSeg sevseg;                       // Object for 4x7 segments display

unsigned long startTime = 0;         // Timer start time
unsigned long stopTime = 0;          // Timer stop time
bool timerRunning = false;           // Flag to track if the timer is running
bool buttonState = false;            // Current state of the button
bool lastButtonState = false;        // Previous state of the button

void setup() {
  pinMode(buttonPin, INPUT_PULLUP);
  pinMode(vibrationPin, INPUT_PULLUP);
  
  sevseg.begin(COMMON_CATHODE, sizeof(displayPins) / sizeof(displayPins[0]), displayPins);
  sevseg.setBrightness(90);
}

void loop() {
  buttonState = digitalRead(buttonPin);
  
  if (buttonState != lastButtonState) {
    if (buttonState == LOW) {
      resetTimer();
    }
    delay(50); // Debounce delay
  }
  
  lastButtonState = buttonState;
  
  if (timerRunning) {
    unsigned long currentTime = millis();
    unsigned long elapsedTime = currentTime - startTime;
    displayTime(elapsedTime);
  } else if (digitalRead(vibrationPin) == LOW) {
    startTimer();
  }
}

void startTimer() {
  startTime = millis();
  timerRunning = true;
}

void stopTimer() {
  stopTime = millis();
  timerRunning = false;
}

void resetTimer() {
  stopTimer();
  sevseg.setNumber(0);
  sevseg.refreshDisplay();
}

void displayTime(unsigned long time) {
  unsigned int minutes = (time / 60000) % 100;
  unsigned int seconds = (time / 1000) % 60;
  unsigned int milliseconds = (time % 1000);
  
  if (minutes < 10) {
    // Display milliseconds
    sevseg.setNumber(milliseconds, 0);
    sevseg.setNumber(0, 1);  // Clear the second digit for seconds
    sevseg.setNumber(0, 2);  // Clear the first digit for seconds
    sevseg.setNumber(0, 3);  // Clear the first digit for minutes
  } else if (seconds < 10) {
    // Display seconds and milliseconds
    sevseg.setNumber(milliseconds, 0);
    sevseg.setNumber(seconds, 1);
    sevseg.setNumber(0, 2);  // Clear the first digit for seconds
    sevseg.setNumber(0, 3);  // Clear the first digit for minutes
  } else {
    // Display minutes and seconds
    sevseg.setNumber(seconds, 0);
    sevseg.setNumber(minutes, 1);
    sevseg.setNumber(0, 2);  // Clear the first digit for seconds
    sevseg.setNumber(0, 3);  // Clear the first digit for minutes
  }
  
  sevseg.refreshDisplay();
}

