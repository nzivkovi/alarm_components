#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27,20,4);
int analogInput = 0;
float vout = 0.0;
float vin = 0.0;
float R1 = 100000.0; // resistance of R1 (100K)
float R2 = 10000.0; // resistance of R2 (10K)
int value = 0;
void setup() {
  lcd.init();
  Serial.begin(9600);
  pinMode(analogInput, INPUT);
  lcd.backlight();
  lcd.setCursor(2, 0);
  lcd.print("DC VOLTMETER");
  delay(3000);
  lcd.clear();

}
void loop() {
  lcd.print("DC Voltmeter");
  // read the value at analog input
  value = analogRead(analogInput);
  //Serial.print("value: ");
  //Serial.println(value);
  vout = (value * 5.0) / 1024.0;
  vin = vout / (R2 / (R1 + R2));
  //Serial.print("vin: ");
  //Serial.println(vin);
  if (vin < 0.09)
  {
    vin = 0.0;
  }
  lcd.setCursor(0, 1);
  lcd.print("Voltage V :");
  lcd.print(vin);
  delay(500);
  lcd.clear();
}
