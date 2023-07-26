
int buttonState = 0;
int buttonPin = 4;

void setup() {
  pinMode(12,OUTPUT);
  pinMode(buttonPin,OUTPUT);
}

void loop() {
  buttonState = digitalRead(buttonPin);
  delay(100);
  if (buttonState == HIGH){
    // play sound on a loop
  } else{
    // stop play sound
  }
}
