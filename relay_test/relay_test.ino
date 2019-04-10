                       

#define RELAY1  2     
#define RELAY2  3                    
void setup()

{    


Serial.begin(9600);
  pinMode(RELAY1, OUTPUT);       
  pinMode(RELAY2, OUTPUT);
  digitalWrite(RELAY1,1);          // Turns Relay Off
  digitalWrite(RELAY2,1);
  delay(30000);
}

  void loop()

{

   digitalWrite(RELAY1,0);           // Turns ON Relays 1
   digitalWrite(RELAY2,0);
   Serial.println("Light ON");
   delay(2000);                                      // Wait 2 seconds

   digitalWrite(RELAY1,1);          // Turns Relay Off
   digitalWrite(RELAY2,1);
   Serial.println("Light OFF");
   delay(2000);
   
}
