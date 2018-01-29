#define SW A0
unsigned long time;
unsigned long pre_time, cur_time;

void setup() {
  Serial.begin(9600);
  pinMode(SW, INPUT);
  digitalWrite(SW, HIGH); //PULL UP the switch
}

void loop() {
  Serial.println("TIME: ");
  if(digitalRead(SW)==0)
  pre_time = millis();
  cur_time = millis()-pre_time;
  Serial.println(cur_time);
  delay(1000);

}
