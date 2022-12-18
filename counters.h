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
