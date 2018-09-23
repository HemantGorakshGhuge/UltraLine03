int m1 = 4;
int m2 = 5;
int pwm1 = 6;
int pwm2 = 7;
int x=0;
int y=0;
int s1 = 8;
int s2 = 9;
int s3 = 10;
int s4 = 11;
int s5 = 12;

int a, b, c, d, e;

  
void setup() {
  // put your setup code here, to run once:
  pinMode(m1, OUTPUT);
  pinMode(m2, OUTPUT);
  pinMode(pwm1, OUTPUT);
  pinMode(pwm2, OUTPUT);

  pinMode(s1, INPUT);
  pinMode(s2, INPUT);
  pinMode(s3, INPUT);
  pinMode(s4, INPUT);
  pinMode(s5, INPUT);

  digitalWrite(m1, LOW);
  digitalWrite(m2, LOW);
  analogWrite(pwm1, 0);
  analogWrite(pwm2, 0);
  
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  a = digitalRead(s1);
  b = digitalRead(s2);
  c = digitalRead(s3);
  d = digitalRead(s4);
  e = digitalRead(s5);

Serial.print("x= ");
Serial.println(x);
Serial.print("y= ");
Serial.println(y);

//********************2 IR HIGH*******************//
if(a==HIGH && b==HIGH && c==LOW && d==LOW && e==LOW)
{
  fullright();
}
if(a==LOW && b==HIGH && c==HIGH && d==LOW && e==LOW)
{
  slightright();
}
if(a==LOW && b==LOW && c==HIGH && d==HIGH && e==LOW)
{
  slightleft();
}
if(a==LOW && b==LOW && c==LOW && d==HIGH && e==HIGH)
{
  fullleft();   
}
//********************3 IR HIGH**********************//
if(a==HIGH && b==HIGH && c==HIGH && d==LOW && e==LOW)
{
  slightright();
}
if(a==LOW && b==HIGH && c==HIGH && d==HIGH && e==LOW)
{
  fwd();
}
if(a==LOW && b==LOW && c==HIGH && d==HIGH && e==HIGH)
{
  slightleft();
}
//*******************4 IR HIGH******************//

if(a==HIGH && b==HIGH && c==HIGH && d==HIGH && e==LOW)
{
  slightright();    
  y++;
}

if(y==1)
{
  fullright();
  y++;
  delay(500);  
}
if(a==LOW && b==HIGH && c==HIGH && d==HIGH && e==HIGH)
{
  slightleft();
}

if(a==HIGH && b==HIGH && c==HIGH && d==HIGH && e==HIGH)
  {
   x++;
    delay(200);
    }
if(a==HIGH && b==HIGH && c==HIGH && d==HIGH && e==HIGH)
{
    if(x==1)
    {
    fullleft();
    x++;
    delay(1000);
    }
    if(x==3)
    {
     x++;
     delay(100);
     }
     if(x==5)
    {
     rest();
     delay(3000);
     clk();
     x++;
     delay(700);
    }
    if(x==7)
    {
     x++;
     }
     if(x==9)
     {
      rest();
      delay(3000);
      fullleft();
      x++;
      delay(1000);      
      }
      if(x==11)
      {
       fullleft();
      x++;
      delay(1000);
    }
    if(x==13)
    {
     x++;
     delay(100);
     }
     if(x==15)
    {
     rest();
     delay(3000);
     clk();
     x++;
     delay(700);
    }
    if(x==17)
    {
     x++;
     }
     if(x==19)
     {
      rest();
      delay(3000);
      clk();
      x++;
      delay(700);      
      }
      if(x==21)
      {
       x++;
       }
      if(x==23)
      {
       x++;
       }
      if(x==25)
      {
       x++;
       }
       if(x==27)
      {
       x++;
       }
      if(x==29)
    {
     rest();
     delay(3000);
     clk();
     x++;
     delay(700);
    }
    if(x==35)
    {
    rest();  
    }
      
  }
}

 void fwd()
    {
      digitalWrite(m1, HIGH);
      digitalWrite(m2, HIGH);
      analogWrite(pwm1, 150);
      analogWrite(pwm2, 150);
    }
    void rev()
    {
      digitalWrite(m1, LOW);
      digitalWrite(m2, LOW);
      analogWrite(pwm1, 75);
      analogWrite(pwm2, 75);
      
      }
    void fullleft()
    { digitalWrite(m1, HIGH);
      digitalWrite(m2, HIGH);
      analogWrite(pwm1, 75);
      analogWrite(pwm2, 0);
    }
    void slightleft()
    { digitalWrite(m1, HIGH);
      digitalWrite(m2, HIGH);
      analogWrite(pwm1, 100);
      analogWrite(pwm2, 75);
    }
    void fullright()
    {
      digitalWrite(m1, HIGH);
      digitalWrite(m2, HIGH);
      analogWrite(pwm1, 0);
      analogWrite(pwm2, 75);
    }
    void slightright()
    {
      digitalWrite(m1, HIGH);
      digitalWrite(m2, HIGH);
      analogWrite(pwm1, 75);
      analogWrite(pwm2, 100);
    }

    void clk()
    {
      digitalWrite(m1, HIGH);
      digitalWrite(m2, LOW);
      analogWrite(pwm1, 100);
      analogWrite(pwm2, 100);
      
    }
    
    void rest()
   {     
      digitalWrite(m1, HIGH);
      digitalWrite(m2, HIGH);
      analogWrite(pwm1, 0);
      analogWrite(pwm2, 0);
  }
