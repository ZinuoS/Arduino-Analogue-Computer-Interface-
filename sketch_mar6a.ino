int trigPin = 3;
int echoPin = 7;

void setup() {         
  pinMode(trigPin, OUTPUT);  
  pinMode(echoPin, INPUT);
  Serial.begin(9600); 
}

void loop() {
  long duration;
  float distanceCm;
  digitalWrite(trigPin, LOW);
  delayMicroseconds(1);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distanceCm = duration * 0.017;
  Serial.print("Distance: ");
  Serial.print(distanceCm);
  Serial.println(" cm");
  delay(100);
}
