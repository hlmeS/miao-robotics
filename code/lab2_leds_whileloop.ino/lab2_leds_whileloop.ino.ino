/* 
 *  
 *  Title: X-Mas Lights, Version 1
 *  Objective: Control multiple LEDs
 */

int pin; 

void setup() {
  // set communication with the computer
  Serial.begin(9600);

  // set the pins as output pins
  pin = 2; 
  while (pin < 14) { 
    pinMode(pin, OUTPUT);
    pin = pin + 1;
    
  }
}

void loop() {
  // blink all twelve at the same time

  // blink on
  pin = 2; 
  while (pin < 14) {
    digitalWrite(pin, HIGH); 
    pin = pin + 1;
  }

  // wait
  delay(100); 

  // blink off
  pin = 2; 
  while (pin < 14) {
    digitalWrite(pin, LOW);
    pin = pin + 1;
  }
  
  
  // turn led's on/off in a row with 100 millisecond interval
  pin = 2;
  while (pin < 14) {
    digitalWrite(pin, HIGH);
    delay(100); 
    digitalWrite(pin, LOW);
    pin = pin + 1;
  }

  // wow  ... so much less typing 
  // can you make it go backwards from 12 to 1? 

  
}
