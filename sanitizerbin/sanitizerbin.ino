#include <Servo.h>
Servo servo;
int trig = 13;
int echo = 12;
long dist;
long timet;
 
void setup() 
{
  servo.attach(9); 
  pinMode(trig, OUTPUT);
  pinMode(echo, INPUT);
}
 
void loop() {
  ultraSonic();
  servo.write(0);
  if(dist >=0 && dist <= 10){
  servo.write(90);
  }
}
 
void ultraSonic(){
  digitalWrite(trig, LOW);
  delayMicroseconds(2);
  digitalWrite(trig, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig, LOW);
  timet = pulseIn(echo, HIGH);
  dist = timet*0.034/2;
  }
