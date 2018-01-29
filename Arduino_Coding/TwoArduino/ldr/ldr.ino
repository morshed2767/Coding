void setup() {
  pinMode(A7, INPUT);
  Serial.begin(9600);

}

void loop() {
  // put your main code here, to run repeatedly:
  int val  = analogRead(A7);
  Serial.println(val);
  delay(1000);

}
