#include <SoftwareSerial.h>
SoftwareSerial mySerial(5,6);//Arduino's(RX,TX).

void ReceiveMsg();


void setup()
{
 Serial.begin(9600);//Start Serial communication.
 mySerial.begin(9600);//Start GSM communication.
 pinMode(9,OUTPUT);
 ReceiveMsg();
}

void loop() 
{
  while(mySerial.available()==0);//Wait until the command to switch ON the LED is received.
    
  while(mySerial.parseInt()!=1)
  {
   
     Serial.println("send an sms to turn on the LED");//prompt the user to send the command.
     delay(1000);
    }
 
 Serial.println("LED IS ON");//Send "1" to turn the LED on.
 digitalWrite(9,HIGH);
 
 while(mySerial.parseInt()!=2);
  
 Serial.println("LED IS OFF");//Send "2" to turn the LED off. 
 digitalWrite(9,LOW);
    
while(1);
}
void ReceiveMsg()
{
  mySerial.println("AT+CNMI=2,2,0,0,0");//AT command to receive a live sms.
  Serial.println("READY TO RECEIVE A LIVE SMS");
 }

