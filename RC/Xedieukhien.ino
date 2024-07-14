#include "SoftwareSerial.h"
#include <Servo.h>
Servo servo;
SoftwareSerial HC05 (1, 0); //TX, RX
int ENA = 8;
int IN1 = 9;
int IN2 = 10;
int IN3 = 11;
int IN4 = 12;
int ENB = 13;

char dieu_khien;
int Speed = 250;

void setup() {
  HC05.begin(9600);
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
  pinMode(ENA, OUTPUT);
  pinMode(ENB, OUTPUT);

  analogWrite(ENA, Speed);
  analogWrite(ENB, Speed);

  servo.attach(7);
}

void loop() 
{
  if (HC05.available() > 0) 
  {
    dieu_khien = HC05.read();
    Serial.println(dieu_khien);
    switch (dieu_khien) 
    {
      case 'F':
        tien();
        Serial.print("Chay tien");
        break;
      case 'B':
        lui();
        Serial.print("Chay lui");
        break;
      case 'L':
        trai();
        Serial.print("Re trai");
        break;
      case 'R':
        phai();
        Serial.print("Re phai");
        break;
      case 'Q':
        trai();
        Serial.print("Re phai");
        break;
      case 'E':
        phai();
        Serial.print("Re phai");
        break;
      case 'C':
        lphai();
        Serial.print("Re phai");
        break;
      case 'Z':
        ltrai();
        Serial.print("Re phai");
        break;
      case 'S':
        Stop();
        Serial.print("Dung");
        break;
    }
  }
}


void tien() {
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  servo.write(90);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
}

void lui() {
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  servo.write(90);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
}

void ltrai() {
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  servo.write(55);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
}

void lphai() {
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  servo.write(115);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
}
void trai() {
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  servo.write(55);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
}

void phai() {
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  servo.write(115);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
}
void Stop() {
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  servo.write(90);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
}
