int motorR1=D0;
int motorR2=D1;
int motorL1=D2;
int motorL2=D3;
int EN1=D5;
int EN2=D6;
int trig=D7;
int echo=D8;

void setup() 
{
    
    pinMode(EN1,OUTPUT);
    pinMode(EN2,OUTPUT);
    
    pinMode(motorL1,OUTPUT);
    pinMode(motorL2,OUTPUT);
    pinMode(motorR1,OUTPUT);
    pinMode(motorR2,OUTPUT);

    pinMode(trig,OUTPUT);
    pinMode(echo,INPUT);
    
    digitalWrite(EN1,HIGH);
    digitalWrite(EN2,HIGH);
    
    Serial.begin(115200); // Setting the baud rate
    
  
}

void loop() 
{

    digitalWrite(trig,LOW);
    delayMicroseconds(5);
    digitalWrite(trig,HIGH);
    delayMicroseconds(10);
    digitalWrite(trig,LOW);

    int duration=pulseIn(echo,HIGH);

    int distance= duration/2/29.1;  //distance in cm,  Divide by 29.1 or multiply by 0.0343
    Serial.println(distance);
    
    /*distance = (traveltime/2) x speed of sound

    The speed of sound is: 343m/s = 0.0343 cm/uS = 1/29.1 cm/uS*/
   
    
    if(distance>10)
    {
      forward();
      Serial.println("Moving forward");
    }
    else if(0<distance<10)
    {
      Serial.print("Obstacle detected at:"+distance);
      nomove();
      delay(200);
      right();
      delay(1000);
    }
     
  
}

void forward()
{
      digitalWrite(motorL1,LOW);  //Left part moving anticlockwise
      digitalWrite(motorL2,HIGH);
      digitalWrite(motorR1,HIGH); //Right part moving clockwise
      digitalWrite(motorR2,LOW);
}

void right()
{
      digitalWrite(motorL1,LOW);   //Left part moving anticlockwise
      digitalWrite(motorL2,HIGH);
      digitalWrite(motorR1,LOW);  //Right part not moving
      digitalWrite(motorR2,LOW);
}

void nomove()
{
      digitalWrite(motorL1,LOW);   //Left part not moving
      digitalWrite(motorL2,LOW);
      digitalWrite(motorR1,LOW);   //Right part not moving
      digitalWrite(motorR2,LOW);
}
