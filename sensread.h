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
