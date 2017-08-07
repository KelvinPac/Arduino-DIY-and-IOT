  
  #include <Servo.h>
  
  int servoPin = 9;
   Servo servo;  
   
  int angle = 0;   // servo position in degrees 
  
  void setup() {
           Serial.begin(9600);
           servo.attach(servoPin); 
  }

  void loop() {
            //if some date is sent, reads it and saves in state
            if(Serial.available() > 0){     
              angle = Serial.read();   
              Serial.println(angle);
            }  
        
            if(angle=='1'){
              servo.write(0);
            }
        
            else if(angle=='0'){
            servo.write(90);
             }

  }
