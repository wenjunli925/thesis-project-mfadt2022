const int ch = 6;
const int relay[] = {2, 3, 4, 5, 6, 7};

const int buttonPin = 8;
int buttonState = 0;

const int echoPin = 12;
const int trigPin = 13;
long duration;
int distance;

int wait = 500;
int i = 0;

void setup() {
  Serial.begin(9600);

  for (int i = 0; i < ch; i++) {
    pinMode(relay[i], OUTPUT);
    digitalWrite(relay[i], HIGH);
  }

  pinMode(buttonPin, INPUT);

  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);

  Serial.println("ALL SET!!");
}

void loop() {
  buttonState = digitalRead(buttonPin);
  
  Serial.print("Button State: ");
  Serial.println(buttonState);

  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distance = duration * 0.034 / 2;
  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");


  if (distance > 300) {
    wait = 2000;
    
    digitalWrite(relay[4], LOW);
    digitalWrite(relay[5], HIGH);

    digitalWrite(relay[0], LOW);
    digitalWrite(relay[1], HIGH);
    digitalWrite(relay[2], HIGH);
    digitalWrite(relay[3], HIGH);
    delay(wait);

    digitalWrite(relay[0], HIGH);
    digitalWrite(relay[1], LOW);
    digitalWrite(relay[2], HIGH);
    digitalWrite(relay[3], HIGH);
    delay(wait);
  }
  
  if (distance <= 300) {
    wait = map(distance, 0, 300, 200, 800);
    
    digitalWrite(relay[4], HIGH);
    digitalWrite(relay[5], LOW);

    digitalWrite(relay[0], HIGH);
    digitalWrite(relay[1], HIGH);
    digitalWrite(relay[2], LOW);
    digitalWrite(relay[3], HIGH);
    delay(wait);

    digitalWrite(relay[0], HIGH);
    digitalWrite(relay[1], HIGH);
    digitalWrite(relay[2], HIGH);
    digitalWrite(relay[3], LOW);
    delay(wait);
  }

  Serial.print("Wait ");
  Serial.println(wait);

  //  digitalWrite(relay[0], LOW);
  //  digitalWrite(relay[1], HIGH);
  //  delay(wait);
  //
  //  digitalWrite(relay[0], HIGH);
  //  digitalWrite(relay[1], LOW);
  //  delay(wait);



}
