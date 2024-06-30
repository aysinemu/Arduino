//Cre: Tấn Cường UTE
#include "SoftwareSerial.h"
#include <Servo.h>
Servo servo1;
Servo servo2;
SoftwareSerial HC05 (1, 0); //TX, RX
int ENA = 2;
int IN1 = 3;
int IN2 = 4;
int IN3 = 5;
int IN4 = 6;
int ENB = 7;
char dieu_khien;
int Speed = 225;
int vitri = 0;
int vitri1 = 0;
int quay = 0;
int quay1 = 0;
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
  servo1.attach(10);
  servo2.attach(11);
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
      case 'X':
//        if (vitri % 2 == 0){
//          quay += 10;
//          if (quay > 110){
//            quay = 110;
//            vitri += 1;
//          }
//        }else if (vitri % 2 !=0){
//          quay -= 10;
//          if (quay < 0){
//            quay = 0;
//            vitri += 1;
//          }
//        }
        if (vitri % 2 == 0){
          quay += 100;
          if (quay >100){
            quay = 100;
            vitri += 1;
          }
        }else if (vitri % 2 !=0){
          quay -= 100;
          if (quay < 0){
            quay = 0;
            vitri += 1;
          }
        }
        len();
        break;
      case 'Y':
//      if (vitri1 % 2 == 0){
//          quay1 += 10;
//          if (quay1 > 85){
//            quay1 = 85;
//            vitri1 += 1;
//          }
//        }else if (vitri1 % 2 !=0){
//          quay1 -= 10;
//          if (quay1 < 5){
//            quay1 = 5;
//            vitri1 += 1;
//          }
//        }
        if (vitri1 % 2 == 0){
          quay1 += 80;
          if (quay1 >80){
            quay1 = 80;
            vitri1 += 1;
          }
        }else if (vitri1 % 2 !=0){
          quay1 -= 55;
          if (quay1 < 25){
            quay1 = 25;
            vitri1 += 1;
          }
        }
        gap();
        break;
    }
  }
}
void tien() {
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
}
void lui() {
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
}
void phai() {
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
}
void trai() {
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
}
void ltrai() {
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
}
void lphai() {
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
}
void Stop() {
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
}
void len(){
  servo1.write(quay);
}
void gap(){
  servo2.write(quay1);
}
