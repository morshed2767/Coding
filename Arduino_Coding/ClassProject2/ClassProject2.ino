#include <LiquidCrystal.h>
LiquidCrystal lcd(8, 7, 6, 5, 4, 3);

//Pin defination
int tempIncrease = 12;
int tempSet = 11;
int tempDecrease = 10;
int led = 9;
int temp = A5;
int setValue = 0;
int varValue = 0;
int prevState = 0;
int inV = 0;

void setup() {
  lcd.begin(16, 2);
  pinMode(tempIncrease, INPUT);
  pinMode(tempSet, INPUT);
  pinMode(tempDecrease, INPUT);
  pinMode(temp, INPUT);
  pinMode(led, OUTPUT);

}

void loop() {
   //Reading temperature
  float val = analogRead(temp);
  float mv = (val/1024)*5000;
  int tempcel = (int)(mv/10);

  inV = digitalRead(12);
  if(inV != prevState){
    if(inV == HIGH){
        varValue +=1;
     }
     delay(50);
  }
  inV = prevState;
  
//  lcd.setCursor(0, 0);
//  lcd.print("Temp:");
//  lcd.print(tempcel);

  //Increasing value
  lcd.setCursor(0, 1);
  lcd.print("Vtemp:");
  lcd.print(varValue);

//  lcd.setCursor(9, 1);
//  lcd.print("STemp:");
//  lcd.print(setValue);
//  
  delay(5);
  lcd.clear();
}
