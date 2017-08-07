int relay= 7;
int led = 13; // the pin that the LED is atteched to
int sensor = 2; // the pin that the sensor is atteched to
int state = LOW; // by default, no motion detected
int val = 0; // variable to store the sensor status (value)


void setup() {
  // put your setup code here, to run once:
pinMode(led, OUTPUT); // initalize LED as an output
pinMode(sensor, INPUT); // initialize sensor as an input
pinMode(relay, OUTPUT);
digitalWrite(relay,HIGH);
Serial.begin(9600); // initialize serial
}

void loop() {
  // put your main code here, to run repeatedly:
  val = digitalRead(sensor);
  digitalWrite(led,val);
  
  if(val==1)
  {
    digitalWrite(relay,HIGH);
    Serial.println("HIGH!");
    delay(1000);
  }
  digitalWrite(relay,LOW);

}
