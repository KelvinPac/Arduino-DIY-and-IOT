  // ---------------------------------------------------------------------------
  // NewPing with 2 HC-SR04 utrasonic sensors , L298N motor driver with 1 motor
  // and Arduino UNO for conveyer belt applications
  // ---------------------------------------------------------------------------
  
  #include <NewPing.h>
  
  //sonar1
  #define TRIGGER_PIN1  10 //12  // Arduino pin tied to trigger pin on the ultrasonic sensor.
  #define ECHO_PIN1    9  // 11 // Arduino pin tied to echo pin on the ultrasonic sensor
  
  //sonar2
  #define TRIGGER_PIN2  12  // Arduino pin tied to trigger pin on the ultrasonic sensor.
  #define ECHO_PIN2     11 // Arduino pin tied to echo pin on the ultrasonic sensor.
  
  #define MAX_DISTANCE 50 // Maximum distance we want to ping for (in centimeters). Maximum sensor distance is rated at 400-500cm.
  
  NewPing sonar1(TRIGGER_PIN1, ECHO_PIN1, MAX_DISTANCE); // NewPing setup of pins and maximum distance.
  NewPing sonar2(TRIGGER_PIN2, ECHO_PIN2, MAX_DISTANCE); // NewPing setup of pins and maximum distance.

  //The motor won't move if speed is too low
  int speed = 150; //  Motor speed. (PWM) maximum value is 255, Minimum is 40-50 but varies depending on power factor;
  
  int objectDistance = 10; // Adjust accordingly (in centimeters). Maximum should be less than @MAX_DISTANCE.

  int ledPin = 5;
  // motor 
  int enB = 3;
  int in3 = 2;
  int in4 = 4;

  void setup() {
      Serial.begin(115200); // Open serial monitor at 115200 baud to see ping results.
       // initialize pins as an output.
      pinMode(ledPin, OUTPUT);
      // set all the motor control pins to outputs
    pinMode(enB, OUTPUT);
    pinMode(in3, OUTPUT);
    pinMode(in4, OUTPUT);
  }

  void loop() {
      delay(250); //Adjust accordingly. Wait 250ms between pings (about 20 pings/sec). 29ms should be the shortest delay between pings.
      //When object is detected at sonar1.Turn on motor clockwise until sonar2 detects the object.
      //Simulating an ON  OFF operation.
      //Object detection is initiated when object is in a certain distance from the sensor, ie.. int objectDistance = 30;
      
      
      int sonar1ObjectDistance = sonar1.ping_cm();  Serial.print("sonar1 =  "); Serial.println(sonar1ObjectDistance);    //sonar 1 object detection
      int sonar2ObjectDistance = sonar2.ping_cm();  Serial.print("sonar2 = "); Serial.println(sonar2ObjectDistance);    //sonar 2 object detection
      
      //sonar1 logic.
      if(sonar1ObjectDistance<=objectDistance && !sonar1ObjectDistance==0)
      {
        Serial.println("Starting Motors");
        startMotor();    //Object detected by sonar1. Start Motor.
      }
      
      //sonar2 logic.
      if(sonar2ObjectDistance<=objectDistance && !sonar2ObjectDistance==0)
      {
         Serial.println("Stoping Motors");
        stopMotor();      //Object detected by sonar2. Stop Motor.
      }
        
  }

  void startMotor(){
      digitalWrite(ledPin, HIGH);
      analogWrite(enB,speed);
      digitalWrite(in3, HIGH);
      digitalWrite(in4, LOW);
  }
  
  void stopMotor(){
      digitalWrite(ledPin, LOW);
     digitalWrite(enB,LOW);
      digitalWrite(in3, LOW);
     digitalWrite(in4, LOW);
  }


