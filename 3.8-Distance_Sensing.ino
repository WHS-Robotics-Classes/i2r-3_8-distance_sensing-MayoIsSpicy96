const int trigPin = 7;
const int echoPin = 8;

const int LED1 = 2;
const int LED2 = 3;
const int LED3 = 4;


int duration = 0;
int distance = 0;

void setup() 
{
  pinMode(trigPin , OUTPUT);
  pinMode(echoPin , INPUT);
  
  pinMode(LED1 , OUTPUT);
  pinMode(LED2 , OUTPUT);
  pinMode(LED3 , OUTPUT);
 
  
  Serial.begin(9600);

}

void loop()
{
 digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);  
  duration = pulseIn(echoPin, HIGH);
  distance = duration/58.2;
  Serial.print(distance);
  Serial.println(" cm");
  if ( distance < 35 )
  {
    digitalWrite(LED1, HIGH);
  }
  else
  {
    digitalWrite(LED1, LOW);
  }
  if ( distance <= 15 )
  {
    digitalWrite(LED2, HIGH);
    digitalWrite(LED1, LOW);
  }
  else
  {
    digitalWrite(LED2, LOW);
  }
  if ( distance <= 10 )
  {
    digitalWrite(LED3, HIGH);
    digitalWrite(LED2, LOW);
  }
  else
  {
    digitalWrite(LED3, LOW);
}
}
