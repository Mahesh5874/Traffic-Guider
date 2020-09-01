#define trigPin1 0
#define echoPin1 1
#define trigPin2 2
#define echoPin2 3
#define trigPin3 4
#define echoPin3 5
#define trigPin4 9
#define echoPin4 10

const int buttonPin = 11;
const int ledPin = 13;

int buttonState = 0;
int ledState = 0;

long duration;
int distance, distNorthUltraSensor, distWestUltraSensor, distEastUltraSensor, distSouthUltraSensor, counterW, counterE, counterS;
/* NorthUltraSensor - 0, 1
 * WestUltraSensor  - 2, 3
 * EastUltraSensor - 4, 5
 * SouthUltraSensor  - 9, 10
 */

void SonarSensor(int trigPin, int echoPin);
void setup() {
  //NorthUltraSensor
  pinMode(trigPin1, OUTPUT);
  pinMode(echoPin1, INPUT);

  //SouthUltraSensor
  pinMode(trigPin2, OUTPUT);
  pinMode(echoPin2, INPUT);

  //EastUltraSensor
  pinMode(trigPin3, OUTPUT);
  pinMode(echoPin3, INPUT);

  //WestUltraSensor
  pinMode(trigPin4, OUTPUT);
  pinMode(echoPin4, INPUT);

  pinMode(buttonPin, INPUT);
  pinMode(ledPin, OUTPUT);

  Serial.begin(9600);
}

void loop() {
  SonarSensor(trigPin1, echoPin1);
  distNorthUltraSensor = distance;
  
  SonarSensor(trigPin2, echoPin2);
  distWestUltraSensor = distance;
  
  SonarSensor(trigPin3, echoPin3);
  distEastUltraSensor = distance;
  
  SonarSensor(trigPin4, echoPin4);
  distSouthUltraSensor = distance;
/*
  Serial.print("NorthUltraSonicSensor: ");
  Serial.println(distNorthUltraSensor);
  Serial.print("SouthUltraSonicSensor: ");
  Serial.println( distSouthUltraSensor);
  Serial.print("EastUltraSonicSensor: ");
  Serial.println(distWestUltraSensor);
  Serial.print("LeftUltraSonicSensor: ");
  Serial.println(distEastUltraSensor);
*/
  if( distWestUltraSensor < 10 ){
    counterW++;
    Serial.print("counter west:");
    Serial.println(counterW);
    
  }

  if( distEastUltraSensor < 10 ){
    counterE++;
    Serial.print("counter east:");
    Serial.println(counterE);
  }

  if( distSouthUltraSensor < 10 ){
    counterS++;
    Serial.print("counter south:");
    Serial.println(counterS);
  }
 /*
 We have only 1 LED light 
 so we used number of blinking
 if it blinks 1 times then it shows output for WEST
 if it blinks 2 times then it shows output for NORTH
 if it blinks 3 times then it shows output for SOUTH
 if it blinks 4 times then it shows output for EAST
 */
  buttonState = digitalRead(buttonPin);
if (buttonState == HIGH) {
if (counterW > counterE)
    {
        if (counterW > counterS)
        {
            Serial.println("Open west");
             digitalWrite(ledPin,HIGH);
             delay(700);
             digitalWrite(ledPin,LOW);
             delay(700);
             digitalWrite(ledPin,HIGH);
             delay(700);
             digitalWrite(ledPin,LOW);
           
            counterW=0;
           
        }
        else
        {
            Serial.println("Open South");
             digitalWrite(ledPin,HIGH);
             delay(700);
             digitalWrite(ledPin,LOW);
             delay(700);
             digitalWrite(ledPin,HIGH);
             delay(700);
             digitalWrite(ledPin,LOW);
             delay(700);
             digitalWrite(ledPin,HIGH);
             delay(700);
             digitalWrite(ledPin,LOW);
            
            counterS=0;
        }
    }
 else if (counterE > counterS){
        Serial.println("Open East");
         digitalWrite(ledPin,HIGH);
         delay(700);
         digitalWrite(ledPin,LOW);
         delay(700);
         digitalWrite(ledPin,HIGH);
         delay(700);
         digitalWrite(ledPin,LOW);
         delay(700);
         digitalWrite(ledPin,HIGH);
         delay(700);
         digitalWrite(ledPin,LOW);
         delay(700);
         digitalWrite(ledPin,HIGH);
         delay(700);
         digitalWrite(ledPin,LOW);
         delay(700);
        
            counterE=0;
            }
 else{
    
        Serial.println("Open South");
             digitalWrite(ledPin,HIGH);
             delay(700);
             digitalWrite(ledPin,LOW);
             delay(700);
             digitalWrite(ledPin,HIGH);
             delay(700);
             digitalWrite(ledPin,LOW);
             delay(700);
             digitalWrite(ledPin,HIGH);
             delay(700);
             digitalWrite(ledPin,LOW);
            
            counterS=0;
            }
  
}
}

void SonarSensor(int trigPin, int echoPin) {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  
  digitalWrite(trigPin, LOW);

  duration = pulseIn(echoPin, HIGH);
  distance = duration*0.034/2;  
  delay(100);
}
