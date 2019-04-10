#include <Keypad.h> //include keypad library - first you must install library (library link in the video description)

const byte rows = 4; //number of the keypad's rows and columns
const byte cols = 4;

char keyMap [rows] [cols] = { //define the cymbols on the buttons of the keypad

  {'1', '2', '3', 'A'},
  {'4', '5', '6', 'B'},
  {'7', '8', '9', 'C'},
  {'*', '0', '#', 'D'}
};

byte rowPins [rows] = {3, 4, 5, 6}; //pins of the keypad
byte colPins [cols] = {7, 8, 9, 10};

Keypad myKeypad = Keypad( makeKeymap(keyMap), rowPins, colPins, rows, cols);

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  char whichKey = myKeypad.getKey(); //define which key is pressed with getKey
  if (whichKey != NO_KEY) {
    Serial.println(whichKey); 
  }
}
