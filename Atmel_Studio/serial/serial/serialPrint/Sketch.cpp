/*Begining of Auto generated code by Atmel studio */
#include <Arduino.h>

/*End of auto generated code by Atmel studio */


//Beginning of Auto generated function prototypes by Atmel Studio
//End of Auto generated function prototypes by Atmel Studio

void setup() {
  Serial.begin(9600);
  Serial.print("Hello\n");
  delay(1000);
  

}

void loop() {
  // put your main code here, to run repeatedly:
  int i=23;
  Serial.print(i);
  Serial.print("\n");
  delay(1000);
  Serial.print(i, OCT);
  Serial.print("\n");
  delay(1000);
  Serial.print(i, HEX);
  Serial.print("\n");
  delay(1000);
  Serial.print(i, BIN);
  Serial.print("\n");
  delay(1000);

}
