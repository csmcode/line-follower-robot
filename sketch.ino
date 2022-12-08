int IRL;
int IRR;
int IRM;
int inML1;
int inMR1;
int inML2;
int inMR2;
int enL;
int enR;
int ground=0;
int line=0;
long Timer ;
int m=0;

 void setup()
{

pinMode(enL,OUTPUT);
pinMode(enR,OUTPUT);
pinMode(inML1,OUTPUT);
pinMode(inML2,OUTPUT);
pinMode(inMR1,OUTPUT);
pinMode(inMR2,OUTPUT);
pinMode (IRL,INPUT);
pinMode (IRR,INPUT);
pinMode(IRM,INPUT);
ground = digitalRead (IRR);
if (ground ==1)line=0;
else line =1;

}
void loop(){

if (moveForward){
Forward();
}
else if (moveRight){
Right();
delay(100);
}
else if (moveLeft){
Left();
delay(100);

}
 if (digitalRead(IRM)==ground&&m==0){
    m=1;

}
if (stop){
Stop();
}
if(digitalRead (IRM)==line)m=0;
}

boolean stop(){
  return digitalRead(IRM)==ground;
}

boolean moveLeft(){
  return digitalRead (IRR)==ground &&digitalRead (IRL)==line;
}

boolean moveRight(){
  return digitalRead (IRR)==line &&digitalRead (IRL)==ground;
}

boolean moveForward(){
  return digitalRead (IRR)==ground &&digitalRead (IRL==ground);
}

void Right(){
digitalWrite (inMR1,HIGH);
digitalWrite (inMR2,LOW);
digitalWrite (inML1,HIGH);
digitalWrite (inML2,LOW);
analogWrite (enL,255);
analogWrite(enR,100);

}
void Left(){
digitalWrite (inMR1,HIGH);
digitalWrite (inMR2,LOW);
digitalWrite (inML1,HIGH);
digitalWrite (inML2,LOW);
analogWrite (enL,100);
analogWrite(enR,255);

}
void Forward(){
digitalWrite (inMR1,HIGH);
digitalWrite (inMR2,LOW);
digitalWrite (inML1,HIGH);
digitalWrite (inML2,LOW);
analogWrite (enL,255);
analogWrite(enR,255);

}
void Stop(){
digitalWrite (inMR1,HIGH);
digitalWrite (inMR2,LOW);
digitalWrite (inML1,HIGH);
digitalWrite (inML2,LOW);
analogWrite (enL,0);
analogWrite(enR,0);

}
