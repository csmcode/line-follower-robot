#include <LiquidCrystal.h>
LiquidCrystal lcd = {8, 13, 12, 11, 10, 9}; 

// sensors
int irLeft = A3;
int irRight = A5;
int irFront = A4;
int irBehind = A2;
// left motor
int leftMotorPin1 = 2; 
int leftMotorPin2 = 3;
int enLeft = 6;
// right motor
int rightMotorPin1 = 7;
int rightMotorPin2 = 4;
int enRight = 5;
// counters
int max = 0 ;
int straightCounter = 0 ;
int crossCounter = 0;
int gapCounter = 0;
// instead of HIGH and LOW
int ground = LOW;
int line = HIGH;
// for badge A
bool isMaximum = false;
// for badge D
bool ended = false;

void countCross()
{
  if (digitalRead(irRight) == line && digitalRead(irLeft) == line && digitalRead(irFront) == line && digitalRead(irBehind) == line)
  {
    crossCounter++;
    // delay(62);
  }
}

void countStraight()
{
  straightCounter++;
  // delay(62);
  if (straightCounter >= max)
  {
    max = straightCounter;
  }
}

void countGap()
{
  if (digitalRead(irRight) == ground && digitalRead(irLeft) == ground && digitalRead(irFront) == ground && digitalRead(irBehind) == line)
  {
    gapCounter++;
    // delay(62);
  }
}

void printBadges()
{
  if (isMaximum)
  {
    lcd.print("A");
  }
  
  if (crossCounter == 5)
  {
    isMaximum = false;
    lcd.print("B"); 
  }
        
  if (gapCounter == 2)
  {
    lcd.print("C");    
  }

  if (ended)
  {
    lcd.print("D");
  }
}

int sensingRight()
{
  // move right when right sensor read line
  return digitalRead(irLeft) == ground && digitalRead(irRight) == line;
}

int sensingLeft()
{
  // move left when left sensor read line 
  return digitalRead(irLeft) == line && digitalRead(irRight) == ground;
}

int sensingStraight()
{
  // move forward when either of sensors read line
  // return (digitalRead(irFront) == line && digitalRead(irLeft) == ground && digitalRead(irRight) == ground) || (digitalRead(irFront) == line && digitalRead(irLeft) == line && digitalRead(irRight) == line && digitalRead(irBehind) == line) || (digitalRead(irFront) == ground && digitalRead(irLeft) == ground && digitalRead(irRight) == ground && digitalRead(irBehind) == line);
  return digitalRead(irFront) == line || digitalRead(irBehind) == line;
}

int sensingNothing()
{
  // stop when both sensors read ground
  return digitalRead(irFront) == ground && digitalRead(irLeft) == ground && digitalRead(irRight) == ground && digitalRead(irBehind) == ground;
}

void goRight()
{
  straightCounter = 0;
  // Tilt robot towards right by stopping the right wheel and moving the left one
  digitalWrite(rightMotorPin1, LOW);
  digitalWrite(rightMotorPin2, HIGH);
  digitalWrite(leftMotorPin1, HIGH);
  digitalWrite(leftMotorPin2, LOW);
  analogWrite(enLeft, 80);
  analogWrite(enRight, 0);
  delay(50);
}

void goLeft()
{
  if (straightCounter == max && crossCounter == 0)    
  {
    isMaximum = true;
    straightCounter = 0;
  }
  // Tilt robot towards left by stopping the left wheel and moving the right one
  digitalWrite(rightMotorPin1, HIGH);
  digitalWrite(rightMotorPin2, LOW);
  digitalWrite(leftMotorPin1, LOW);
  digitalWrite(leftMotorPin2, HIGH);
  analogWrite(enLeft, 0);
  analogWrite(enRight, 80);
  delay(50);
}

void goForward()
{
  countStraight();
  // Move both the Motors
  digitalWrite(rightMotorPin1, HIGH);
  digitalWrite(rightMotorPin2, LOW);
  digitalWrite(leftMotorPin1, HIGH);
  digitalWrite(leftMotorPin2, LOW);
  analogWrite(enLeft, 80);
  analogWrite(enRight,80);
}

void stop()
{
  // Stop both the motors
  ended = true;
  digitalWrite(rightMotorPin1, LOW);
  digitalWrite(rightMotorPin2, LOW);
  digitalWrite(leftMotorPin1, LOW);
  digitalWrite(leftMotorPin2, LOW);
  analogWrite(enLeft, 0);
  analogWrite(enRight, 0);
}

void moveTheRobot()
{
  if (digitalRead(irLeft) == ground && digitalRead(irRight) == line)
  {
    lcd.print("RIGHT   ");
    goRight();
  }

  else if (digitalRead(irLeft) == line && digitalRead(irRight) == ground && digitalRead(irFront) == ground)
  {
    lcd.print("LEFT    ");
    goLeft();  
  }

  else if ((digitalRead(irFront) == line && digitalRead(irLeft) == ground && digitalRead(irRight) == ground) || (digitalRead(irFront) == line && digitalRead(irLeft) == line && digitalRead(irRight) == line && digitalRead(irBehind) == line) || (digitalRead(irFront) == ground && digitalRead(irLeft) == ground && digitalRead(irRight) == ground && digitalRead(irBehind) == line) /* same as sensingStraight*/)
  {
    lcd.print("STRAIGHT");
    goForward();
  }

  else if (sensingNothing()) 
  {
    lcd.print("END     ");
    stop();
  }

  else
  {
    goForward();
  }
}
