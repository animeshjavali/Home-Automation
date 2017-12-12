int data;
void setup() {
  Serial.begin(9600);
  pinMode(13,OUTPUT);
}

void loop() {
  if(Serial.available()>0)
  {
  data=Serial.parseInt();
  if(data==1)
  digitalWrite(13,HIGH);
  else if(data==2)
  digitalWrite(13,LOW);

  }
  
  }// put your main code here, to run repeatedly:


