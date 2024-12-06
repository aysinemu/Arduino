#include "SoftwareSerial.h"
#include <Servo.h>
SoftwareSerial HC05 (0, 1); //TX, RX
Servo servo;
int IN3 = 6;
int IN4 = 5;
int ENB = 3;
char dieu_khien;
int SpeedDK = 255;

void setup() {
  HC05.begin(9600);
  Serial.begin(9600);
  Serial.setTimeout(2);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
  pinMode(ENB, OUTPUT);
  servo.attach(4);
  servo.write(95);
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
        break;
      case 'B':
        lui();
        break;
      case 'L':
        trai();
        break;
      case 'R':
        phai();
        break;
      case 'Q':
        trai();
        break;
      case 'E':
        phai();
        break;
      case 'C':
        lphai();
        break;
      case 'Z':
        ltrai();
        break;
      case 'S':
        Stop();
        break;
    }
  }else{
    while (!Serial.available());
    String input = Serial.readStringUntil('\n');
    int angle = input.substring(0, input.indexOf(',')).toInt();
    int Speed = input.substring(input.indexOf(',') + 1).toInt();
    servo.write(angle);
    Auto(Speed);
    Serial.println("Angle: " + String(angle) + ", Speed: " + String(Speed));
  }
}

void Auto(int Speed) {
  analogWrite(ENB, Speed);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
}

void tien() {
  servo.write(95);
  analogWrite(ENB, SpeedDK);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
}

void lui() {
  servo.write(95);
  analogWrite(ENB, SpeedDK);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
}

void ltrai() {
  servo.write(55);
  analogWrite(ENB, SpeedDK);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
}

void lphai() {
  servo.write(115);
  analogWrite(ENB, SpeedDK);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
}
void trai() {
  servo.write(55);
  analogWrite(ENB, SpeedDK);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
}

void phai() {
  servo.write(115);
  analogWrite(ENB, SpeedDK);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
}
void Stop() {
  servo.write(95);
  analogWrite(ENB, SpeedDK);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
}
