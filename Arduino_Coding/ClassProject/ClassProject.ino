#include <LiquidCrystal.h>
LiquidCrystal lcd(7, 6, 5, 4, 3, 2);
//Variables
int temp = A5;
int led = 12;
int ldr = A4;
int mt1 = 11;
int mt2 = 10;

//SetUp
void setup() {
  lcd.begin(16, 2);
  pinMode(temp, INPUT);
  pinMode(led, OUTPUT);
  pinMode(mt1, OUTPUT);
  pinMode(mt2, OUTPUT);
  pinMode(ldr, INPUT);
}

void loop() {
  //Reading temperature
  float val = analogRead(temp);
  float mv = (val/1024)*5000;
  float tempcel = mv/10;

  //Reading LDR & Controling Led
  float light = analogRead(A4);
  lcd.setCursor(0, 1);
  lcd.print(light);
  if(light<=300){
    lcd.setCursor(8, 1);
    lcd.print("Led ON");
    digitalWrite(led, HIGH);
  }else{
    lcd.setCursor(8, 1);
    lcd.print("Led OFF");
    digitalWrite(led, LOW);
  }
  

  //Controlling Motor
  lcd.setCursor(0, 0);
  lcd.print(tempcel);
  lcd.print("C");
  if(tempcel>20 && tempcel <30){
    lcd.setCursor(7, 0);
    lcd.print("Fan: 50%");
    analogWrite(mt1, 128);
    digitalWrite(mt2, LOW);
  }else if(tempcel>=30){
    lcd.setCursor(7, 0);
    lcd.print("Fan: 100%");
    analogWrite(mt1, 255);
    digitalWrite(mt2, LOW);
  }
  else{
    lcd.setCursor(8, 0);
    lcd.print("Fan OFF");
    digitalWrite(mt1, LOW);
  }
  delay(5);
  lcd.clear();

}
