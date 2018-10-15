// Spotify Conductor project - an Arduino project for an emergency stop button to control & pause media playback
#include <Keyboard.h>

//Set pins
const int ledPin = 17;
const int buttonPin = 2;

int buttonState = 0;

bool lastFrame = false;



void setup() {
  // initialize the LED pin as an output:
  pinMode(ledPin, OUTPUT);
  // initialize the button pin as an input:
  pinMode(buttonPin, INPUT);
  
  Serial.begin(9600);
}


void loop() {
  
  // read and check state of push button pin
  buttonState = digitalRead(buttonPin);
  if (buttonState == LOW && lastFrame == false) {
    //changed from unpressed to pressed
    delay(100);
    lastFrame=true;
    digitalWrite(ledPin, HIGH);
    Serial.println("hit pause key (pressed)");   
  }
  
  if (buttonState == HIGH && lastFrame == true) { 
    //changed from pressed to unpressed
    delay(100);
    lastFrame=false;
    digitalWrite(ledPin, LOW);     // turn LED off:
    Serial.println("hit pause key (unpressed)");
  }  
  
}
