#include <LiquidCrystal.h> //include LCD library (standard library)

LiquidCrystal lcd (A0, A1, A2, A3, A4 , A5); // pins of the LCD. (RS, E, D4, D5, D6, D7)
void setup() {
  // put your setup code here, to run once:
  lcd.begin(16, 2);
}

void loop() {
  // put your main code here, to run repeatedly:
  lcd.setCursor(0, 0);
  lcd.print("Sad ce kava");
  lcd.setCursor(0, 1);
  lcd.print(" Enter Password");
}
