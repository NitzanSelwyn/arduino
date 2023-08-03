#include "SoftwareSerial.h"
#include "DFRobotDFPlayerMini.h" 

// Declare the MP3 module
SoftwareSerial mySoftwareSerial(10, 11);
DFRobotDFPlayerMini mp3module;

int buttonState = 0;
int buttonPin = 4;

void setup() {
  Serial.begin(9600);
  mySoftwareSerial.begin(9600);

  pinMode(12,OUTPUT);
  pinMode(buttonPin,OUTPUT);
  // pinMode(10,OUTPUT);


  if (!mp3module.begin(mySoftwareSerial)) { 
    Serial.println("Unable to connect to module!");
    Serial.println("Check cable connections and");
    Serial.println("make sure SD Card is inserted");
    while(1);
  }
  
  Serial.println("Succesfully connected to DFPlayer Mini");
  
  mp3module.setTimeOut(100); // Set serial communictaion time out to 500 ms
  mp3module.volume(20);  //Set volume value (0-30).
  mp3module.EQ(DFPLAYER_EQ_NORMAL); // Set equalization to normal
  mp3module.outputDevice(DFPLAYER_DEVICE_SD); // Read music from MicroSD card
  
  delay(100);

}

void loop() {
  buttonState = digitalRead(buttonPin);
    Serial.println(buttonState);

  delay(100);
  if (buttonState == HIGH){
    mp3module.play(1);
    // play sound on a loop
  } else{
    delay(100);
    // stop play sound
  }
  delay(100);

}
