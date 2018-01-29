void setup() {
  Serial.begin(9600);
}

void loop() {
  while(Serial.available() == 0){};

  String value = Serial.readString();
  int val = value.toInt();
  Serial.println(val);
  
  Serial.println(val, BIN);
  Serial.println(val, OCT);
  Serial.println(val, HEX);
}
