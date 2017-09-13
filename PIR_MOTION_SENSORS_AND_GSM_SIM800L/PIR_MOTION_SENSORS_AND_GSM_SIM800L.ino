/*  
    Arduino with PIR motion sensor
    For complete project details, visit: http://RandomNerdTutorials.com/pirsensor
    Modified by Rui Santos based on PIR sensor by Limor Fried
*/
 
int led = 13;                // the pin that the LED is atteched to
int sensor1 = 2;              // the pin that the sensor is atteched to
int sensor2 = 3;              // the pin that the sensor is atteched to
int sensor3 = 4;              // the pin that the sensor is atteched to
int val1 = 0;                 // variable to store the sensor status (value)
int val2 = 0;                 // variable to store the sensor status (value)
int val3 = 0;                 // variable to store the sensor status (value)

void setup() {
  pinMode(led, OUTPUT);      // initalize LED as an output
  pinMode(sensor1, INPUT);    // initialize sensor as an input
  pinMode(sensor2, INPUT);    // initialize sensor as an input
  pinMode(sensor3, INPUT);    // initialize sensor as an input
  Serial.begin(9600);        // initialize serial
}

void loop(){
  delay(300);
  val1 = digitalRead(sensor1);   // read sensor value
  val2 = digitalRead(sensor2);   // read sensor value
  val3 = digitalRead(sensor3);   // read sensor value
  //sensor 1
  if (val1 == HIGH) {           // check if the sensor is HIGH
    digitalWrite(led, HIGH);   // turn LED ON
     Serial.println("Motion in room 1 detected!");
   // delay(100);                // delay 100 milliseconds 
  } 
  else {
      digitalWrite(led, LOW); // turn LED OFF
      /// Serial.println("Motion in room 1 stopped!");
     // delay(200);             // delay 200 milliseconds 
  }

  //sensor2
  if (val2 == HIGH) {           // check if the sensor is HIGH
    digitalWrite(led, HIGH);   // turn LED ON
     Serial.println("Motion in room 2 detected!");
   // delay(100);                // delay 100 milliseconds 
  } 
  else {
      digitalWrite(led, LOW); // turn LED OFF
     // delay(200);             // delay 200 milliseconds 
  }

  //sensor3
  if (val3 == HIGH) {           // check if the sensor is HIGH
    digitalWrite(led, HIGH);   // turn LED ON
     Serial.println("Motion in room 3 detected!");
    //delay(100);                // delay 100 milliseconds 
  } 
  else {
      digitalWrite(led, LOW); // turn LED OFF
     // delay(200);             // delay 200 milliseconds 
  }
}

