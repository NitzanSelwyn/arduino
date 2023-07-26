
int buttonState = 0;
int buttonPin = 4;

void setup() {
pinMode(12,OUTPUT);
pinMode(buttonPin,OUTPUT);
}

void loop() {
  buttonState = digitalRead(buttonPin);
  if (buttonState == HIGH){
    digitalWrite(12,HIGH);
  } else{
    digitalWrite(12,LOW);
  }
// 
// delay(100);
// 
// delay(100);
}
