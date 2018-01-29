
#include <LiquidCrystal.h>
LiquidCrystal lcd(9, 8, 7, 6, 5, 4);
void setup() {
  lcd.begin(16,2);
  //lcd.print("Hello, World!");

}

void loop() {
  lcd.setCursor(5,0);
  lcd.print("MORSHED");
  lcd.setCursor(7,1);
  lcd.print("KHAN");
 /* for(int i=1; i<=9; i++){
    lcd.print(i);
    delay(200);
  }
  lcd.setCursor(16,1);
  lcd.print("123456789");
  
  for(int i=0; i<16; i++){
    lcd.scrollDisplayRight();
    delay(100);
  }
  lcd.clear();*/
  
  /*for(int j=0; j<29; j++){
    lcd.scrollDisplayLeft();
   delay(100);
  }*/
}
