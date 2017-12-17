/* 
 *  
 *  Title: X-Mas Lights, Version 1
 *  Objective: Control multiple LEDs
 */

// assign names to the different pins
int led_1 = 2;
int led_2 = 3; 
int led_3 = 4; 
int led_4 = 5; 
int led_5 = 6; 
int led_6 = 7; 
int led_7 = 8;
int led_8 = 9; 
int led_9 = 10;
int led_10 = 11; 
int led_11 = 12; 
int led_12 = 13; 

void setup() {
  // set communication with the computer
  Serial.begin(9600);

  // set the pins as output pins
  pinMode(led_1, OUTPUT);
  pinMode(led_2, OUTPUT);
  pinMode(led_3, OUTPUT);
  pinMode(led_4, OUTPUT);  
  
  pinMode(led_5, OUTPUT);  
  pinMode(led_6, OUTPUT);  
  pinMode(led_7, OUTPUT);  
  pinMode(led_8, OUTPUT);  

  pinMode(led_9, OUTPUT);  
  pinMode(led_10, OUTPUT);  
  pinMode(led_11, OUTPUT);  
  pinMode(led_12, OUTPUT);  
    
}

void loop() {
  // blink all twelve at the same time
  digitalWrite(led_1, HIGH);
  digitalWrite(led_2, HIGH);
  digitalWrite(led_3, HIGH);
  digitalWrite(led_4, HIGH);
  digitalWrite(led_5, HIGH);
  digitalWrite(led_6, HIGH);
  digitalWrite(led_7, HIGH);
  digitalWrite(led_8, HIGH);
  digitalWrite(led_9, HIGH);
  digitalWrite(led_10, HIGH);
  digitalWrite(led_11, HIGH);
  digitalWrite(led_12, HIGH);

  delay(100); 

  digitalWrite(led_1, LOW);
  digitalWrite(led_2, LOW);
  digitalWrite(led_3, LOW);
  digitalWrite(led_4, LOW);
  digitalWrite(led_5, LOW);
  digitalWrite(led_6, LOW);
  digitalWrite(led_7, LOW);
  digitalWrite(led_8, LOW);
  digitalWrite(led_9, LOW);
  digitalWrite(led_10, LOW);
  digitalWrite(led_11, LOW);
  digitalWrite(led_12, LOW);

  delay(100); 
  
  digitalWrite(led_1, HIGH);
  digitalWrite(led_2, HIGH);
  digitalWrite(led_3, HIGH);
  digitalWrite(led_4, HIGH);
  digitalWrite(led_5, HIGH);
  digitalWrite(led_6, HIGH);
  digitalWrite(led_7, HIGH);
  digitalWrite(led_8, HIGH);
  digitalWrite(led_9, HIGH);
  digitalWrite(led_10, HIGH);
  digitalWrite(led_11, HIGH);
  digitalWrite(led_12, HIGH);

  delay(100); 

  digitalWrite(led_1, LOW);
  digitalWrite(led_2, LOW);
  digitalWrite(led_3, LOW);
  digitalWrite(led_4, LOW);
  digitalWrite(led_5, LOW);
  digitalWrite(led_6, LOW);
  digitalWrite(led_7, LOW);
  digitalWrite(led_8, LOW);
  digitalWrite(led_9, LOW);
  digitalWrite(led_10, LOW);
  digitalWrite(led_11, LOW);
  digitalWrite(led_12, LOW);
  
  
  // turn led's on/off in a row with 100 millisecond interval

  digitalWrite(led_1, HIGH);
  delay(100);
  digitalWrite(led_1, LOW);
  digitalWrite(led_2, HIGH);
  delay(100);
  digitalWrite(led_2, LOW);
  digitalWrite(led_3, HIGH);
  delay(100);
  digitalWrite(led_3, LOW);
  digitalWrite(led_4, HIGH);
  delay(100);
  digitalWrite(led_4, LOW);
  
  digitalWrite(led_5, HIGH);
  delay(100);
  digitalWrite(led_5, LOW);
  digitalWrite(led_6, HIGH);
  delay(100);
  digitalWrite(led_6, LOW);
  digitalWrite(led_7, HIGH);
  delay(100);
  digitalWrite(led_7, LOW);
  digitalWrite(led_8, HIGH);
  delay(100);
  digitalWrite(led_8, LOW);
  
  digitalWrite(led_9, HIGH);
  delay(100);
  digitalWrite(led_9, LOW);
  digitalWrite(led_10, HIGH);
  delay(100);
  digitalWrite(led_10, LOW);
  digitalWrite(led_11, HIGH);
  delay(100);
  digitalWrite(led_11, LOW);
  digitalWrite(led_12, HIGH);
  delay(100);
  digitalWrite(led_12, LOW);

  // wow  ... so much typing 
  // can you make it go backwards from 12 to 1? 

  
}
