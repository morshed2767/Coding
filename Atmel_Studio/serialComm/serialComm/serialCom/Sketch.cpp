/*Begining of Auto generated code by Atmel studio */
#include <Arduino.h>

/*End of auto generated code by Atmel studio */


//Beginning of Auto generated function prototypes by Atmel Studio
//End of Auto generated function prototypes by Atmel Studio

void setup() {
  Serial.begin(9600);
}

void loop() {
 while(Serial.available() == 0){};

 String value = Serial.readString();
 int val = value.toInt();
 Serial.print("\nDEC: ");
 Serial.println(val);
  Serial.print("BIN: ");
 Serial.println(val, BIN);
 Serial.print("OCT: ");
 Serial.println(val, OCT);
 Serial.print("HEX: ");
 Serial.println(val, HEX);
}
