//#include "SIM900.h"
//#include <SoftwareSerial.h>
//If not used, is better to exclude the HTTP library,
//for RAM saving.
//If your sketch reboots itself proprably you have finished,
//your memory available.
//#include "inetGSM.h"

//If you want to use the Arduino functions to manage SMS, uncomment the lines below.
#include "sms.h"
SMSGSM sms;

//To change pins for Software Serial, use the two lines in GSM.cpp.

//GSM Shield for Arduino
//www.open-electronics.org
//this code is based on the example of Arduino Labs.

//Simple sketch to send and receive SMS.

char pos;
boolean started=false;
char smsbuffer[41];
char n[20];
char* Numbers[3] = {"0038763916334", "0038763498403", ""};
void setup() 
{
  //Serial connection.
  Serial.begin(9600);
  Serial.println("GSM Shield testing.");
  //Start configuration of shield with baudrate.
  //For http uses is raccomanded to use 4800 or slower.
  if (gsm.begin(2400)){
    Serial.println("\nstatus=READY");
    started=true;  
  }
  else Serial.println("\nstatus=IDLE");
  if(started){
    //Enable this two lines if you want to send an SMS.
    //if(sms.SendSMS(Numbers[0], "Arduino SMS"))
      //Serial.println("\nSMS sent OK");
  }
};

void loop() {
  if(started){
    //Read if there are messages on SIM card and print them.
    pos = sms.IsSMSPresent(SMS_ALL);
    Serial.println(pos,DEC);
    if(sms.GetSMS(pos,n,smsbuffer,41)){
      Serial.print("sms.GetSMS(pos,n,smsbuffer, 160): ");
      Serial.println(sms.GetSMS(pos,n,smsbuffer, 160), DEC);
      Serial.print("n: ");
      Serial.println(n);
      Serial.print("smsbuffer: ");
      Serial.println(smsbuffer);
      memset(smsbuffer, 0, sizeof(smsbuffer));
      sms.DeleteSMS(pos);
    }
    delay(1000);
  }
};
