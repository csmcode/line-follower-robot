#include <LiquidCrystal.h>
LiquidCrystal lcd = {1, 2, 3, 4, 5, 6}; // can be modified

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
int crossCounter = 0;
int gapCounter = 0;
int ground;
int line;

void setup()
{
  lcd.begin(16, 2);
  lcd.setCursor(3, 1);
  lcd.println("START");
  
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
  
  ground = digitalRead(irLeft);
  line = !ground;
}

void loop()
{
  lcd.clear();
  lcd.setCursor(6, 0);
  lcd.println("CSM");

  if (cross)
  {
    crossCounter++;
  }

  if (gap)
  {
    gapCounter++;
  }

  lcd.setCursor(13, 1);
  if (crossCounter == 5)
  {
    lcd.println("B"); 
  }
        
  if (gapCounter == 2)
  {
    lcd.println("C");    
  }

  lcd.setCursor(3, 1);
  if (sensingRight)
  {
    lcd.println("RIGHT");
    goRight();

  }

  else if (sensingLeft)
  {
    lcd.println("LEFT");
    goLeft();  
  }

  else if (sensingStraight)
  {
    lcd.println("STRAIGHT");
    goForward();
  }

  else if (sensingNothing)
  {
    lcd.println("END");
    stop();
  }  
}

boolean sensingNothing()
{
  return digitalRead(irFront) == ground && digitalRead(irBehind) == ground;
}

boolean sensingLeft()
{
  return digitalRead(irRight) == ground && digitalRead(irLeft) == line;
}

boolean sensingRight()
{
  return digitalRead(irRight) == line && digitalRead(irLeft) == ground;
}

boolean sensingStraight()
{
  return digitalRead(irFront) == line || digitalRead(irBehind) == line ;
}

boolean cross()
{
  return digitalRead(irRight) == line && digitalRead(irLeft) == line && digitalRead(irFront) == line;
}

boolean gap()
{
  return digitalRead(irRight) == ground && digitalRead(irLeft) == ground && digitalRead(irFront) == ground;
}

void goRight()
{
  digitalWrite(rightMotorPin1, LOW);
  digitalWrite(rightMotorPin2, HIGH);
  digitalWrite(leftMotorPin1, HIGH);
  digitalWrite(leftMotorPin2, LOW);
  analogWrite(enLeft, 255);
  analogWrite(enRight, 150);

}
void goLeft()
{
  digitalWrite(rightMotorPin1, HIGH);
  digitalWrite(rightMotorPin2, LOW);
  digitalWrite(leftMotorPin1, LOW);
  digitalWrite(leftMotorPin2, HIGH);
  analogWrite(enLeft, 100);
  analogWrite(enRight, 255);

}
void goForward()
{
  digitalWrite(rightMotorPin1, HIGH);
  digitalWrite(rightMotorPin2, LOW);
  digitalWrite(leftMotorPin1, HIGH);
  digitalWrite(leftMotorPin2, LOW);
  analogWrite(enLeft, 255);
  analogWrite(enRight, 255);
}
void stop()
{
  digitalWrite(rightMotorPin1, LOW);
  digitalWrite(rightMotorPin2, LOW);
  digitalWrite(leftMotorPin1, LOW);
  digitalWrite(leftMotorPin2, LOW);
  analogWrite(enLeft, 0);
  analogWrite(enRight, 0);

}
