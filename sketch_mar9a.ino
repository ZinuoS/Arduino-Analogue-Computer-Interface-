const int outputPin = 8;      
const int analogInputPin = A2;  

const int numPoints = 86;

const float forceData[numPoints] = {
  -4.038,
  -4.035,
  -4.034,
  -4.034,
  -4.033,
  -4.033,
  -4.032,
  -4.032,
  -3.893,
  -1.667,
  -0.106,
  1.483,
  2.841,
  3.761,
  4.101,
  3.807,
  2.925,
  1.591,
  -0.014,
  -1.621,
  -2.948,
  -0.906,
  0.718,
  2.225,
  3.373,
  4.011,
  4.032,
  3.431,
  2.299,
  0.811,
  -0.825,
  -2.319,
  -3.454,
  -4.043,
  -3.993,
  -3.313,
  -2.111,
  1.294,
  2.683,
  3.671,
  4.093,
  3.881,
  3.071,
  1.782,
  0.200,
  -3.282,
  -3.983,
  -4.049,
  -2.243,
  -0.731,
  0.868,
  2.344,
  3.461,
  4.041,
  3.999,
  3.337,
  2.161,
  0.630,
  -0.993,
  -2.464,
  -3.549,
  -4.071,
  -3.945,
  -3.195,
  1.888,
  3.149,
  3.917,
  4.083,
  3.619,
  2.576,
  1.158,
  -0.469,
  -2.015,
  -4.005,
  -4.035,
  0.067,
  1.629,
  2.954,
  3.822,
  4.101,
  3.746,
  2.811,
  1.422,
  -2.389,
  -4.062,
  -1.770
};
// force range: -4.071 to 4.101 N
const float forceMin = -4.071 ; 
const float forceMax = 4.101; 

int mapForceToPWM(float force) {
  int pwm = (int)(((force - forceMin) / (forceMax - forceMin)) * 255.0);
  if (pwm < 0)   pwm = 0;
  if (pwm > 255) pwm = 255;
  return pwm;
}

void setup() {
  pinMode(outputPin, OUTPUT);
  pinMode(analogInputPin, INPUT);
  Serial.begin(9600);
}

void loop() {
  for (int i = 0; i < numPoints; i++) {
    int pwmVal = mapForceToPWM(forceData[i]);
    analogWrite(outputPin, pwmVal);
    delay(5);  
    int analogValue = analogRead(analogInputPin);
    float voltage = analogValue * (5.0 / 1023.0);
    
    Serial.print("Force: ");
    Serial.print(forceData[i], 3);
    Serial.print(" N, PWM: ");
    Serial.print(pwmVal);
    Serial.print(", Voltage: ");
    Serial.print(voltage,3);
    Serial.println(" V");
  }
}

