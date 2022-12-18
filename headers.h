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
// for badge d 
bool ended = false ;

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
    stop();
  }
}
