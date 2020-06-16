/* $-way Traffic light system with RFID override by Ajith */
// PIN FORMAT : laneX ={redPin,yellowPin,greenPin}
int lane1[]={4,3,2};
int lane2[]={8,7,6};
int lane3[]={A2,A1,A0};
int lane4[]={A5,A4,A3};
#define R 0
#define Y 1
#define G 2
unsigned long previousMillis = 0;      
const long interval = 5000;           
char* rfid_id[]={"270021BEBE06"};
int i;
int seqNum=1;
void seq(int);
void state(int, int, int, int);
void chanegSignal(int *,int);

void setup(){
  Serial.begin(9600);
  for (int k=0;k<3;k++)pinMode(lane1[k],OUTPUT);
  for (int k=0;k<3;k++)pinMode(lane2[k],OUTPUT);
  for (int k=0;k<3;k++)pinMode(lane3[k],OUTPUT);
  for (int k=0;k<3;k++)pinMode(lane4[k],OUTPUT);   
}

void loop() {
  if(Serial.available()>0){
      char response[12];
      i=0;
      do{
          while(Serial.available()<=0);
          response[i]=Serial.read();
          Serial.print(response[i]);
          i++;
      }while(i<12);
      response[i]='\0';
      if(strcmp(response,rfid_id[0])==0) {
          seqNum=1; 
          Serial.print("\nFOUND 😄 ");
      }
  }
  unsigned long currentMillis = millis();   
  if(currentMillis - previousMillis >= interval){
    previousMillis = currentMillis; 
    if (seqNum>8) seqNum=1;
    seq(seqNum++);
  } 
}

void chanegSignal(int * lane,int Signal){
  for(int i=0;i<3;i++){
    int pin = *lane++;
    if (i == Signal) digitalWrite(pin,HIGH);
    else digitalWrite(pin,LOW);
  }
}
void state(int L1,int L2,int L3,int L4){
  chanegSignal(lane1,L1);
  chanegSignal(lane2,L2);
  chanegSignal(lane3,L3);
  chanegSignal(lane4,L4);
  delay(5000);
}

void seq(int stateSeq){
  switch(stateSeq){
    case 1:state(G,R,R,R);break;
    case 2:state(Y,Y,R,R);break;
    case 3:state(R,G,R,R);break;
    case 4:state(R,Y,Y,R);break;
    case 5:state(R,R,G,R);break;
    case 6:state(R,R,Y,Y);break;
    case 7:state(R,R,R,G);break;
    case 8:state(R,R,Y,Y);break;
  }
}
