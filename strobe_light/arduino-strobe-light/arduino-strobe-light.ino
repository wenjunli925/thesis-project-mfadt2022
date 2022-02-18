// CONSTANTS
const byte potPin = A0;
const byte strobePin = 3;

void setup() {
  Serial.begin(9600);
  
  pinMode(strobePin, OUTPUT);
}

void loop() {
  // Analog red gives a value between 0-1023
  int potValue = analogRead(potPin);
  // Convert this to a sensible range of values for the strobe delay
  int refreshRate = map(potValue, 0, 1023, 500, 5);
  
  // Turn the strobe LED on
  digitalWrite(strobePin, HIGH);
  delay(20);
  // Turn it off again
  digitalWrite(strobePin, LOW);
  delay(refreshRate-20);

  Serial.println(potValue);
  Serial.println(refreshRate);
}
