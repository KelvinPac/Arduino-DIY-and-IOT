// connect motor controller pins to Arduino digital pins

// note that maximum speed is determined by the motor itself and the operating voltage
 // the PWM values sent by analogWrite() are fractions of the maximum speed possible by your hardware

// motor one or left motor
int enA = 11;
int in1 = 12;
int in2 = 10;


// motor two or right motor
int enB = 3;
int in3 = 2;
int in4 = 4;


char command; 
int speed;
int turn_speed =40;

void setup() {
    Serial.begin(9600);  //Set the baud rate to your Bluetooth module.
    pinMode(5, OUTPUT); //Front lights
    pinMode(3, OUTPUT);  //Back lights
    // set all the motor control pins to outputs
    pinMode(enA, OUTPUT);
    pinMode(in1, OUTPUT);
    pinMode(in2, OUTPUT);

    // set all the motor control pins to outputs
    pinMode(enB, OUTPUT);
    pinMode(in3, OUTPUT);
    pinMode(in4, OUTPUT);

}

void loop() {
      // put your main code here, to run repeatedly:
      if(Serial.available() > 0){ 
      command = Serial.read(); 
      Stop(); //initialize with motors stoped
      //Change pin mode only if new command is different from previous.   
      //Serial.println(command);
      switch(command){
      case 'F':  
      forward();
      break;
      case 'B':  
      back();
      break;
      case 'L':
      left();
      break;
      case 'R':
      right();
      break;
      case '0':  
      speed=0; //no speed
      break;
      case '1':  
      speed =10;//speed 25
      break;
      case '2':  
      speed=20;//speed 50
      break;
      case '3':
      speed=30; //speed 75
      break;
      case '4':  
      speed=40; //speed 100
      break;
      case '5':  
      speed=50;//speed 125
      break;
      case '6':
      speed=60; //speed 150
      break;
      case '7':  
      speed =70; //speed 175
      break;
      case '8':  
      speed=80;  //speed 200
      break;
      case '9':
      speed=90; //speed 225
      break;
      case 'q':
      speed=100;//speed 255
      break;
      
      }
} 

}

void forward()
{

    // set speed to 200 out of possible range 0~255
     analogWrite(enA,speed);
     analogWrite(enB,speed);
    // this function will run the motors in both directions at a fixed speed
     // turn on motor A
     digitalWrite(in1, HIGH);
     digitalWrite(in2, LOW);
     digitalWrite(in3, HIGH);
     digitalWrite(in4, LOW);
 
}

void back()
{
    // set speed to 200 out of possible range 0~255
     analogWrite(enA, speed);
     analogWrite(enB, speed);
    // now change motor directions
     digitalWrite(in1, LOW);
     digitalWrite(in2, HIGH); 
     digitalWrite(in3, LOW);
     digitalWrite(in4, HIGH); 
 
 
}

void left()
{
    //rotate left motor forward and
    analogWrite(enA,turn_speed);
    digitalWrite(in1, HIGH);
    digitalWrite(in2, LOW);
    // rotate right motor  backwards
     analogWrite(enB, turn_speed);
     digitalWrite(in3, LOW);
     digitalWrite(in4, HIGH); 
  
}

void right()
{
  //rotate right motor forward and
  analogWrite(enB,turn_speed);
  digitalWrite(in3, HIGH);
     digitalWrite(in4, LOW);
  // rotate left motor  backwards
  analogWrite(enA,turn_speed);
  digitalWrite(in1, LOW);
     digitalWrite(in2, HIGH);
  
}

void Stop()
{
    // now turn off motors
     digitalWrite(in1, LOW);
     digitalWrite(in2, LOW); 
     digitalWrite(in3, LOW);
     digitalWrite(in4, LOW);
}

