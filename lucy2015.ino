#include <SD.h>                      // need to include the SD library
#define SD_ChipSelectPin 10  //using digital pin 4 on arduino nano 328, can use other pins
#include <TMRpcm.h>           //  also need to include this library...
#include <SPI.h>
#define redLed 5
#define blueLed 6

TMRpcm tmrpcm;   // create an object for use in this sketch

 int b1, b2, b3;

void setup(){
  
 pinMode(2, INPUT);
 
  
 pinMode(redLed, OUTPUT);
 pinMode(blueLed, OUTPUT);

Serial.begin(9600);

  tmrpcm.speakerPin = 9; //5,6,11 or 46 on Mega, 9 on Uno, Nano, etc

  if (!SD.begin(SD_ChipSelectPin)) {  // see if the card is present and can be initialized:
    Serial.println("SD fail");  
    return;   // don't do anything more if not
  }
  tmrpcm.play("oi.wav"); //the sound file "music" will play each time the arduino powers up, or is reset

}




void loop(){  

  // red
  //digitalWrite(redLed, HIGH);
  //delay(1000);
  //digitalWrite(redLed, LOW);
  //delay(1000);

  // blue
  //digitalWrite(blueLed, HIGH);
  //delay(1000);
  //digitalWrite(blueLed, LOW);
  //delay(1000);

  // purple? :)))
  //digitalWrite(redLed, HIGH);
  //digitalWrite(blueLed, HIGH);
  //delay(1000);
  //digitalWrite(redLed, LOW);
  //digitalWrite(blueLed, LOW);
  //delay(1000); 
 
  //Serial.println(analogRead(1));  
  //delay(250);
  
  b1 = digitalRead(2);
  
  
  if (b1 == 0)
  {
   
      Serial.println(analogRead(0));  
      delay(250);
    
    digitalWrite(redLed, HIGH);
    delay(5000);
    digitalWrite(redLed, LOW);

    // tmrpcm.play("gate.wav");
  }
  
 delay(25);
  
  b2 = digitalRead(3);
  if (b2 == 0)
  {
    Serial.println(analogRead(1));  
    delay(250);
    
    digitalWrite(blueLed, HIGH);
    delay(5000);
    digitalWrite(blueLed, LOW);
    
    // tmrpcm.stopPlayback();
  }
 
 b3 = digitalRead(4);
  if (b3 == 0)
  {
  tmrpcm.play("nyan.wav");
  }
 
 
  
}
