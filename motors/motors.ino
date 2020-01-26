#define SPEED_LEFT 6
#define SPEED_RIGHT 5
#define DIR_LEFT 7
#define DIR_RIGHT 4
#define SPEED 235

void runForward() {
  analogWrite(SPEED_LEFT, SPEED);
  analogWrite(SPEED_RIGHT, SPEED);
  digitalWrite(DIR_LEFT, HIGH);
  digitalWrite(DIR_RIGHT, HIGH);
}

void setup() {
  // put your setup code here, to run once:
  for (int i=4; i<=7; i++) {
    pinMode(i, OUTPUT);
  }
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  runForward();
}
