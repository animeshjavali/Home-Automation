#include <SPI.h>
#include <BlynkSimpleEsp8266.h>

int j ;
char *ssid="WiFi_NETWORK_NAME";
char *pass="WiFi_PASSWORD";
char *auth = "f788d57d563942378dc4401cfe488d37";//Unique authentication token given by blynk.

void setup() {
Serial.begin(115200);
delay(100);

pinMode(D2,OUTPUT);
pinMode(D3,OUTPUT);
pinMode(D4,OUTPUT);// Set outpins on NodeMCU.
pinMode(D5,OUTPUT);
pinMode(D6,OUTPUT);

Blynk.begin(auth, ssid, pass);// start blynk server.
delay(100);
}

 BLYNK_WRITE(V1)
{
 j = param.asInt();//Parse data from Blynk android app to select an LED.
 Serial.print("LED ");
Serial.print(j);
Serial.println(" is selected");
}
 BLYNK_WRITE(V0)
{
int i = param.asInt();//Parse data from Blynk android app to control an LED.

if(j==1){ 
if(i == 1){
digitalWrite(D2, HIGH);
Serial.print("LED ");
Serial.print(j);
Serial.println(" is turned ON");
}
else if(i == 0){
digitalWrite(D2, LOW);
Serial.print("LED ");
Serial.print(j);
Serial.println(" is turned OFF");
}
}
if(j==2){ 
if(i == 1){
digitalWrite(D3, HIGH);
Serial.print("LED ");
Serial.print(j);
Serial.println(" is turned ON");
}
else if(i == 0){
digitalWrite(D3, LOW);
Serial.print("LED ");
Serial.print(j);
Serial.println(" is turned OFF");
}
}
if(j==3){ 
if(i == 1){
digitalWrite(D4, HIGH);
Serial.print("LED ");
Serial.print(j);
Serial.println(" is turned ON");
}
else if(i == 0){
digitalWrite(D4, LOW);
Serial.print("LED ");
Serial.print(j);
Serial.println(" is turned OFF");
}
}
if(j==4){ 
if(i == 1){
digitalWrite(D5, HIGH);
Serial.print("LED ");
Serial.print(j);
Serial.println(" is turned ON");
}
else if(i == 0){
digitalWrite(D5, LOW);
Serial.print("LED ");
Serial.print(j);
Serial.println(" is turned OFF");
}
}
if(j==5){ 
if(i == 1){
digitalWrite(D6, HIGH);
Serial.print("LED ");
Serial.print(j);
Serial.println(" is turned ON");
}
else if(i == 0){
digitalWrite(D6, LOW);
Serial.print("LED ");
Serial.print(j);
Serial.println(" is turned OFF");
}
}
}

void loop() {
 Blynk.run();// Runs in an infinite loop.
}
