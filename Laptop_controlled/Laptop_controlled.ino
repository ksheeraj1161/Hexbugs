char ch;

int motorR1= D0;
int motorR2=D1;
int motorL1=D2;
int motorL2=D3;
int EN1=D5;
int EN2=D6;

void setup() 
{
    
    pinMode(EN1,OUTPUT);
    pinMode(EN2,OUTPUT);
    
    pinMode(motorL1,OUTPUT);
    pinMode(motorL2,OUTPUT);
    pinMode(motorR1,OUTPUT);
    pinMode(motorR2,OUTPUT);
    
    digitalWrite(EN1,HIGH);
    digitalWrite(EN2,HIGH);
    
    Serial.begin(115200); // Setting the baud rate
    
  
}

void loop() 
{
   while(Serial.available())
  {
    ch=Serial.read();
    
    if(ch=='f'|| ch=='F')
    {
      forward();
      Serial.println("Moving forward");
    }
    else if(ch=='b'||ch=='B')
    {
      backward();
      Serial.println("Moving Backward");
    }
     else if(ch=='r'||ch=='R')
    {
      right();
      Serial.println("Moving Right");
    }
     else if(ch=='l'||ch=='L')
    {
      left();
      Serial.println("Moving Left");
    }
    else if(ch=='n'||ch=='N')
    {
      nomove();
      Serial.println("No movement");
    }
  }
}

void forward()
{
      digitalWrite(motorL1,LOW);  //Left part moving anticlockwise
      digitalWrite(motorL2,HIGH);
      digitalWrite(motorR1,HIGH); //Right part moving clockwise
      digitalWrite(motorR2,LOW);
}
void backward()
{
      digitalWrite(motorL1,HIGH);  //Left part moving clockwise
      digitalWrite(motorL2,LOW);
      digitalWrite(motorR1,LOW);   //Right part moving anticlockwise
      digitalWrite(motorR2,HIGH);
}
void right()
{
      digitalWrite(motorL1,LOW);   //Left part moving anticlockwise
      digitalWrite(motorL2,HIGH);
      digitalWrite(motorR1,LOW);  //Right part not moving
      digitalWrite(motorR2,LOW);
}
void left()
{
      digitalWrite(motorL1,LOW);   //Left part not moving
      digitalWrite(motorL2,LOW);
      digitalWrite(motorR1,HIGH);  //Right part moving clockwise
      digitalWrite(motorR2,LOW);
}
void nomove()
{
      digitalWrite(motorL1,LOW);   //Left part not moving
      digitalWrite(motorL2,LOW);
      digitalWrite(motorR1,LOW);   //Right part not moving
      digitalWrite(motorR2,LOW);
}
