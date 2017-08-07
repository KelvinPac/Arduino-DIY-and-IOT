// ---------------------------------------------------------------------------
// Example NewPing library sketch that does a ping about 20 times per second.
// ---------------------------------------------------------------------------

//Sketch is designed for a 30cm cylinder.
//Place sensor 10cm above the cylinder opening

int TANK_FULL = 7;
int TANK_HALF = 6;
int TANK_EMPTY = 5;
#include <NewPing.h>

#define TRIGGER_PIN  12  // Arduino pin tied to trigger pin on the ultrasonic sensor.
#define ECHO_PIN     11  // Arduino pin tied to echo pin on the ultrasonic sensor.
#define MAX_DISTANCE 50 // Maximum distance we want to ping for (in centimeters). Maximum sensor distance is rated at 400-500cm.

NewPing sonar(TRIGGER_PIN, ECHO_PIN, MAX_DISTANCE); // NewPing setup of pins and maximum distance.

void setup() {
  Serial.begin(115200); // Open serial monitor at 115200 baud to see ping results.
  pinMode(TANK_FULL, OUTPUT);
  pinMode(TANK_HALF, OUTPUT);
  pinMode(TANK_EMPTY, OUTPUT);
}

void loop() {
  delay(1000);                     // Wait 50ms between pings (about 20 pings/sec). 29ms should be the shortest delay between pings.

  unsigned int uS = sonar.ping_cm();
  Serial.print(uS); // Send ping, get distance in cm and print result (0 = outside set distance range)
  Serial.println(" cm");
  if(uS<=20){
    //Tank is full
    digitalWrite(TANK_FULL, HIGH);   // turn the LED on (HIGH is the voltage level)
    digitalWrite(TANK_HALF, LOW);    // turn the LED off by making the voltage LOW
    digitalWrite(TANK_EMPTY, LOW);    // turn the LED off by making the voltage LOW
    
  }else if(uS<=30){
    //Tank is half
    digitalWrite(TANK_FULL, LOW);   // turn the LED on (HIGH is the voltage level)
    digitalWrite(TANK_HALF, HIGH);    // turn the LED off by making the voltage LOW
    digitalWrite(TANK_EMPTY, LOW);    // turn the LED off by making the voltage LOW
    
  }else if(uS<=40){
    digitalWrite(TANK_FULL, LOW);   // turn the LED on (HIGH is the voltage level)
    digitalWrite(TANK_HALF, LOW);    // turn the LED off by making the voltage LOW
    digitalWrite(TANK_EMPTY, HIGH);    // turn the LED off by making the voltage LOW
    
  }

  
}
