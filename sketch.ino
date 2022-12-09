<<<<<<< HEAD
#include <LiquidCrystal.h>
LiquidCrystal Lcd = {1,2,3,4,5,6}; // can be modified

int IRL;
int IRR;
int IRM;
int inML1;
int inMR1;
int inML2;
int inMR2;
int enL;
int enR;
int ground=0;
int line=0;
long Timer ;
int m=0;
=======
int irLeft = 8;
int irRight = 9;
int irMiddle;
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
<<<<<<< HEAD
  Lcd.begin(16,2);
  //print start one time only 
  Lcd.println("START");

  pinMode(enL,OUTPUT);
  pinMode(enR,OUTPUT);
  pinMode(inML1,OUTPUT);
  pinMode(inML2,OUTPUT);
  pinMode(inMR1,OUTPUT);
  pinMode(inMR2,OUTPUT);
  pinMode (IRL,INPUT);
  pinMode (IRR,INPUT);
  pinMode(IRM,INPUT);
  ground = digitalRead (IRR);
  if (ground == 1)
    line=0;
  else 
    line = 1;
}

void loop(){
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
  delay(100);
}
else if (moveLeft)
{
  Lcd.println("LEFT");
  Left();
  delay(100);
=======
  pinMode(enLeft, OUTPUT);
  pinMode(enRight, OUTPUT);
  pinMode(leftMotorPin1, OUTPUT);
  pinMode(leftMotorPin2, OUTPUT);
  pinMode(rightMotorPin1, OUTPUT);
  pinMode(rightMotorPin2, OUTPUT);
  pinMode(irLeft, INPUT);
  pinMode(irRight, INPUT);
  pinMode(irMiddle, INPUT);
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
>>>>>>> 32eca954dbced9aefd575357464400f6f4ad0cf5

void loop()
{

<<<<<<< HEAD
}
if (stop)
{
  Lcd.println("END");
  Stop();
}
if(digitalRead (IRM)==line)m=0;
=======
  if (moveForward)
  {
    Forward();
  }
  else if (moveRight)
  {
    Right();
  }
  else if (moveLeft)
  {
    Left();
  }
  else if (stop)
  {
    Stop();
  }
  
>>>>>>> 32eca954dbced9aefd575357464400f6f4ad0cf5
}

boolean stop()
{
  return digitalRead(irMiddle) == ground;
}

boolean moveLeft()
{
  return digitalRead(irRight) == ground && digitalRead(irLeft) == line;
}

boolean moveRight()
{
  return digitalRead(irRight) == line && digitalRead(irLeft) == ground;
}

<<<<<<< HEAD
boolean moveForward(){
  return digitalRead(IRR) == ground && digitalRead(IRL == ground);
=======
boolean moveForward()
{
  return digitalRead(irRight) == ground && digitalRead(irLeft) == ground;
>>>>>>> 32eca954dbced9aefd575357464400f6f4ad0cf5
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
  analogWrite(enLeft,0);
  analogWrite(enRight,0);

}
