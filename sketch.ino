#include <LiquidCrystal.h>
#include <headers.h>
#include <movment.h>
#include <counters.h>
#include <print.h>

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

