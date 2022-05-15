const int ch = 6;
const int relay[] = {2, 3, 4, 5, 6, 7};

const int buttonPin_1 = 9;
int buttonState_1 = 0;

const int buttonPin_2 = 8;
int buttonState_2 = 0;

const int ledPin = 13;

int wait_1 = 2500;
int wait_2 = 500;
int i = 0;

void setup() {
  Serial.begin(9600);

  for (int i = 0; i < ch; i++) {
    pinMode(relay[i], OUTPUT);
    digitalWrite(relay[i], HIGH);
  }

  pinMode(buttonPin_1, INPUT);
  pinMode(buttonPin_2, INPUT);
  
  pinMode(ledPin, OUTPUT);

  Serial.println("ALL SET!!");
}

void loop() {
  buttonState_1 = digitalRead(buttonPin_1);
  buttonState_2 = digitalRead(buttonPin_2);
//  Serial.println(buttonState_1);
//  Serial.println(buttonState_2);

  if (buttonState_1 == HIGH) {
    digitalWrite(ledPin, HIGH);
    
    digitalWrite(relay[2], HIGH);
    digitalWrite(relay[5], LOW);
    
    digitalWrite(relay[0], LOW);
    digitalWrite(relay[1], HIGH);
    digitalWrite(relay[3], HIGH);
    digitalWrite(relay[4], HIGH);
    delay(wait_1);

    digitalWrite(relay[0], HIGH);
    digitalWrite(relay[1], LOW);
    digitalWrite(relay[3], HIGH);
    digitalWrite(relay[4], HIGH);
    delay(wait_1);
  }
  if(buttonState_1 == LOW){
    digitalWrite(ledPin, LOW);
    
    digitalWrite(relay[2], LOW);
    digitalWrite(relay[5], HIGH);
    
    digitalWrite(relay[0], HIGH);
    digitalWrite(relay[1], HIGH);
    digitalWrite(relay[3], LOW);
    digitalWrite(relay[4], HIGH);
    delay(wait_2);

    digitalWrite(relay[0], HIGH);
    digitalWrite(relay[1], HIGH);
    digitalWrite(relay[3], HIGH);
    digitalWrite(relay[4], LOW);
    delay(wait_2);
  }



}
