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
  for (pin=2; pin < 14, pin++) { 
    pinMode(pin, OUTPUT);    
  }
}

void loop() {
  // blink all twelve at the same time

  // blink on
  for (pin=2; pin < 14, pin++) { 
    digitalWrite(pin, HIGH); 
  }

  // wait
  delay(100); 

  // blink off
  for (pin=2; pin < 14, pin++) { 
    digitalWrite(pin, LOW);
  }
  
  
  // turn led's on/off in a row with 100 millisecond interval
  pin = 2;
  for (pin=2; pin < 14, pin++) { 
    digitalWrite(pin, HIGH);
    delay(100); 
    digitalWrite(pin, LOW);
  }

  // wow  ... so much less typing 
  // can you make it go backwards from 12 to 1? 

  
}
