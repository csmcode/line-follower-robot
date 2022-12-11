#include <LiquidCrystal.h>
LiquidCrystal Lcd = {1,2,3,4,5,6}; // can be modified

int irLeft = 8;
int irRight = 9;
int irFront;
int irBehind;
int leftMotorPin1 = 4;
int leftMotorPin2 = 7;
int enLeft = 6;
int rightMotorPin1 = 2;
int rightMotorPin2 = 3;
int enRight = 5;
int power = 10;
int ground = 0, line = 1;

void setup()
{
  Lcd.begin(16, 2);
  Lcd.println("START");
  
  pinMode(enLeft, OUTPUT);
  pinMode(enRight, OUTPUT);
  pinMode(leftMotorPin1, OUTPUT);
  pinMode(leftMotorPin2, OUTPUT);
  pinMode(rightMotorPin1, OUTPUT);
  pinMode(rightMotorPin2, OUTPUT);
  pinMode(irLeft, INPUT);
  pinMode(irRight, INPUT);
  pinMode(irFront, INPUT);
  pinMode(irBehind, INPUT);
  pinMode(power, OUTPUT);
  digitalWrite(power, HIGH);
  ground = digitalRead(irRight);
  if (ground == 1)
  {
    line = 0;
  }
  else
  {
    line = 1;
  }

}

void loop()
{
  Lcd.clear();
  // Lcd.setCursor(__ , __); // لسه متفقناش علا مكان الاسم 
  Lcd.println("CSM");
  Lcd.setCursor(0,0);

  if (moveForward)
  {
    Lcd.println("STRAIGHT");
    Forward();
  }
  else if (moveRight)
  {
    Lcd.println("RIGHT");
    Right();
  }
  else if (moveLeft)
  {
    Lcd.println("LEFT");
    Left();
  }
  else if (stop)
  {
    Lcd.println("END");
    Stop();
  }
  
}

boolean stop()
{
  return digitalRead(irLeft) == ground && digitalRead(irRight) == ground && digitalRead(irFront) == ground && digitalRead(irBehind) == ground;
}

boolean moveLeft()
{
  return digitalRead(irRight) == ground && digitalRead(irLeft) == line;
}

boolean moveRight()
{
  return digitalRead(irRight) == line && digitalRead(irLeft) == ground;
}

boolean moveForward()
{
  return digitalRead(irRight) == ground && digitalRead(irLeft) == ground;
}

void Right(){
  digitalWrite(rightMotorPin1, LOW);
  digitalWrite(rightMotorPin2, HIGH);
  digitalWrite(leftMotorPin1, HIGH);
  digitalWrite(leftMotorPin2, LOW);
  analogWrite(enLeft, 255);
  analogWrite(enRight, 150);

}
void Left(){
  digitalWrite(rightMotorPin1, HIGH);
  digitalWrite(rightMotorPin2, LOW);
  digitalWrite(leftMotorPin1, LOW);
  digitalWrite(leftMotorPin2, HIGH);
  analogWrite(enLeft, 100);
  analogWrite(enRight, 255);

}
void Forward()
{
  digitalWrite(rightMotorPin1, HIGH);
  digitalWrite(rightMotorPin2, LOW);
  digitalWrite(leftMotorPin1, HIGH);
  digitalWrite(leftMotorPin2, LOW);
  analogWrite(enLeft, 255);
  analogWrite(enRight, 255);
}
void Stop()
{
  digitalWrite(rightMotorPin1, LOW);
  digitalWrite(rightMotorPin2, LOW);
  digitalWrite(leftMotorPin1, LOW);
  digitalWrite(leftMotorPin2, LOW);
  analogWrite(enLeft, 0);
  analogWrite(enRight, 0);

}
