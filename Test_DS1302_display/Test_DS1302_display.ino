//This code is to use with DS1302 RTC module, it permits you to setup the actual time and date
//And you can visualize them on the LCD i2c screen
//This code is a modified version of the code provided in virtuabotixRTC library

#include <virtuabotixRTC.h> //Libraries needed
#include <LiquidCrystal_I2C.h>

//Wiring VCC -> 5+, GND -> GND, SDA -> GPIO18, SCL -> GPIO19 (Arduino Uno)
LiquidCrystal_I2C lcd(0x27, 16, 2);   // adress and format LCD

//Wiring CLK -> 4 , DAT ->3, Reset -> 2, VCC -> 5+, GND -> GND

//virtuabotixRTC myRTC(4, 3, 2); //If you change the wiring change the pins here also
virtuabotixRTC myRTC(A2, A1, A0);



void setup() {
  Serial.begin(9600);
  lcd.init();                         // init LCD
  lcd.backlight();
  lcd.home();
  lcd.setCursor(4, 0);                // place static text
  lcd.print("Welcome");
  myRTC.setDS1302Time(30, 47, 01, 5, 8, 8, 2018); //Here you write your actual time/date as shown above 
  //but remember to "comment/remove" this function once you're done as I did
  //The setup is done only one time and the module will continue counting it automatically
 
}

void loop() {
 lcd.clear(); //Here after clearing the LCD we take the time from the module and print it on the screen with usual LCD functions
 myRTC.updateTime();
 lcd.setCursor(0,0);
 lcd.print(myRTC.dayofmonth);
 lcd.print(".");
 lcd.print(myRTC.month);
 lcd.print(".");
 lcd.print(myRTC.year);
 lcd.setCursor(0,1);
 lcd.print(myRTC.hours);
    
 lcd.print(":");
 lcd.print(myRTC.minutes);
 lcd.print(":");
 lcd.print(myRTC.seconds);
 delay(1000);
}
