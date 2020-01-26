#define SENSOR_LINE_PIN 7
 
void setup() {
  // открываем последовательный порт
  pinMode(SENSOR_LINE_PIN, INPUT);
  Serial.begin(9600);
}
 
void loop() {
  // считываем значение с датчика
  bool signal = digitalRead(SENSOR_LINE_PIN);
  if ( !signal ) {
    // если сигнал ноль
    // выдаем предупреждение
    Serial.println("Warning! Out of table!");
  } else {
    // если сигнал единица
    Serial.println("OK! Above table!");
  }
 
  delay(100);
}
