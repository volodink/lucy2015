int button1 = 3;
int button2 = 4;
int button3 = 7;

volatile int led1state = LOW;
volatile int led2state = LOW;
volatile int led1OffState = LOW;

void setup() {
  // leds
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  
  // buttons
  pinMode(button1, INPUT);
  pinMode(button2, INPUT);
  pinMode(button3, INPUT); 
  
  attachInterrupt(0, blink, FALLING);
}

void loop() {
  digitalWrite(5, led1state);
  digitalWrite(6, led2state);
  delay(15);
}

void blink() {
  int b1 = digitalRead(button1);
  int b2 = digitalRead(button2);
  int b3 = digitalRead(button3);
  
  if (b1 == 0) {
    led1state = 1;
    led2state = 0;
  }
 
  if (b2 == 0) { 
    led1state = 0;
    led2state = 1;
  }
  
  if (b3 == 0) {
    led1state = 1;
    led2state = 1;
  }
  
  b1 = b2 = b3 = HIGH;
}
