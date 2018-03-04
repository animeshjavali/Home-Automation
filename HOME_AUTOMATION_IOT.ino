int data;
void setup() {
  Serial.begin(9600);
  pinMode(13,OUTPUT);
}

void loop() {
  if(Serial.available()>0)// Check for data.
  {
  data=Serial.parseInt();// Get data as integer.
  if(data==1)
  digitalWrite(13,HIGH);// Turn on an LED if sent data is 1.
  else if(data==2)
  digitalWrite(13,LOW);// Turn off the LED if sent data is 2.
  }
}


