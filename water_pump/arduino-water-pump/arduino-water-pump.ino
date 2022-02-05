byte pump1 = 7;
byte pump2 = 10;
void setup() {
 Serial.begin(9600);
 while (!Serial);  
 pinMode(pump1, OUTPUT); // variant low/high
 pinMode(pump2, OUTPUT); // variant low/high
// digitalWrite(pump1, LOW); // variant input/output
// digitalWrite(pump2, LOW); // variant input/output
}
void loop() {
 digitalWrite(pump1, HIGH); // pump1 deactivated
 digitalWrite(pump2, LOW); // variant input/output
 delay(2000);
 
 digitalWrite(pump1, LOW); // pump1 activated
 digitalWrite(pump2, HIGH); // variant input/output 
 delay(2000);
}
