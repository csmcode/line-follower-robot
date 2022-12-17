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
int enLeft = 4;
// right motor
int rightMotorPin1 = 5;
int rightMotorPin2 = 6;
int enRight = 7;
// counters
int max = 0 ;
int straightCounter = 0 ;
int crossCounter = 0;
int gapCounter = 0;
// instead of HIGH and LOW
int ground;
int line;
// for badge A
bool isMaximum = false;

void setup()
{
  lcd.begin(16, 2);
  lcd.setCursor(3, 1);
  lcd.print("START");
  // initialize the inputs and outputs
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
  // auto detect ground
  ground = digitalRead(irLeft);
  line = !ground;
}

void loop()
{
  // Team name
  lcd.setCursor(6, 0);
  lcd.print("CSM");
  // helpful for printing B and C
  countCross();
  countGap();
  // badges
  lcd.setCursor(13, 1);
  printBadges();
  // movement
  lcd.setCursor(3, 1);
  moveTheRobot();
}

boolean sensingNothing()
{
  // stop when both sensors read ground
  return digitalRead(irFront) == ground && digitalRead(irBehind) == ground;
}

boolean sensingLeft()
{
  // move left when left sensor read line 
  return digitalRead(irRight) == ground && digitalRead(irLeft) == line;
}

boolean sensingRight()
{
  // move right when right sensor read line
  return digitalRead(irRight) == line && digitalRead(irLeft) == ground;
}

boolean sensingStraight()
{
  // move forward when either of sensors read line
  return digitalRead(irFront) == line || digitalRead(irBehind) == line ;
}

boolean cross()
{
  // return true when all sesnors read line (a cross found)
  return digitalRead(irRight) == line && digitalRead(irLeft) == line && digitalRead(irFront) == line;
}

boolean gap()
{
  // return ture when all sensors read ground (a gap found)
  return digitalRead(irRight) == ground && digitalRead(irLeft) == ground && digitalRead(irFront) == ground;
}

void countCross()
{
  if (cross)
  {
    crossCounter++;
    delay(100); //changeable
  }
}

void countGap()
{
  if (gap)
  {
    gapCounter++;
    delay(100); //changeable
  }
}

void countStraight()
{
  straightCounter++;
  delay(10);
  if (straightCounter >= max)
  {
    max = straightCounter ;
  }
}

void printBadges()
{
  if (crossCounter == 5)
  {
    lcd.print("B"); 
  }
        
  if (gapCounter == 2)
  {
    lcd.print("C");    
  }

  if (isMaximum)
  {
    lcd.print("A");
    delay(10);
    isMaximum = false;
  }
}

void goRight()
{
  straightCounter = 0;
  // Tilt robot towards right by stopping the right wheel and moving the left one
  digitalWrite(rightMotorPin1, LOW);
  digitalWrite(rightMotorPin2, HIGH);
  digitalWrite(leftMotorPin1, HIGH);
  digitalWrite(leftMotorPin2, LOW);
  analogWrite(enLeft, 255);
  analogWrite(enRight, 150);

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
  analogWrite(enLeft, 100);
  analogWrite(enRight, 255);
}

void goForward()
{
  countStraight();
  // Move both the Motors
  digitalWrite(rightMotorPin1, HIGH);
  digitalWrite(rightMotorPin2, LOW);
  digitalWrite(leftMotorPin1, HIGH);
  digitalWrite(leftMotorPin2, LOW);
  analogWrite(enLeft, 255);
  analogWrite(enRight, 255);
}
void stop()
{
  // Stop both the motors
  digitalWrite(rightMotorPin1, LOW);
  digitalWrite(rightMotorPin2, LOW);
  digitalWrite(leftMotorPin1, LOW);
  digitalWrite(leftMotorPin2, LOW);
  analogWrite(enLeft, 0);
  analogWrite(enRight, 0);
}

void moveTheRobot()
{
  if (sensingRight)
  {
    lcd.print("RIGHT");
    goRight();
  }

  else if (sensingLeft)
  {
    lcd.print("LEFT");
    goLeft();  
  }

  else if (sensingStraight)
  {
    lcd.print("STRAIGHT");
    goForward();
  }

  else if (sensingNothing)
  {
    lcd.print("END");
    lcd.setCursor(13, 1);
    lcd.print("D");
    stop();
  }
}