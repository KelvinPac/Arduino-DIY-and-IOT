  #define E1 10  // Enable Pin for motor 1
  #define I1 8  // Control pin 1 for motor 1
  #define I2 9  // Control pin 2 for motor 1
  
  boolean ifWasOut=false;
  boolean runOnce=false;
  boolean clothesAreOut=true;
  
  
  void setup(){
  Serial.begin(9600);
  pinMode(2, OUTPUT);
  pinMode(E1, OUTPUT);
  pinMode(I1, OUTPUT);
  pinMode(I2, OUTPUT);
  pinMode(13, OUTPUT);
  }
  
  
  void loop(){
  digitalWrite(E1, LOW);
  // read the input on analog pin 0:
  int sensorValue = analogRead(A0);
  digitalWrite(13, LOW);
  
  if(sensorValue<500&&clothesAreOut==true){
  clothesIn();
  }
  else if(sensorValue>500&&ifWasOut){
   clothesAreOut=true;
  ifWasOut=false;
  digitalWrite(13, LOW);
  analogWrite(E1, 50);
  digitalWrite(I1, HIGH);
  digitalWrite(I2, LOW);
  delay(3.000);
  }
  delay(3000);
  }
  
  //Its raining
  void clothesIn(){
 clothesAreOut=false;
  ifWasOut=true;
  Serial.println("Heavy Rain");
  //digitalWrite(E1, HIGH);
  analogWrite(E1, 50);
  digitalWrite(I1, LOW);
  digitalWrite(I2, HIGH);
  digitalWrite(13, HIGH);   // turn the LED on (HIGH is the voltage level)
  }
  
  //No more rain
  void clothesOut(){
   
  }

