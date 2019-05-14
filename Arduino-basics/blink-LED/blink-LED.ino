//-------------------------------------------------------HECTOMINDS--------------------------------------------------//
//------------------------------------------------------blinking LED-------------------------------------------------//
//----------------------------------------------Copyright © 2019 by Hectominds---------------------------------------//

int led_pin= 8;       // declaring pin 8 as led pin

void setup() {
  pinMode ( led_pin , OUTPUT);  // making led_pin as output
}
void loop() {
  digitalWrite(led_pin,HIGH);     // LED turns ON 
  delay (1000);                   // delay of one second
  digitalWrite (led_pin,LOW);     // LED turns OFF
  delay(1000);                    // delay of one second 
}
