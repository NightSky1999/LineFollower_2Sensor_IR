#include <Servo.h>

#define IN1 10
#define IN2 9
#define IN3 6
#define IN4 5

#define Lsensor 8
#define Rsensor 7

int Speed = 90;
bool R,L;
void setup() {
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);

  pinMode(Lsensor, INPUT);
  pinMode(Rsensor, INPUT);  
}

void loop() {
  L = digitalRead(Lsensor);
  R = digitalRead(Rsensor);
  if(L == HIGH && R == HIGH){
    MotorDC(0);
  }
  else if(L == HIGH && R == LOW){
    turnL(Speed);
  }
  else if(L == LOW && R == HIGH){
    turnR(Speed);
  }
  else {
    MotorDC(Speed);
  }

}

void MotorDC(int motor){
  analogWrite(IN1,0);
  analogWrite(IN2,motor);

  analogWrite(IN3,0);
  analogWrite(IN4, motor);
}

void turnL(int motor){
  analogWrite(IN1,motor);
  analogWrite(IN2,0);

  analogWrite(IN3,0);
  analogWrite(IN4, motor);
}

void turnR(int motor){
  analogWrite(IN1,0);
  analogWrite(IN2,motor);

  analogWrite(IN3,motor);
  analogWrite(IN4, 0);
}
