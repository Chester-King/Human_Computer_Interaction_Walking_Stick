#define trigPin  12
#define echoPin  13
#define trigPin1  4
#define echoPin1  5
#define Buzzer 7

void setup ()
        {
        Serial.begin(9600);
        pinMode(trigPin, OUTPUT);
        pinMode(echoPin, INPUT);
        pinMode(trigPin1, OUTPUT);
        pinMode(echoPin1, INPUT);
        pinMode(Buzzer, OUTPUT);
        }

void loop () 
{

     long duration,duration1,distance,distance1;
     
     digitalWrite(trigPin, LOW);
     delayMicroseconds(2);
     
     digitalWrite(trigPin, HIGH);
     delayMicroseconds(10);
     digitalWrite(trigPin, LOW);
     
     duration = pulseIn(echoPin, HIGH);
     distance = (duration/2) / 29.1;
     digitalWrite(trigPin, LOW);

     digitalWrite(trigPin1, LOW);
     delayMicroseconds(2);
     
     digitalWrite(trigPin1, HIGH);
     delayMicroseconds(10);
     digitalWrite(trigPin1, LOW);
     
     duration1 = pulseIn(echoPin1, HIGH);
     distance1 = (duration1/2) / 29.1;
     digitalWrite(trigPin1, LOW);
     
  if (distance<70 || distance>0 && distance1>=70)
       {
       Serial.println("object detected \n");
       Serial.print("distance= ");
       Serial.print(distance);
       digitalWrite(Buzzer, HIGH);
       tone(Buzzer,1000);
       }
       
  if (distance>=70 && distance1<70)
       {
       Serial.println("object detected \n");
       Serial.print("distance1= ");
       Serial.print(distance1);
       digitalWrite(Buzzer, HIGH);
       tone(Buzzer,5000);
       }
       
  if (distance<70 && distance1<70)
       {
       Serial.println("object detected");
       digitalWrite(Buzzer, HIGH);
       tone(Buzzer,7000);   
       }
  if(distance>70 && distance1>70) 
       {
        Serial.println("no object detected");
        digitalWrite(Buzzer, LOW);
        noTone(Buzzer);
       }     
delay(500);
}
