#define IR_SENSOR_RIGHT 5
#define IR_SENSOR_LEFT 2
#define BUZZER_PIN 8
#define MAX_MOTOR_SPEED 250
int enableRightMotor = 6;
int rightMotorPin1 = 7;
int enableLeftMotor = 11;
int leftMotorPin1 = 9;
int aount = 0;
unsigned long startTime = 0;
const unsigned long straightDuration1 = 760;
const unsigned long turnDuration1 = 450;
boolean isTurning = false;
boolean isTTurning = false;
boolean isTTTurning = false;
boolean isTTTTurning = false;
boolean isTTTTTurning = false;
boolean isTTTTTTurning = false;
boolean isTTTTTTTurning = false;
boolean isTTTTTTTTurning = false;
boolean isTTTTTTTTTurning = false;
boolean Robot = false;
boolean RRobot = false;
boolean RRRobot = false;
boolean RRRRobot = false;
boolean RRRRRobot = false;
boolean RRRRRRobot = false;
boolean RRRRRRRobot = false;
boolean RRRRRRRRobot = false;
boolean RRRRRRRRRobot = false;
void setup() {
  pinMode(BUZZER_PIN, OUTPUT);
  pinMode(enableRightMotor, OUTPUT);
  pinMode(rightMotorPin1, OUTPUT);
  pinMode(enableLeftMotor, OUTPUT);
  pinMode(leftMotorPin1, OUTPUT);
  pinMode(IR_SENSOR_RIGHT, INPUT);
  pinMode(IR_SENSOR_LEFT, INPUT);
  rotateMotor(0, 0);
  startTime = millis();
}
void loop() {
  unsigned long currentTime = millis();
  int rightIRSensorValue = digitalRead(IR_SENSOR_RIGHT);
  int leftIRSensorValue = digitalRead(IR_SENSOR_LEFT);
  if (aount == 0) {
    if (!isTurning && aount == 0) {
      if ((unsigned long)(currentTime - startTime) < (unsigned long)(straightDuration1) && aount == 0) {
        if (rightIRSensorValue == LOW && leftIRSensorValue == LOW) {
          rotateMotor(MAX_MOTOR_SPEED, MAX_MOTOR_SPEED);
        } else if (rightIRSensorValue == HIGH && leftIRSensorValue == LOW) {
          rotateMotor(MAX_MOTOR_SPEED - 50, MAX_MOTOR_SPEED);
        } else if (rightIRSensorValue == LOW && leftIRSensorValue == HIGH) {
          rotateMotor(MAX_MOTOR_SPEED, MAX_MOTOR_SPEED - 50);
        } else {
          rotateMotor(0, 0);
        }
      } else if ((unsigned long)(currentTime - startTime) < (unsigned long)(straightDuration1 + turnDuration1) && aount == 0) {
        isTurning = true;
        startTime = (unsigned long)(currentTime); 
        rotateMotor(MAX_MOTOR_SPEED, -MAX_MOTOR_SPEED);
        delay(100);
      } else {
        rotateMotor(0, 0);
      }
    } else {
      if ((unsigned long)(currentTime - startTime) < (unsigned long)(turnDuration1) && aount == 0) {
        rotateMotor(MAX_MOTOR_SPEED, -MAX_MOTOR_SPEED);
      } else {
        isTurning = false;
        startTime = (unsigned long)(currentTime); 
        rotateMotor(0, 0);
        aount++;
      }
    }
  } else if (aount == 1) {
    if (!isTTurning && aount == 1) {
      if ((unsigned long)(currentTime - startTime) < (unsigned long)(720) && aount == 1) {
        if (rightIRSensorValue == LOW && leftIRSensorValue == LOW) {
          rotateMotor(MAX_MOTOR_SPEED, MAX_MOTOR_SPEED);
        } else if (rightIRSensorValue == HIGH && leftIRSensorValue == LOW) {
          rotateMotor(MAX_MOTOR_SPEED - 70, MAX_MOTOR_SPEED);
        } else if (rightIRSensorValue == LOW && leftIRSensorValue == HIGH) {
          rotateMotor(MAX_MOTOR_SPEED, MAX_MOTOR_SPEED - 70);
        } else {
          rotateMotor(MAX_MOTOR_SPEED, MAX_MOTOR_SPEED);
        }
      } else if ((unsigned long)(currentTime - startTime) < (unsigned long)(720 + 500) && aount == 1) {
        isTTurning = true;
        startTime = (unsigned long)(currentTime); 
        rotateMotor(MAX_MOTOR_SPEED, -MAX_MOTOR_SPEED);
        delay(100);
      } else {
        rotateMotor(0, 0);
      }
    } else {
      // If turning
      if ((unsigned long)(currentTime - startTime) < (unsigned long)(500) && aount == 1) {
        rotateMotor(MAX_MOTOR_SPEED, -MAX_MOTOR_SPEED);
      } else {
        isTTurning = false;
        startTime = (unsigned long)(currentTime); 
        rotateMotor(0, 0);
        aount++;
      }
    }
  } else if (aount == 2) {
    if (!isTTTurning && aount == 2) {
      if ((unsigned long)(currentTime - startTime) < (unsigned long)(90) && aount == 2) {
        if (rightIRSensorValue == LOW && leftIRSensorValue == LOW) {
          rotateMotor(MAX_MOTOR_SPEED, MAX_MOTOR_SPEED);
        } else if (rightIRSensorValue == HIGH && leftIRSensorValue == LOW) {
          rotateMotor(MAX_MOTOR_SPEED - 80, MAX_MOTOR_SPEED);
        } else if (rightIRSensorValue == LOW && leftIRSensorValue == HIGH) {
          rotateMotor(MAX_MOTOR_SPEED, MAX_MOTOR_SPEED - 80);
        } else {
          rotateMotor(MAX_MOTOR_SPEED, MAX_MOTOR_SPEED);
        }
      } else if ((unsigned long)(currentTime - startTime) < (unsigned long)(90 + 500) && aount == 2) {
        isTTTurning = true;
        startTime = (unsigned long)(currentTime); 
        rotateMotor(MAX_MOTOR_SPEED, -MAX_MOTOR_SPEED);
        delay(100);
      } else {
        rotateMotor(0, 0);
      }
    } else {
      if ((unsigned long)(currentTime - startTime) < (unsigned long)(500) && aount == 2) {
        rotateMotor(MAX_MOTOR_SPEED, -MAX_MOTOR_SPEED);
      } else {
        isTTTurning = false;
        startTime = (unsigned long)(currentTime); 
        rotateMotor(0, 0);
        aount++;
      }
    }
  } else if (aount == 3) {
    if (!isTTTTurning && aount == 3) {
      if ((unsigned long)(currentTime - startTime) < (unsigned long)(815) && aount == 3) {
        if (rightIRSensorValue == LOW && leftIRSensorValue == LOW) {
          rotateMotor(MAX_MOTOR_SPEED-50, MAX_MOTOR_SPEED-50);
        } else if (rightIRSensorValue == HIGH && leftIRSensorValue == LOW) {
          rotateMotor(0, MAX_MOTOR_SPEED-60);
        } else if (rightIRSensorValue == LOW && leftIRSensorValue == HIGH) {
          rotateMotor(MAX_MOTOR_SPEED-60, 0);
        } else {
          rotateMotor(MAX_MOTOR_SPEED, MAX_MOTOR_SPEED);
        }
      } else if ((unsigned long)(currentTime - startTime) < (unsigned long)(815 + 770) && aount == 3) {
        isTTTTurning = true;
        startTime = (unsigned long)(currentTime); 
        rotateMotor(-MAX_MOTOR_SPEED, MAX_MOTOR_SPEED);
        delay(100);
      } else {
        rotateMotor(0, 0);
      }
    } else {
      if ((unsigned long)(currentTime - startTime) < (unsigned long)(770) && aount == 3) {
        rotateMotor(-MAX_MOTOR_SPEED, MAX_MOTOR_SPEED);
      } else {
        isTTTTurning = false;
        startTime = (unsigned long)(currentTime); 
        rotateMotor(0, 0);
        aount++;
      }
    }
  } else if (aount == 4) {
      if (!isTTTTTurning && aount == 4) {
        if ((unsigned long)(currentTime - startTime) < (unsigned long)(1420) && aount == 4) {
          if (rightIRSensorValue == LOW && leftIRSensorValue == LOW) {
            rotateMotor(MAX_MOTOR_SPEED, MAX_MOTOR_SPEED);
          } else if (rightIRSensorValue == HIGH && leftIRSensorValue == LOW) {
            rotateMotor(MAX_MOTOR_SPEED - 70, MAX_MOTOR_SPEED);
          } else if (rightIRSensorValue == LOW && leftIRSensorValue == HIGH) {
            rotateMotor(MAX_MOTOR_SPEED, MAX_MOTOR_SPEED - 70);
          } else {
            rotateMotor(MAX_MOTOR_SPEED, MAX_MOTOR_SPEED);
          }
        } else if ((unsigned long)(currentTime - startTime) < (unsigned long)(1420 + 500) && aount == 4) {
          isTTTTTurning = true;
          startTime = (unsigned long)(currentTime); 
          rotateMotor(-MAX_MOTOR_SPEED, MAX_MOTOR_SPEED);
          delay(100);
        } else {
          rotateMotor(0, 0);
        }
      } else {
        if ((unsigned long)(currentTime - startTime) < (unsigned long)(500) && aount == 4) {
          rotateMotor(-MAX_MOTOR_SPEED, MAX_MOTOR_SPEED);
        } else {
          isTTTTTurning = false;
          startTime = (unsigned long)(currentTime); 
          rotateMotor(0, 0);
          aount++;
        }
      }
   } else if (aount == 5) {
    if (!isTTTTTTurning && aount == 5) {
      if ((unsigned long)(currentTime - startTime) < (unsigned long)(300) && aount == 5) {
        if (rightIRSensorValue == LOW && leftIRSensorValue == LOW) {
          rotateMotor(MAX_MOTOR_SPEED, MAX_MOTOR_SPEED);
        } else if (rightIRSensorValue == HIGH && leftIRSensorValue == LOW) {
          rotateMotor(MAX_MOTOR_SPEED - 80, MAX_MOTOR_SPEED);
        } else if (rightIRSensorValue == LOW && leftIRSensorValue == HIGH) {
          rotateMotor(MAX_MOTOR_SPEED, MAX_MOTOR_SPEED - 80);
        } else {
          rotateMotor(MAX_MOTOR_SPEED, MAX_MOTOR_SPEED);
        }
      } else if ((unsigned long)(currentTime - startTime) < (unsigned long)(300 + 300) && aount == 5) {
        isTTTTTTurning = true;
        startTime = (unsigned long)(currentTime); 
        rotateMotor(MAX_MOTOR_SPEED,-MAX_MOTOR_SPEED);
        delay(100);
      } else {
        rotateMotor(0, 0);
      }
    } else {
      if ((unsigned long)(currentTime - startTime) < (unsigned long)(300) && aount == 5) {
        rotateMotor(MAX_MOTOR_SPEED, -MAX_MOTOR_SPEED);
      } else {
        isTTTTTTurning = false;
        startTime = (unsigned long)(currentTime); 
        rotateMotor(0, 0);
        aount++;
      }
    }
  } else if (aount == 6) {
    if (!isTTTTTTTurning && aount == 6) {
      if ((unsigned long)(currentTime - startTime) < (unsigned long)(500) && aount == 6) {
        if (rightIRSensorValue == LOW && leftIRSensorValue == LOW) {
          rotateMotor(MAX_MOTOR_SPEED, MAX_MOTOR_SPEED);
        } else if (rightIRSensorValue == HIGH && leftIRSensorValue == LOW) {
          rotateMotor(MAX_MOTOR_SPEED - 80, MAX_MOTOR_SPEED);
        } else if (rightIRSensorValue == LOW && leftIRSensorValue == HIGH) {
          rotateMotor(MAX_MOTOR_SPEED, MAX_MOTOR_SPEED - 80);
        } else {
          rotateMotor(MAX_MOTOR_SPEED, MAX_MOTOR_SPEED);
        }
      } else if ((unsigned long)(currentTime - startTime) < (unsigned long)(500 + 500) && aount == 6) {
        isTTTTTTTurning = true;
        startTime = (unsigned long)(currentTime); 
        rotateMotor(MAX_MOTOR_SPEED, -MAX_MOTOR_SPEED);
        delay(100);
      } else {
        rotateMotor(0, 0);
      }
    } else {
      if ((unsigned long)(currentTime - startTime) < (unsigned long)(500) && aount == 6) {
        rotateMotor(MAX_MOTOR_SPEED, -MAX_MOTOR_SPEED);
      } else {
        isTTTTTTTurning = false;
        startTime = (unsigned long)(currentTime); 
        rotateMotor(0, 0);
      }
    }
  }
//  } else if (aount == 7) {
//    if (!isTTTTTTTTurning && aount == 7) {
//      if ((unsigned long)(currentTime - startTime) < (unsigned long)(70) && aount == 7) {
//        if (rightIRSensorValue == LOW && leftIRSensorValue == LOW) {
//          rotateMotor(MAX_MOTOR_SPEED, MAX_MOTOR_SPEED);
//        } else if (rightIRSensorValue == HIGH && leftIRSensorValue == LOW) {
//          rotateMotor(MAX_MOTOR_SPEED - 80, MAX_MOTOR_SPEED);
//        } else if (rightIRSensorValue == LOW && leftIRSensorValue == HIGH) {
//          rotateMotor(MAX_MOTOR_SPEED, MAX_MOTOR_SPEED - 80);
//        } else {
//          rotateMotor(MAX_MOTOR_SPEED, MAX_MOTOR_SPEED);
//        }
//      } else if ((unsigned long)(currentTime - startTime) < (unsigned long)(70 + 380) && aount == 7) {
//        isTTTTTTTTurning = true;
//        startTime = (unsigned long)(currentTime); 
//        rotateMotor(MAX_MOTOR_SPEED, -MAX_MOTOR_SPEED);
//        delay(100);
//      } else {
//        rotateMotor(0, 0);
//      }
//    } else {
//      // If turning
//      if ((unsigned long)(currentTime - startTime) < (unsigned long)(380) && aount == 7) {
//        rotateMotor(MAX_MOTOR_SPEED, -MAX_MOTOR_SPEED);
//      } else {
//        isTTTTTTTTurning = false;
//        startTime = (unsigned long)(currentTime); 
//        rotateMotor(0, 0);
//      }
//    }
//  }
//  } else if (aount == 8) {
//    if (!isTTTTTTTTTurning && aount == 8) {
//      if ((unsigned long)(currentTime - startTime) < (unsigned long)(50) && aount == 8) {
//        if (rightIRSensorValue == LOW && leftIRSensorValue == LOW) {
//          rotateMotor(MAX_MOTOR_SPEED, MAX_MOTOR_SPEED);
//        } else if (rightIRSensorValue == HIGH && leftIRSensorValue == LOW) {
//          rotateMotor(MAX_MOTOR_SPEED - 80, MAX_MOTOR_SPEED);
//        } else if (rightIRSensorValue == LOW && leftIRSensorValue == HIGH) {
//          rotateMotor(MAX_MOTOR_SPEED, MAX_MOTOR_SPEED - 80);
//        } else {
//          rotateMotor(MAX_MOTOR_SPEED, MAX_MOTOR_SPEED);
//        }
//      } else if ((unsigned long)(currentTime - startTime) < (unsigned long)(50 + 380) && aount == 8) {
//        isTTTTTTTTTurning = true;
//        startTime = (unsigned long)(currentTime); 
//        rotateMotor(-MAX_MOTOR_SPEED, MAX_MOTOR_SPEED);
//        delay(100);
//      } else {
//        rotateMotor(0, 0);
//      }
//    } else {
//      // If turning
//      if ((unsigned long)(currentTime - startTime) < (unsigned long)(380) && aount == 8) {
//        rotateMotor(-MAX_MOTOR_SPEED, MAX_MOTOR_SPEED);
//      } else {
//        isTTTTTTTTTurning = false;
//        startTime = (unsigned long)(currentTime); 
//        rotateMotor(0, 0);
//      }
//    }
//  }
}
void rotateMotor(int rightMotorSpeed, int leftMotorSpeed) {
  digitalWrite(rightMotorPin1, (rightMotorSpeed < 0) ? LOW : HIGH);
  analogWrite(enableRightMotor, constrain(abs(rightMotorSpeed), 0, MAX_MOTOR_SPEED));
  digitalWrite(leftMotorPin1, (leftMotorSpeed < 0) ? LOW : HIGH);
  analogWrite(enableLeftMotor, constrain(abs(leftMotorSpeed), 0, MAX_MOTOR_SPEED));
}
