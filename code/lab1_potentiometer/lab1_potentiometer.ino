
int pot = 0;
int reading;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  reading = analogRead(pot);
  Serial.print("Reading: ");
  Serial.println(pot);

  delay(1000);
}
