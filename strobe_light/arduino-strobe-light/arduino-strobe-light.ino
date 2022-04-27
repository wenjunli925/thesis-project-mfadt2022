// CONSTANTS
//const byte potPin = A0;
const byte strobePin = 3;
const byte buttonPin = 4;

//VARIABLES
unsigned long totalTime;
int sec;
int tPosition;

int buttonState = 0;
int buttonCount = 0;

void setup() {
  Serial.begin(9600);

  pinMode(strobePin, OUTPUT);
  pinMode(buttonPin, INPUT);
}

void loop() {
  totalTime = millis();
  sec = totalTime / 1000;
  tPosition = sec % 60;

//  Serial.println(sec);
//  Serial.println(tPosition);
  int refreshRate = map(tPosition, 0, 60, 500, 20);

//  Serial.println(refreshRate);


  buttonState = digitalRead(buttonPin);
  
  if(buttonState == HIGH){
    if(buttonCount > 2){
      buttonCount = 0;
    }
    
    buttonCount += 1;
    delay(300);
  }

  Serial.println(buttonCount);

  if(buttonCount == 1){
    digitalWrite(strobePin, LOW);
  }

  if(buttonCount == 2){
    // Turn the strobe LED on
    digitalWrite(strobePin, HIGH);
    delay(20);
    // Turn it off again
    digitalWrite(strobePin, LOW);
    delay(refreshRate - 20);
  }

  if(buttonCount == 3){
    digitalWrite(strobePin, HIGH);
  }


}
