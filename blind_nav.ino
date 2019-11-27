const int trigPin = 2;
const int echoPin = 4;
const int motor = 5;
long duration = 0;
float cm = 0;

void setup() {
  // initialize serial communication:
  Serial.begin(9600);
  pinMode (trigPin, OUTPUT);
  pinMode (motor, OUTPUT);
  pinMode (echoPin, INPUT);
  digitalWrite(trigPin, LOW);
}

void loop()
{
  digitalWrite (trigPin, HIGH);
  delayMicroseconds(2);
  digitalWrite (trigPin, LOW);
  delayMicroseconds(2);
  duration = pulseIn(echoPin, HIGH);
  cm =(duration/29)/2;
  
  //Serial.println(analogRead(A0)/10);
  if (cm <= analogRead(A0)/10)
  {
    Serial.println(cm);
    digitalWrite(motor, HIGH);
    delay(cm*10);
    digitalWrite(motor, LOW);
    delay(cm*10);
  }
}
  
  
  
  
