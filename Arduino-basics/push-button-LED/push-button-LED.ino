
int led_pin = 8;   // declaring pin 8 as led pin
int pushbutton = 2; // declaring pin 2 as pushbutton
void setup() {
  pinMode (led_pin , OUTPUT); // making led_pin as output
  pinMode (pushbutton ,INPUT); // making pushbutton as input 
}
void loop() {
 if ( digitalRead(pushbutton)==HIGH){  // reads the push button
      digitalWrite(led_pin,HIGH); // if push button is pressed LED turns ON
 }else {
    digitalWrite (led_pin,LOW); // else LED turns OFF  
  }
}
