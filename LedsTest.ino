// Leds Definition
#define redLed 5
#define blueLed 6

void setup() {
  pinMode(redLed, OUTPUT);
  pinMode(blueLed, OUTPUT);
}

void loop() {
  // red
  digitalWrite(redLed, HIGH);
  delay(1000);
  digitalWrite(redLed, LOW);
  delay(1000);

  // blue
  digitalWrite(blueLed, HIGH);
  delay(1000);
  digitalWrite(blueLed, LOW);
  delay(1000);

  // purple? :)))
  digitalWrite(redLed, HIGH);
  digitalWrite(blueLed, HIGH);
  delay(1000);
  digitalWrite(redLed, LOW);
  digitalWrite(blueLed, LOW);
  delay(1000); 
}
