//#include <LiquidCrystal.h> //include LCD library (standard library)
#include <LiquidCrystal_I2C.h> //include LCD I2C library (standard library)
#include <Keypad.h> //include keypad library - first you must install library (library link in the video description)

const byte rows = 4; //number of the keypad's rows and columns
const byte cols = 4;

char keyMap [rows] [cols] = { //define the cymbols on the buttons of the keypad

  {'1', '2', '3', 'A'},
  {'4', '5', '6', 'B'},
  {'7', '8', '9', 'C'},
  {'*', '0', '#', 'D'}
};

byte rowPins [rows] = {3, 4, 5, 6};//{10, 9, 8, 7}; //pins of the keypad
byte colPins [cols] = {7, 8, 9, 10};//{6, 5, 4, 3};

char mystr[16]; //String data
String temp = "";

Keypad myKeypad = Keypad( makeKeymap(keyMap), rowPins, colPins, rows, cols);
//LiquidCrystal lcd (A0, A1, A2, A3, A4, A5); // pins of the LCD. (RS, E, D4, D5, D6, D7)
LiquidCrystal_I2C lcd (0x27, 16, 2); // 

void setup(){
  Serial.begin(9600);
  //lcd.begin(16, 2); // standard wiring
  lcd.init(); // With I2C module
  lcd.backlight(); // With I2C module
  lcd.setCursor(4,0);
  lcd.print("Welcome");
}

void loop(){
  char whichKey = myKeypad.getKey(); //define which key is pressed with getKey
  delay(1);
  if (whichKey != NO_KEY) {
    if (whichKey == 'D') {
      unsigned int len = String(mystr).length();
      temp = String(mystr);
      temp.remove(len - 1);
      temp.toCharArray(mystr,16);
      lcd.clear();
      lcd.print(mystr);
      Serial.println(mystr);
    } else {
      temp = String(mystr);
      temp += whichKey;
      temp.toCharArray(mystr,16);
      lcd.clear();
      lcd.print(mystr);
      Serial.println(mystr);
    }
  }  
}
  

