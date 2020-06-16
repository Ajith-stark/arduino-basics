
int pushbutton = 7; // declaring pin 7 as pushbutton pin
int relay = 3;    // declaring pin 3 as relay pin

void setup() {
  pinMode (pushbutton ,INPUT); // making pushbutton pin as input 
  pinMode (relay , OUTPUT);   }
  
void loop() {
  if (digitalRead(pushbutton) == HIGH) {
    digitalWrite(relay,HIGH);
    }else {
    digitalWrite(relay,LOW); }  
  }
