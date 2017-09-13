   #include <gprs.h>
  #include <SoftwareSerial.h>

  GPRS gprs;
  
  int led1 = 13; // the pin that the LED isatteched to
  int led2 = 12; // the pin that the LED isatteched to
  int ledR = 9; // the pin that the LED isatteched to
  int sensor1 = 2; // the pin that the sensor is atteched to
  int sensor2 = 3; // the pin that the sensor is atteched to
  int sensor3 = 4; // the pin that the sensor is atteched to
  int state1 = LOW; // by default, no motion detected
  int state2 = LOW; // by default, no motion detected
  int state3 = LOW; // by default, no motion detected
  int val = 0; // variable to store the sensor status (value)
  int val2 = 0; // variable to store the sensor status (value)
  int val3 = 0; // variable to store the sensor status (value)
 


void setup() {
   Serial.begin(9600); // initialize serial
  
   //start gsm
  while(!Serial);
  Serial.println("GPRS - Send SMS Test ...");
  gprs.preInit();
  delay(1000);
  while(0 != gprs.init()) {
      delay(1000);
      Serial.print("init error\r\n");
  }  
  Serial.println("Init success, start to send SMS message...");
  gprs.sendSMS("0719325974","System Is Ready"); //define phone number and text
  //end  of  gsm
   
   pinMode(led1, OUTPUT); // initalize LED as an output
    pinMode(led2, OUTPUT); // initalize LED as an output
     pinMode(ledR, OUTPUT); // initalize LED as an output
   pinMode(sensor1, INPUT); // initialize sensor as an input
   pinMode(sensor2, INPUT); // initialize sensor as an input
   pinMode(sensor3, INPUT); // initialize sensor as an input
  
}
void loop(){
  
     val = digitalRead(sensor1); // read sensor value
     val2 = digitalRead(sensor2); // read sensor value
     val3 = digitalRead(sensor3); // read sensor value

     //sensor1
     if (val == HIGH) { // check if the sensor is HIGH
     
     delay(3000); // delay 100 milliseconds
     digitalWrite(led1, HIGH); // turn LED ON
     if (state1 == LOW) {
     Serial.println("Motion in room 1 detected!");
     gprs.sendSMS("0719325974","Motion in room 1 detected");
     delay(200);
     state1 = HIGH; // update variable state to HIGH
     }
     }
     else {
     digitalWrite(led1, LOW); // turn LED OFF
     //delay(20); // delay 200 milliseconds 
      if (state1 == HIGH){
     Serial.println("Motion in room 1 stopped!");
     state1 = LOW; // update variable state to LOW
     }
     }




////     //sensor2
//    if (val2 == HIGH) { // check if the sensor is HIGH
//     digitalWrite(led2, HIGH); // turn LED ON
//   // delay(10); // delay 100 milliseconds
//   
//    if (state2 == LOW) {
//     Serial.println("Motion in room 2 detected!");
//     gprs.sendSMS("0705419309","Motion in room 2 detected");
//      delay(200);
//     state2 = HIGH; // update variable state to HIGH
//     }
//     }
//     else {
//     digitalWrite(led2, LOW); // turn LED OFF
//    //delay(20); // delay 200 milliseconds 
//     if (state2 == HIGH){
//    Serial.println("Motion in room 2 stopped!");
//    state2 = LOW; // update variable state to LOW
//    }
//    }


     //sensor3
     if (val3 == HIGH) { // check if the sensor is HIGH
     digitalWrite(ledR, HIGH); // turn LED ON
     delay(3000); // delay 100 milliseconds
    
     if (state3 == LOW) {
     Serial.println("Motion in room 3 detected!");
     gprs.sendSMS("0719325974","Motion in room 3 detected");
      delay(200);
     state3 = HIGH; // update variable state to HIGH
     }
     }
     else {
     digitalWrite(ledR, LOW); // turn LED OFF
     delay(20); // delay 200 milliseconds 
      if (state3 == HIGH){
     Serial.println("Motion in room 3 stopped!");
    state3 = LOW; // update variable state to LOW
     }
     }
}
