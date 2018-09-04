int motorPin1 = 5;
int motorPin2 = 6;
int enA = 7;

int display1 = 4;
int display2 = 12;
int display3 = 13;

//floor markers
boolean level1 = true;
boolean level2 = false;
boolean level3 = false;

// constants won't change. They're used here to set pin numbers:
const int buttonPin1 = 8;    // the number of the pushbutton pin
const int buttonPin2 = 9;
const int buttonPin3 = 11;
const int ledPin = 13;      // the number of the LED pin

// Variables will change:
int ledState = HIGH;         // the current state of the output pin
int buttonState1;             // the current reading from the input pin
int buttonState2;
int buttonState3;
int lastButtonState1 = LOW;   // the previous reading from the input pin
int lastButtonState2 = LOW;
int lastButtonState3 = LOW;

// the following variables are unsigned longs because the time, measured in
// milliseconds, will quickly become a bigger number than can be stored in an int.
unsigned long lastDebounceTime1 = 0;  // the last time the output pin was toggled
unsigned long lastDebounceTime2 = 0;
unsigned long lastDebounceTime3 = 0;
unsigned long debounceDelay = 50;    // the debounce time; increase if the output flickers

//IR varibales
int IRpin = 2;

unsigned long lastIRdebounceTime = 0;
unsigned long IRdebounceDelay = 50;

int IRstate = HIGH;
int lastIRstate = HIGH;


void setup() {
//  buttons
  pinMode(buttonPin1, INPUT);
  pinMode(buttonPin2, INPUT);
  pinMode(buttonPin3, INPUT);

//  LED
  pinMode(ledPin, OUTPUT);

// set initial LED state
  digitalWrite(ledPin, ledState);

//  Motor
  pinMode(enA, OUTPUT);
  pinMode(motorPin1, OUTPUT);
  pinMode(motorPin2, OUTPUT);
  digitalWrite(enA, HIGH);

//  IR sensor
  pinMode(IRpin, INPUT);

//  7 segment pins
  pinMode(display1, OUTPUT);
  pinMode(display2, OUTPUT);
  pinMode(display3, OUTPUT);
  
  digitalWrite(display1, HIGH);
  digitalWrite(display2, LOW);
  digitalWrite(display3, LOW);
}

void clockwise()
{
  int i = 0;
  while (i != 6){
    digitalWrite(motorPin2, LOW);
    digitalWrite(motorPin1, HIGH);
    
    int IRvalue = digitalRead(IRpin);
    
    if (IRvalue != lastIRstate) {
      // reset the debouncing timer
      lastIRdebounceTime = millis();
    }
    
    if ((millis() - lastIRdebounceTime) > IRdebounceDelay){      
      if (IRvalue != IRstate) {
        IRstate = IRvalue;
        if (IRvalue == LOW){
          i++;
        }
      }
    }
    lastIRstate = IRvalue;
  }
  
  digitalWrite(motorPin1, LOW);
  digitalWrite(motorPin2, LOW);
}

void anticlockwise()
{
  int i = 0;
  while (i != 6){
    digitalWrite(motorPin2, HIGH);
    digitalWrite(motorPin1, LOW);
    
    int IRvalue = digitalRead(IRpin);
    
    if (IRvalue != lastIRstate) {
      // reset the debouncing timer
      lastIRdebounceTime = millis();
    }
    
    if ((millis() - lastIRdebounceTime) > IRdebounceDelay){      
      if (IRvalue != IRstate) {
        IRstate = IRvalue;
        if (IRvalue == LOW){
          i++;
        }
      }
    }
    lastIRstate = IRvalue;
  }
  digitalWrite(motorPin1, LOW);
  digitalWrite(motorPin2, LOW);
}
void norotate()
{
  digitalWrite(motorPin2, LOW);
  digitalWrite(motorPin1, LOW);
}
// Functions to show floor number on 7 segment display
void show1()
{
   digitalWrite(display1, HIGH);
   digitalWrite(display2, LOW);
   digitalWrite(display3, LOW);
}
void show2()
{
   digitalWrite(display1, LOW);
   digitalWrite(display2, HIGH);
   digitalWrite(display3, LOW);
}
void show3()
{
   digitalWrite(display1, LOW);
   digitalWrite(display2, LOW);
   digitalWrite(display3, HIGH);
}
void loop() {
  // read the state of the switch into a local variable:
  int reading1 = digitalRead(buttonPin1);
  int reading2 = digitalRead(buttonPin2);
  int reading3 = digitalRead(buttonPin3);

  // check to see if you just pressed the button
  // (i.e. the input went from LOW to HIGH), and you've waited long enough
  // since the last press to ignore any noise:

  // If the switch changed, due to noise or pressing:
  if (reading1 != lastButtonState1) {
    // reset the debouncing timer
    lastDebounceTime1 = millis();
  }
  if (reading2 != lastButtonState2) {
    // reset the debouncing timer
    lastDebounceTime2 = millis();
  }
  if (reading3 != lastButtonState3) {
    // reset the debouncing timer
    lastDebounceTime3 = millis();
  }

  if ((millis() - lastDebounceTime1) > debounceDelay) {
    // whatever the reading is at, it's been there for longer than the debounce
    // delay, so take it as the actual current state:

    // if the button state has changed:
    if (reading1 != buttonState1) {
      buttonState1 = reading1;

      // only toggle the LED if the new button state is HIGH
      if (buttonState1 == HIGH) {
        ledState = !ledState;
        if (level1 == true){
           norotate();
        }
        if (level2 == true){
          // go from level2 to level1
          clockwise();
          level2 = false;
          level1 = true;
        }
        if (level3 == true){
          // go from level3 to level1
          clockwise();
          clockwise();
          level3 = false;
          level1 = true;
        }
      }
      show1();
    }
  }

  if ((millis() - lastDebounceTime2) > debounceDelay) {
    // whatever the reading is at, it's been there for longer than the debounce
    // delay, so take it as the actual current state:

    // if the button state has changed:
    if (reading2 != buttonState2) {
      buttonState2 = reading2;

      // only toggle the LED if the new button state is HIGH
      if (buttonState2 == HIGH) {
        ledState = !ledState;
        if (level1 == true){
          // go from level1 to level2
          anticlockwise();
          level2 = true;
          level1 = false;
        }
        if (level2 == true){
          norotate();
        }
        if (level3 == true){
          // go from level3 to level1
          clockwise();
          level3 = false;
          level2 = true;
        }
      }
      show2();
    }
  }

    if ((millis() - lastDebounceTime3) > debounceDelay) {
    // whatever the reading is at, it's been there for longer than the debounce
    // delay, so take it as the actual current state:

    // if the button state has changed:
    if (reading3 != buttonState3) {
      buttonState3 = reading3;

      // only toggle the LED if the new button state is HIGH
      if (buttonState3 == HIGH) {
        ledState = !ledState;
        if (level1 == true){
          // go from level1 to level3
          anticlockwise();
          anticlockwise();
          level1 = false;
          level3 = true;
        }
        if (level2 == true){
          // go from level2 to level3
          anticlockwise();
          level3 = true;
          level2 = false;
        }
        if (level3 == true){
          norotate();
        }
      }
      show3();
    }
  }

  // save the reading. Next time through the loop, it'll be the lastButtonState:
  lastButtonState1 = reading1;
  lastButtonState2 = reading2;
  lastButtonState3 = reading3;
}

