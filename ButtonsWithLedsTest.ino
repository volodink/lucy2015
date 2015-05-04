#define button1 3
#define button2 4
#define button3 7

#define redLed 5
#define blueLed 6

int b1 = 0, b2, b3;

volatile int b1state = HIGH;
volatile int b2state = HIGH;
volatile int b3state = HIGH;

void setup() {
  // buttons
  pinMode(button1, INPUT);
  pinMode(button2, INPUT);
  pinMode(button3, INPUT); 
  
  pinMode(redLed, OUTPUT); 
  pinMode(blueLed, OUTPUT); 
  
  Serial.begin(9600);
  
  b1 = b2 = b3 = HIGH;
  
  attachInterrupt(0, blink, FALLING);
  
  Serial.print("Ready.\n");
}

void loop() {
  if (b1state == LOW){
    digitalWrite(redLed, HIGH);
  }
  else
    digitalWrite(redLed, LOW);
  
  if (b2state == LOW){
    digitalWrite(blueLed, HIGH);
  }
  else
    digitalWrite(blueLed, LOW);    
  
  delay(30);
}

void blink() {
  noInterrupts();
  b1 = digitalRead(button1);
  b2 = digitalRead(button2);
  b3 = digitalRead(button3);
  
  if (b1 == 0) {
    Serial.print("Button 1 pressed. ");
    Serial.print("Button state: ");
    if (b1state == HIGH){
      Serial.print("pressed.\n");
      b1state = !b1state;
    }
    else { 
       Serial.print("released.\n");
       b1state = !b1state;
     }
  }
 
  if (b2 == 0) { 
    Serial.print("Button 2 pressed. ");
    Serial.print("Button state: ");
    if (b2state == HIGH){
      Serial.print("pressed.\n");
      b2state = !b2state;
    }
    else { 
       Serial.print("released.\n");
       b2state = !b2state;
     }
  }
  
  if (b3 == 0) {
    Serial.print("Button 3 pressed. ");
    Serial.print("Button state: ");
    if (b3state == HIGH){
      Serial.print("pressed.\n");
      b3state = !b3state;
    }
    else { 
       Serial.print("released.\n");
       b3state = !b3state;
     }
  }
  
  interrupts();
}
