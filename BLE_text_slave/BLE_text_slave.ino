#include <Servo.h>

#define led 13
int pos = 0;
int val = 5;

#define SERVO_PIN    9
Servo myServo;
int servoAngle = 90;

void setup() {
  Serial.begin(38400);
  
  pinMode(led, OUTPUT);
  
  myServo.attach(SERVO_PIN); 
}

void loop() {
  if (Serial.available() > 0)
  {
    val = Serial.read();

    //test bluetooth connection with a led
    if (val == 100  && pos == 0)
    {
      digitalWrite(led, HIGH);
      pos = 1;
    }
    else if (val == 100 && pos == 1)
    {
      digitalWrite(led, LOW);
      pos = 0;
    }


    if (val == 100)
    {
      digitalWrite(led, HIGH);
      servoAngle = 180;
    }
    else
    {
      digitalWrite(led, LOW);
      servoAngle = 0;
    }

  }

  myServo.write(servoAngle);

}
