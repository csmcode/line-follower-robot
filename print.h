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
  if (ended)
  {
    lcd.setCursor(13, 1);
    lcd.print("D");
  }
