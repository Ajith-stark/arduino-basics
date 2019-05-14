//-------------------------------------------------------HECTOMINDS--------------------------------------------------//
//--------------------------------------------obstacle detection using ir sensor-------------------------------------//
//----------------------------------------------Copyright © 2019 by Hectominds---------------------------------------//

int ir_sensor = 3; // declaring pin 3 as IR sensor pin

void setup() {
  pinMode (ir_sensor,INPUT); // making IR sensor pin as input 
  Serial.begin(9600);
}
void loop() {
  if (digitalRead(ir_sensor)== HIGH){ // reads the IR sensor..
    Serial.println ("obstacle detected"); // serial prints if obstacle detected
  }else {
   Serial.println("no obstacle detected");   }// serial prints not detected
}
