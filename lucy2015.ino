// code here
// )

#include <SD.h>                      // need to include the SD library
#define SD_ChipSelectPin 10  //using digital pin 4 on arduino nano 328, can use other pins
#include <TMRpcm.h>           //  also need to include this library...
#include <SPI.h>
#define redLed 5
#define blueLed 6

TMRpcm tmrpcm;   // create an object for use in this sketch

void setup(){
  
 pinMode(redLed, OUTPUT);
 pinMode(blueLed, OUTPUT);

  tmrpcm.speakerPin = 9; //5,6,11 or 46 on Mega, 9 on Uno, Nano, etc

  if (!SD.begin(SD_ChipSelectPin)) {  // see if the card is present and can be initialized:
    Serial.println("SD fail");  
    return;   // don't do anything more if not
  }
  tmrpcm.play("5.wav"); //the sound file "music" will play each time the arduino powers up, or is reset
}



void loop(){  

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
