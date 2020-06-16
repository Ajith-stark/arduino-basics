
int pushbutton = 2; // declaring pin 2 as pushbuttonpin

void setup() {
  pinMode (pushbutton ,INPUT); // making pushbutton pin as input 
  Serial.begin(9600); // setting serial monitor at 9600 baud rate
}
void loop() {
 if ( digitalRead(pushbutton)==HIGH){ //if button is pressed
    Serial.println ("button is pressed");// prints  button is pressed
 }else {
    Serial.println ("button is not_pressed"); // prints  button is not pressed
  }  
 }
