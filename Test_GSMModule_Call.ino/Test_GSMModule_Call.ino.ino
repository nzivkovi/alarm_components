#include "call.h"

#define NUMBERS_TO_CALL 20

//Sketch to make phone call on trigger wich can be triggered with magnetic sensor

CallGSM call;

char number1[NUMBERS_TO_CALL] = "0038763916334";
unsigned long time1; //watching time
unsigned long time2; //watching time

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  Serial.println("GSM Shield testing.");
  if (gsm.begin(2400)){
    Serial.println("\nstatus=READY");
  }
  else{
    Serial.println("\nstatus=IDLE");
  }
  //Serial.print("Call status 2: ");
  //Serial.println(call.CallStatus());
  Serial.print("call.CallStatus() == 0: ");
  Serial.println(call.CallStatus() == 0);
  while(call.CallStatus() != 1){
    call.Call(number1);
  }
  /*time1 = millis();
  while(call.CallStatus() == 0){
    Serial.print("Call status: ");
    Serial.println(call.CallStatus());
  }
  Serial.print("millis() - time1: ");
  Serial.println(millis() - time1);
  time1 = millis();
  while(call.CallStatus() == 1 && millis() - time1 < 10001){}
  call.HangUp();*/
  Serial.print("call.CallStatus(): ");
  Serial.println(call.CallStatus());
  //Serial.print("millis() - time1: ");
  //Serial.println(millis() - time1);
}

void loop() {
  // put your main code here, to run repeatedly:
  /*Serial.print("Call status 1: ");
  Serial.println(call.CallStatus());
  if (gsm.begin(2400)){
    Serial.println("\nstatus=READY");
  }
  else{
    Serial.println("\nstatus=IDLE");
  }
  call.Call((char *)number1);
  Serial.print("Call status: ");
  Serial.println(call.CallStatus());*/
}
