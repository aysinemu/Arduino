//Code Cre:Tấn Cường UTE - code có tích hợp LCD và RGB

//#include <Wire.h> //Gọi thư viện I2C để sử dụng 

//#include <LiquidCrystal_I2C.h> // Vào Library Manager tải thư viện Thư viện Màn hình I2C
//LiquidCrystal_I2C lcd(0x27, 16, 2); //Khai báo địa chỉ I2C (0x27 or 0x3F) và Màn hình 16x02

#include "SoftwareSerial.h"
SoftwareSerial HC06 (1, 0); //TX, RX
int ENA = 2;
int IN1 = 3;
int IN2 = 4;
int IN3 = 5;
int IN4 = 6;
int ENB = 7;

char dieu_khien;
int Speed = 250;

//const byte PIN_RED = 2;
//const byte PIN_GREEN = 3;
//const byte PIN_BLUE = 4;
//
//const byte COLOR_RED[] = {255,0,0};
//const byte COLOR_LIME[] = {0,255,0};
//const byte COLOR_BLUE[] = {0,0,255};
//const byte COLOR_WHITE[] = {255,255,255};
//const byte COLOR_YELLOW[] = {255,255,0};
//const byte COLOR_CYAN[] = {0,255,255};
//const byte COLOR_MAGENTA[] = {255,0,255};
//const byte COLOR_SILVER[] = {192,192,192};
//const byte COLOR_GRAY[] = {128,128,128};
//const byte COLOR_MAROON[] = {128,0,0};
//const byte COLOR_OLIVE[] = {128,128,0};
//const byte COLOR_GREEN[] = {0,128,0};
//const byte COLOR_PURPLE[] = {128,0,128};
//const byte COLOR_TEAL[] = {0,128,128};
//const byte COLOR_NAVY[] = {0,0,128};
//
//const unsigned short DURATION_COLOR = 0;

void setup() {
  HC06.begin(9600);
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
  pinMode(ENA, OUTPUT);
  pinMode(ENB, OUTPUT);

  analogWrite(ENA, Speed);
  analogWrite(ENB, Speed);

//  pinMode(PIN_RED, OUTPUT);
//  pinMode(PIN_GREEN, OUTPUT);
//  pinMode(PIN_BLUE, OUTPUT);
//
//  // Khai báo Các câu lệnh bắt buột để sử dụng lcd.
//  lcd.init(); // Khởi tạo màn hình Màn hình
//  lcd.backlight(); // Bật đèn màn hình Màn 
}

void loop() 
{ 
  if (HC06.available() > 0) 
  {
    dieu_khien = HC06.read();
    Serial.println(dieu_khien);
    switch (dieu_khien) 
    {
      case 'F':
        tien();
//        lcd.setCursor(0, 0); //Chọn vị trí đặt con trỏ (cột, hàng)  
//        lcd.print("Forward              "); //in lên Màn hình chữ 
//        setColor(COLOR_GREEN);
        Serial.print("Chay tien");
        break;
      case 'B':
        lui();
//        setColor(COLOR_PURPLE);
//        lcd.setCursor(0, 0); //Chọn vị trí đặt con trỏ (cột, hàng)  
//        lcd.print("Backward             "); //in lên Màn hình chữ 
        Serial.print("Chay lui");
        break;
      case 'L':
        trai();
//        setColor(COLOR_YELLOW);
//        lcd.setCursor(0, 0); //Chọn vị trí đặt con trỏ (cột, hàng)  
//        lcd.print("Turn Left            "); //in lên Màn hình chữ 
        Serial.print("Re trai");
        break;
      case 'R':
        phai();
//        setColor(COLOR_BLUE);
//        lcd.setCursor(0, 0); //Chọn vị trí đặt con trỏ (cột, hàng)  
//        lcd.print("Turn Right           "); //in lên Màn hình chữ 
        Serial.print("Re phai");
        break;
      case 'Q':
        trai();
//        setColor(COLOR_TEAL);
//        lcd.setCursor(0, 0); //Chọn vị trí đặt con trỏ (cột, hàng)  
//        lcd.print("45 Degree L          "); //in lên Màn hình chữ 
        Serial.print("Re phai");
        break;
      case 'E':
        phai();
//        setColor(COLOR_LIME);
//        lcd.setCursor(0, 0); //Chọn vị trí đặt con trỏ (cột, hàng)  
//        lcd.print("45 Degree R          "); //in lên Màn hình chữ 
        Serial.print("Re phai");
        break;
      case 'C':
        lphai();
//        setColor(COLOR_OLIVE);
//        lcd.setCursor(0, 0); //Chọn vị trí đặt con trỏ (cột, hàng)  
//        lcd.print("45 Degree RB         "); //in lên Màn hình chữ 
        Serial.print("Re phai");
        break;
      case 'Z':
        ltrai();
//        setColor(COLOR_MAROON);
//        lcd.setCursor(0, 0); //Chọn vị trí đặt con trỏ (cột, hàng)  
//        lcd.print("45 Degree LB         "); //in lên Màn hình chữ 
        Serial.print("Re phai");
        break;
      case 'S':
        Stop();
//        setColor(COLOR_RED);
//        lcd.setCursor(0, 0);
//        lcd.print("Cre:Tan Cuong");
//        lcd.setCursor(0, 1); // Chọn cột 1 và hàng 1
//        lcd.print("Racing");
//        lcd.setCursor(7, 1); 
//        lcd.print("Car"); 
//        lcd.setCursor(11, 1);
//        lcd.print("Beta");
        Serial.print("Dung");
        break;
    }
  }
}

//void setColorr() {
//  setColor(COLOR_RED); delay(DURATION_COLOR);
//  setColor(COLOR_LIME); delay(DURATION_COLOR);
//  setColor(COLOR_BLUE); delay(DURATION_COLOR);
//  setColor(COLOR_WHITE); delay(DURATION_COLOR);
//  setColor(COLOR_YELLOW); delay(DURATION_COLOR);
//  setColor(COLOR_MAGENTA); delay(DURATION_COLOR);
//  setColor(COLOR_SILVER); delay(DURATION_COLOR);
//  setColor(COLOR_GRAY); delay(DURATION_COLOR);
//  setColor(COLOR_MAROON); delay(DURATION_COLOR);
//  setColor(COLOR_OLIVE); delay(DURATION_COLOR);
//  setColor(COLOR_GREEN); delay(DURATION_COLOR);
//  setColor(COLOR_PURPLE); delay(DURATION_COLOR);
//  setColor(COLOR_TEAL); delay(DURATION_COLOR);
//  setColor(COLOR_NAVY); delay(DURATION_COLOR);
//}

void tien() {
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
}

void lui() {
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
}

void trai() {
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
}

void phai() {
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
}
void ltrai() {
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
}

void lphai() {
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
}
void Stop() {
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
}

//void setColor(byte colors[]) {
//  analogWrite(PIN_RED, colors[0]);
//  analogWrite(PIN_GREEN, colors[1]);
//  analogWrite(PIN_BLUE, colors[2]);
//}

//void LCD(){
//  lcd.setCursor(0, 0); //Chọn vị trí đặt con trỏ (cột, hàng)  
//  lcd.print("Cre:Tan Cuong"); //in lên Màn hình 
//  lcd.clear(); //Xóa Màn hình
//  lcd.setCursor(0, 1); // Chọn cột 1 và hàng 1
//  lcd.print("Racing");
//  lcd.setCursor(7, 1); 
//  lcd.print("Car"); 
//  lcd.setCursor(11, 1);
//  lcd.print("Beta");
//  lcd.clear();
//  lcd.setCursor(0, 0);
//  lcd.print("Cre:Tan Cuong");
//  lcd.setCursor(0, 1); // Chọn cột 1 và hàng 1
//  lcd.print("Racing");
//  lcd.setCursor(7, 1); 
//  lcd.print("Car"); 
//  lcd.setCursor(11, 1);
//  lcd.print("Beta");
//  lcd.clear();
//}
