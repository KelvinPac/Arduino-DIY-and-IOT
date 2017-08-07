//*** 1- Documentation
//This program is used to control a robot car using Bluetooth RC Controller Andriod app that communicates with Arduino through a bluetooth module

#include <AFMotor.h>

//creates two objects to control the terminal 1 and 2 of motor shield 
AF_DCMotor motor1(3); 
AF_DCMotor motor2(1); 

char command; 
int speed;

void setup() 
{       
  Serial.begin(9600);  //Set the baud rate to your Bluetooth module.
  pinMode(5, OUTPUT); //Front lights
  pinMode(3, OUTPUT);  //Back lights
}

void loop(){
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
      speed =25;//speed 25
      break;
    case '2':  
      speed=50;//speed 50
      break;
    case '3':
     speed=75; //speed 75
      break;
      case '4':  
      speed=100; //speed 100
      break;
    case '5':  
      speed=125;//speed 125
      break;
    case '6':
     speed=150; //speed 150
      break;
      case '7':  
      speed =175; //speed 175
      break;
    case '8':  
    speed=200;  //speed 200
      break;
    case '9':
     speed=225; //speed 225
      break;
      case 'q':
      speed=255;//speed 255
      break;
      case 'W':
      //front lights on
      digitalWrite(5, HIGH);   // turn the LED on (HIGH is the voltage level)
      break;
      case 'w':
      //front lights off
      digitalWrite(5, LOW);   // turn the LED on (HIGH is the voltage level)
      break;

      case 'U':
      //back lights on
      digitalWrite(3, HIGH);   // turn the LED off (LOW is the voltage level)
      break;
      case 'u':
      //back lights off
      digitalWrite(3, LOW);   // turn the LED off (LOW is the voltage level)
     
      break;
    }
  } 
}

void forward()
{
  motor2.run(FORWARD); //rotate the motor clockwise
  motor1.run(FORWARD); //rotate the motor clockwise
  motor1.setSpeed(speed); //Define maximum velocity
  motor2.setSpeed(speed); //Define maximum velocity
  
  
}

void back()
{
  motor1.run(BACKWARD); //rotate the motor counterclockwise
  motor2.run(BACKWARD); //rotate the motor counterclockwise
  motor1.setSpeed(speed); 
  motor2.setSpeed(speed); 
}

void left()
{
  motor2.run(RELEASE); //turn motor2 off
  motor1.run(FORWARD); //rotate the motor clockwise
  motor1.setSpeed(speed); //Define maximum velocity
  
  motor2.setSpeed(0);
  
}

void right()
{
  motor1.run(RELEASE); //turn motor1 off
  motor2.run(FORWARD); //rotate the motor clockwise
  motor1.setSpeed(0);
  motor2.setSpeed(speed); //Define maximum velocity
  
}

void Stop()
{
  motor2.run(RELEASE); //turn motor1 off
  motor2.run(RELEASE); //turn motor2 off
  motor1.setSpeed(0);
   motor2.setSpeed(0);
  
}



