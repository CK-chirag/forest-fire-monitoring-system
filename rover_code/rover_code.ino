#include <Servo.h>
Servo s1;
Servo s2;

int in1 = 5;
int in2 = 6;
int in3 = 10;
int in4 = 11;

char data;

void setup()
{
  pinMode(5,OUTPUT);
  pinMode(6,OUTPUT);
  pinMode(10,OUTPUT);
  pinMode(11,OUTPUT);
  s1.attach(9);
  s2.attach(12);
  Serial.begin(9600);
}

void loop()
{

  while(Serial.available() > 0)
  {
    data = Serial.read();
    Serial.println(data);    //Uncomment this line to print the incomming data
  }

    if(data == 'F')
    {
      digitalWrite(5,LOW);
      digitalWrite(6,HIGH);

      digitalWrite(10,LOW);
      digitalWrite(11,HIGH);
    }
    else if(data == 'B')
    {
      for (int i = 0 ; i<=180; i+=1) {
        s1.write(i);
        delay(15);

      }
      for (int i = 180 ; i>=0; i-=1) {
        s1.write(i);
        delay(15);
      }
      s2.write(0);
      delay(12000);
      s2.write(90);
      delay(1000);
    }
    else if(data == 'R')
    {
      digitalWrite(5,LOW);
      digitalWrite(6,HIGH);

      digitalWrite(10,HIGH);
      digitalWrite(11,LOW);
    }
    else if(data == 'L')
    {
      digitalWrite(5,HIGH);
      digitalWrite(6,LOW);

      digitalWrite(10,LOW);
      digitalWrite(11,HIGH);
    }
    else if(data == 'S')
    {
      digitalWrite(5,LOW);
      digitalWrite(6,LOW);

      digitalWrite(10,LOW);
      digitalWrite(11,LOW);
    }
}