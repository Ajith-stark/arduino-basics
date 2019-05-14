//-------------------------------------------------------HECTOMINDS--------------------------------------------------//
//------------------------------------------------speed control of  motor------------------------------------------//
//----------------------------------------------Copyright © 2019 by Hectominds---------------------------------------//

int pot=A0; // declaring pot pin 
int motor= 5; // declaring output for motor
int val;  // variable is used to store value
void setup() {
    pinMode(motor,OUTPUT); // declaring output for motor
    pinMode(pot, INPUT); // declaring pot pin as input 
}
void loop() {
   val= analogRead(pot); // read the pot value
   val = map(val,0,1023,0,255); // map pot values to pwm value
   delay(100); // delay is used for not to overloading
   analogWrite(motor,val); // pmw output is generated
}
