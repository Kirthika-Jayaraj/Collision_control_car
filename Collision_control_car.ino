const int sl=2,sr=3,sf=4,sb=7; //Sensor pins
const int sto=512,so=5;//steering output and pin no
int wo=6;
void setup()
{
  pinMode(sl,INPUT);
  pinMode(sr,INPUT);
  pinMode(sf,INPUT);
  pinMode(sb,INPUT);
  pinMode(so,OUTPUT);
}

void loop()
{
  
  if(digitalRead(sf)==1)
  {
    if(digitalRead(sr) && !digitalRead(sl))
    {
      analogWrite(so,1023);//turn left
      analogWrite(wo,512);//turn with half speed
    }  
    else if(!digitalRead(sr) && digitalRead(sl))
    {
      analogWrite(so,0);//turn right
      analogWrite(wo,512);// turn with half speed
    }  
    else if(digitalRead(sr) && digitalRead(sl))
    {
      analogWrite(so,512);//no turn
      analogWrite(wo,0); // halt
    }   
  }
  else 
  {
    analogWrite(so,512);// go straight
    analogWrite(wo,1023);// full speed
  }
}
