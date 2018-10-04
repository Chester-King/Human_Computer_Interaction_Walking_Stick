#define trigPin  12     // Connections of the first ultrasonic sensor
#define echoPin  13
#define trigPin1  4     // Connections of the second ultrasonic sensor
#define echoPin1  5
#define Buzzer 7  // The buzzers would be connected to pin 7      

void setup ()    // Defining the pinmodes for every pin on the arduino i.e. which pin gives output and which gives input
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

     long duration,duration1,distance,distance1;        // Variable declaration
     
     /*
        In the lines below we are defining the value of the pins and
        making them ready for use  
     */
        
     digitalWrite(trigPin, LOW);
     delayMicroseconds(2);
     
     digitalWrite(trigPin, HIGH);
     delayMicroseconds(10);
     digitalWrite(trigPin, LOW);
        
     /*
       Using the pulse function to find the eco of the ultra sound sent by
       the ultrasonic sensor and using it to find the distance
      */
     
     duration = pulseIn(echoPin, HIGH);
     distance = (duration/2) / 29.1;      // The system is similar to Sonar
     digitalWrite(trigPin, LOW);

     digitalWrite(trigPin1, LOW);
     delayMicroseconds(2);
     
     digitalWrite(trigPin1, HIGH);
     delayMicroseconds(10);
     digitalWrite(trigPin1, LOW);
     
        /*
       Using the pulse function to find the eco of the ultra sound sent by
       the ultrasonic sensor and using it to find the distance
      */
     
     duration1 = pulseIn(echoPin1, HIGH);
     distance1 = (duration1/2) / 29.1;
     digitalWrite(trigPin1, LOW);
        
// If the object is detected on the left
// Keep the buzzer frequency as 1000
     
  if (distance<70 || distance>0 && distance1>=70)
       {
       Serial.println("object detected \n");
       Serial.print("distance= ");
       Serial.print(distance);
       digitalWrite(Buzzer, HIGH);
       tone(Buzzer,1000);
       }
       
// If the object is detected on the right
// Keep the buzzer frequency as 5000       
        
  if (distance>=70 && distance1<70)
       {
       Serial.println("object detected \n");
       Serial.print("distance1= ");
       Serial.print(distance1);
       digitalWrite(Buzzer, HIGH);
       tone(Buzzer,5000);
       }
       
// If the object is detected on the left and right
// Means the the object is in front
// Keep the buzzer frequency as 7000
 
       
  if (distance<70 && distance1<70)
       {
       Serial.println("object detected");
       digitalWrite(Buzzer, HIGH);
       tone(Buzzer,7000);   
       }
        
// When no object detected on either side
// No object in the vicinity 
        
  if(distance>70 && distance1>70) 
       {
        Serial.println("no object detected");
        digitalWrite(Buzzer, LOW);
        noTone(Buzzer);
       }     
        
  // A delay of 500 miliseconds every time after the loop block works
        
delay(500);
}
