// Sensor 1 (Left Side)
#define TRIG1 8
#define ECHO1 7
#define LED1_1 12
#define LED1_2 13

// Sensor 2 (Right Side)
#define TRIG2 9
#define ECHO2 10
#define LED2_1 4
#define LED2_2 5

// Obstacle distance threshold (in cm)
#define THRESHOLD 30

void setup() {
  Serial.begin(9600);
  pinMode(TRIG1, OUTPUT); pinMode(ECHO1, INPUT);
  pinMode(LED1_1, OUTPUT); pinMode(LED1_2, OUTPUT);
  pinMode(TRIG2, OUTPUT); pinMode(ECHO2, INPUT);
  pinMode(LED2_1, OUTPUT); pinMode(LED2_2, OUTPUT);
}

long readDistanceCM(int trigPin, int echoPin) {
  digitalWrite(trigPin, LOW); delayMicroseconds(2);
  digitalWrite(trigPin, HIGH); delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  long duration = pulseIn(echoPin, HIGH);
  return duration * 0.034 / 2;
}

void loop() {
  long distance1 = readDistanceCM(TRIG1, ECHO1);
  long distance2 = readDistanceCM(TRIG2, ECHO2);
  Serial.print("Left: "); Serial.print(distance1);
  Serial.print(" cm | Right: "); Serial.println(distance2);

  if (distance1 > 0 && distance1 <= THRESHOLD) { digitalWrite(LED1_1, HIGH); digitalWrite(LED1_2, HIGH); }
  else { digitalWrite(LED1_1, LOW); digitalWrite(LED1_2, LOW); }

  if (distance2 > 0 && distance2 <= THRESHOLD) { digitalWrite(LED2_1, HIGH); digitalWrite(LED2_2, HIGH); }
  else { digitalWrite(LED2_1, LOW); digitalWrite(LED2_2, LOW); }

  delay(200);
}
