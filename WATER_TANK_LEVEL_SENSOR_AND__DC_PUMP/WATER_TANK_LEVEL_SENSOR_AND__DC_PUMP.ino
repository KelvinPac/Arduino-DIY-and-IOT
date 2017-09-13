/////////////////////////////////////////////////////////////////////////
//   Using Hc-sr04 utrasonic sensor. Calculate the water level in a tank
//   and turn the outlet pump ON if water level is high(TANK_FULL)
//   If water level  is low turn OFF the outlet pump
/////////////////////////////////////////////////////////////////////////
#include <NewPing.h>

#define TRIGGER_PIN 10
#define ECHO_PIN 9
#define MAX_DISTANCE 200   // height of water tank in CM

int TANK_FULL = 10;  //height of water if the tank is full
int TANK_EMPTY =50; 
boolean running = false;
int RELAY_PIN = 5;

NewPing sonar(TRIGGER_PIN, ECHO_PIN, MAX_DISTANCE); 
//NewPing setup of pins and maximum distance.

void setup() {
 Serial.begin(9600);

 // initialize digital pin LED_BUILTIN as an output.
  pinMode(LED_BUILTIN, OUTPUT);
  pinMode(RELAY_PIN, OUTPUT);
}

void loop() {
 delay(1000);
 unsigned int uS = sonar.ping_cm();  //  
 Serial.print(uS);
 Serial.println("CM");

 if(uS<=TANK_FULL){
  running = true;
 }

 //check if tank is full and turn on pump

 if(uS <= TANK_FULL || running == true){
   //Tank is full. turn on pump
  turnOnPump();    
 }


 if(uS >= TANK_EMPTY){

  running = false;
  //Tank is full. turn on pump
  turnOffPump();
  
 }
 
}

void turnOnPump(){
  Serial.println("Water Pump is ON");
  digitalWrite(LED_BUILTIN, HIGH);
  digitalWrite(RELAY_PIN, HIGH);
}

void turnOffPump(){
  Serial.println("Water Pump is OFF");
  digitalWrite(LED_BUILTIN, LOW);
   digitalWrite(RELAY_PIN, LOW);
}

