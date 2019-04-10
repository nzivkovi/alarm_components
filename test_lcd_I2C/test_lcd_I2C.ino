#include <LiquidCrystal_I2C.h>

int i = 0;

LiquidCrystal_I2C lcd(0x27,16,2);

void setup() {
  // put your setup code here, to run once:
  lcd.init();
  Serial.begin(9600);
  lcd.backlight();
  lcd.setCursor(2, 0);
  lcd.print("Test");
  delay(3000);
  lcd.clear();
}

void loop() {
  // put your main code here, to run repeatedly:
  lcd.print("Vrtim u loop-u");
  lcd.setCursor(5, 1);
  lcd.print("i = ");
  lcd.setCursor(9, 1);
  lcd.print(i);
  i++;
  delay(3000);
  lcd.clear();
}
