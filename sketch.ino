#include <LiquidCrystal.h>
LiquidCrystal Lcd = {1,2,3,4,5,6}; // can be modified

int irLeft = A0;
int irRight = A1;
int irFront = A2;
int irBehind = A3;
int leftMotorPin1 = 4;
int leftMotorPin2 = 7;
int enLeft = 6;
int rightMotorPin1 = 2;
int rightMotorPin2 = 3;
int enRight = 5;
int power = 10;
int counter_B = 0;
int counter_C = 0;

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
  

}

void loop()
{
  Lcd.clear();
  // Lcd.setCursor(__ , __); // لسه متفقناش علا مكان الاسم 
  Lcd.println("CSM");
  Lcd.setCursor(0,0);
  if ((digitalRead(irRight) == 1 && digitalRead(irLeft) == 1 && digitalRead(irFront) == 1 && digitalRead(irBehind) == 1))
  {
    Counter_B ++;
  }
  if ((digitalRead(irRight) == 0 && digitalRead(irLeft) == 0 && digitalRead(irFront) == 0 && digitalRead(irBehind) == 1))
  {
    counter_C ++;
  }  

  if (moveForward)
  {
    Lcd.println("STRAIGHT");
    Forward();
    
    if (counter_B == 5)
    {
      Lcd.println("B");            
    }
         
    if (counter_C == 2)
    {
      Lcd.println("C");            
    }
  }
  else if (moveRight)
  {
    Lcd.println("RIGHT");
    Right();

    if (counter_B == 5)
    {
      Lcd.println("B");            
    }
         
    if (counter_C == 2)
    {
      Lcd.println("C");            
    }
  }
  else if (moveLeft)
  {
    Lcd.println("LEFT");
    Left();
    
    if (counter_B == 5)
    {
      Lcd.println("B");            
    }
         
    if (counter_C == 2)
    {
      Lcd.println("C");            
    }
  }
  else if (stop)
  {
    Lcd.println("END");
    Stop();
    
    if (counter_B == 5)
    {
      Lcd.println("B");            
    }
         
    if (counter_C == 2)
    {
      Lcd.println("C");            
    }
  }
  
}

boolean stop()
{
  return digitalRead(irLeft) == 0 && digitalRead(irRight) == 0 && digitalRead(irFront) == 0 && digitalRead(irBehind) == 0;
}

boolean moveLeft()
{
  return digitalRead(irRight) == 0 && digitalRead(irLeft) == 1;
}

boolean moveRight()
{
  return digitalRead(irRight) == 1 && digitalRead(irLeft) == 0;
}

boolean moveForward()
{
  return (digitalRead(irRight) == 0 && digitalRead(irLeft) == 0) ||  (digitalRead(irRight) == 1 && digitalRead(irLeft) == 1 && digitalRead(irFront) == 1 && digitalRead(irBehind) == 1) ;
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
