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

void loop()
{

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
  analogWrite(enLeft,0);
  analogWrite(enRight,0);

}
