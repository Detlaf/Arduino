/*
    The sample code for driving one way motor encoder.
    link:
       A pin -- digital 2
       B pin -- digital 4
       
    Beacuse of the interrupt port with different board, the following code is only used in UNO and mega2560.
    If you want to use Leonardo or Romeo,you should change digital pin 3 instead of digital pin 2.
    See the link for detail http://arduino.cc/en/Reference/AttachInterrupt
*/
#define SPEED_LEFT 6
#define SPEED_RIGHT 5
#define DIR_LEFT 7
#define DIR_RIGHT 4
#define SPEED 120

const byte encoder0pinA = 3;                  //A pin -> the interrupt pin 0
const byte encoder0pinB = 4;                  //B pin -> the digital pin 4
byte encoder0PinALast;
int duration;                                 //the number of the pulses
boolean Direction;                            //the rotation direction 

 
void setup(){  
  Serial.begin(57600);
  for (int i=4; i<=7; i++) {
    pinMode(i, OUTPUT);
  }
  EncoderInit();
}
 
void loop(){
  Serial.print("Pulse:");
  Serial.println(duration);
  duration = 0;
  delay(100);
  runForward();
}
 
void EncoderInit(){
  Direction = true;                            //default -> Forward  
  pinMode(encoder0pinB,INPUT);  
  attachInterrupt(0, wheelSpeed, CHANGE);
}
 
void wheelSpeed(){
  int Lstate = digitalRead(encoder0pinA);
  if((encoder0PinALast == LOW) && Lstate==HIGH){
    int val = digitalRead(encoder0pinB);
    if(val == LOW && Direction){
      Direction = false;                       //Reverse
    }
    else if(val == HIGH && !Direction){
      Direction = true;                        //Forward
    }
  }
  encoder0PinALast = Lstate;
  if(!Direction)  duration++;
  else  duration--;
}

void runForward() {
  analogWrite(SPEED_LEFT, SPEED);
  analogWrite(SPEED_RIGHT, SPEED);
  digitalWrite(DIR_LEFT, HIGH);
  digitalWrite(DIR_RIGHT, HIGH);
}
