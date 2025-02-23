#include<Servo.h>
Servo rotate;
int trig=6;
int echo=A0;
int led1=2;
int led2=3;
int led3=4;
int led4=5;
int led5=7;
int led6=8;

void setup() {
 Serial.begin(9600);
  pinMode(trig,OUTPUT);
  pinMode(led1,OUTPUT);
  pinMode(led2,OUTPUT);
  pinMode(led3,OUTPUT);
  pinMode(led4,OUTPUT);
  pinMode(led5,OUTPUT);
  pinMode(led6,OUTPUT);
  pinMode(echo,INPUT);
  rotate.attach(9);
}

void loop() {
  digitalWrite(led1,LOW);
  digitalWrite(led2,LOW);
  digitalWrite(led3,LOW);
  digitalWrite(led4,LOW);
  digitalWrite(led5,LOW);
  digitalWrite(led6,LOW);
  int angle;
  int duration;
  int dist;
  for(angle=0;angle<=180;angle++){
    rotate.write(angle);
    delay(10);
    
dist=distance();
  Serial.print(dist);
  Serial.print("\n");
  if(angle<=30&&dist<10)
  digitalWrite(led6,HIGH);
  
  if(angle<=60&&dist<15)
  digitalWrite(led5,HIGH);
  
  else if(angle<=90&&dist<25)
  digitalWrite(led4,HIGH);
  
  else if(angle<=120&&dist<25)
  digitalWrite(led3,HIGH);
  
  else if(angle<=150&&dist<25)
  digitalWrite(led2,HIGH);
  
  else if(angle<=180&&dist<25)
  digitalWrite(led1,HIGH);

}
  
    for(angle=180;angle>=0;angle--){
    rotate.write(angle);
    delay(10);
  dist=distance();
  if(angle<=30&&dist<10)
  digitalWrite(led6,HIGH);
  
  if(angle<=60&&dist<7)
  digitalWrite(led5,HIGH);
  
  else if(angle<=90&&dist<25)
  digitalWrite(led4,HIGH);
  
  else if(angle<=120&&dist<25)
  digitalWrite(led3,HIGH);
  
  else if(angle<=150&&dist<25)
  digitalWrite(led2,HIGH);
  
  else if(angle<=180&&dist<25)
  digitalWrite(led1,HIGH);
  }

}
int distance(){
  int dist,duration;
  digitalWrite(trig,LOW);
  delayMicroseconds(5);
  digitalWrite(trig,HIGH);
  delayMicroseconds(10);
  digitalWrite(trig,LOW);
  duration=pulseIn(echo,HIGH);
  dist=duration*0.034/2;

return dist;
}
