#include <LiquidCrystal.h>

LiquidCrystal lcd = {8, 13, 12, 11, 10, 9};
// Black Line Follower
int irRight = A5; // Right sensor
int irLeft = A3;  // left Sensor
int irMiddle = A4;

// motors
int enRight = 5;
int rightMotorPin1 = 2;
int rightMotorPin2 = 3;

int enLeft = 6;
int leftMotorPin1 = 7;
int leftMotorPin2 = 4;
const uint8_t maxSpeedRight = 150;
const uint8_t maxSpeedLeft = 150;
unsigned long initialMillies;
unsigned long currentMillies;
unsigned long period;
int motorspetr;
int proportionalError = 0;
int integeralError = 0;
int diffError = 0;
int lastError = 0;
int error = 0;
const uint8_t baseSpeedLeft = 100;
const uint8_t baseSpeedRight = 100;
int position = 0;
float Ki = 0.0008;
float Kp = 0.2;
float Kd = 0.97;

void setup()
{
  initialMillies = millis();
  lcd.begin(16, 2);
  lcd.println("START!!!!!!");
  delay(1000);
  lcd.clear();
  // put your setup code here, to run once:
  pinMode(enRight, OUTPUT);
  pinMode(enLeft, OUTPUT);
  pinMode(irRight, INPUT);
  pinMode(irLeft, INPUT);
  pinMode(rightMotorPin1, OUTPUT);
  pinMode(rightMotorPin2, OUTPUT);
  pinMode(leftMotorPin1, OUTPUT);
  pinMode(leftMotorPin2, OUTPUT);
  digitalWrite(rightMotorPin1, HIGH);
  digitalWrite(rightMotorPin2, LOW);
  digitalWrite(leftMotorPin1, HIGH);
  digitalWrite(leftMotorPin2, LOW);
  lcd.setCursor(6, 0);
  lcd.print("CSM");
}

void motorControl(int leftSpeed, int rightSpeed)
{
  if (leftSpeed == 0)
  {
    rightSpeed = 150;
  }

  if (rightSpeed == 0)
  {
    leftSpeed = 150;
  }

  analogWrite(enRight, (leftSpeed * 0.8));
  analogWrite(enLeft, (rightSpeed * 0.8));
}

void loop()
{
  currentMillies = millis();
  period = currentMillies - initialMillies;
  
  lcd.setCursor(3, 1);
  if (digitalRead(irRight) == HIGH && digitalRead(irLeft) == HIGH && digitalRead(irMiddle) == HIGH) // IR will not glow on black line
  {
    lcd.print("STRAIGHT");
    position = 3500;
  }

  else if (digitalRead(irRight) == LOW && digitalRead(irLeft) == LOW && digitalRead(irMiddle) == HIGH) // bot on black line
  {
    lcd.print("STRAIGHT");
    // Move both the Motors
    position = 3500;
  }

  else if (digitalRead(irRight) == LOW && digitalRead(irLeft) == HIGH)
  {
    lcd.print("LEFT    ");
    // Tilt robot towards left by stopping the left wheel and moving the right one
    position = 0;
  }
  else if (digitalRead(irRight) == HIGH && digitalRead(irLeft) == LOW)
  {
    lcd.print("RIGHT   ");
    position = 7000;
  }

  else
  {
    position = position;
  }

  PID_control(position);
  lcd.setCursor(15, 1);
  printBadges();
}

void PID_control(int pos)
{
  int error = 3500 - pos;
  proportionalError = error;
  integeralError = constrain(integeralError + error, -50 / 100, 50 / 100);
  diffError = error - lastError;
  lastError = error;

  float pidValue = proportionalError * Kp + integeralError * Ki + diffError * Kd;

  int leftSpeed = baseSpeedLeft + pidValue;
  int rightSpeed = baseSpeedRight - pidValue;

  if (leftSpeed > maxSpeedLeft)
  {
    leftSpeed = maxSpeedLeft;
  }
  if (rightSpeed > maxSpeedRight)
  {
    rightSpeed = maxSpeedRight;
  }
  if (leftSpeed < 0)
  {
    leftSpeed = 0;
  }
  if (rightSpeed < 0)
  {
    rightSpeed = 0;
  }

  motorControl(leftSpeed, rightSpeed);
}

void printBadges()
{
  if (period >= 8000 && period <= 12000)
  {
    lcd.print("A");
  }
  else if (period >= 20000 && period <= 24000)
  {
    lcd.print("B");
  }
  else if (period >= 33000 && period <= 37000)
  {
    lcd.print("C");
  }
  else if (period >= 42000 && period <= 45000)
  {
    lcd.print("D");
  }
  else
  {
    lcd.print(" ");
  }
}
