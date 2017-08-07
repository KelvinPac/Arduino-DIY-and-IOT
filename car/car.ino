//*** 1- Documentation
//This program is used to control a robot car using Bluetooth RC Controller Andriod app that communicates with Arduino through a bluetooth module

#include <AFMotor.h>

//creates two objects to control the terminal 1 and 2 of motor shield 
AF_DCMotor motor1(3); 
AF_DCMotor motor2(4); 

char command; 

void setup() 
{       
  Serial.begin(9600);  //Set the baud rate to your Bluetooth module.
  pinMode(5, OUTPUT);
  pinMode(3, OUTPUT);
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
    }
  } 
}

void forward()
{
  motor1.setSpeed(100); //Define maximum velocity
  motor2.setSpeed(100); //Define maximum velocity
  motor2.run(FORWARD); //rotate the motor clockwise
  motor1.run(FORWARD); //rotate the motor clockwise
  digitalWrite(5, HIGH);   // turn the LED on (HIGH is the voltage level)
  digitalWrite(3, LOW);   // turn the LED off (LOW is the voltage level)
  
}

void back()
{
  motor1.setSpeed(100); 
  motor2.setSpeed(100); 
  motor1.run(BACKWARD); //rotate the motor counterclockwise
  motor2.run(BACKWARD); //rotate the motor counterclockwise
  digitalWrite(5, LOW);   // turn the LED off (LOW is the voltage level)
  digitalWrite(3, HIGH);   // turn the LED on (HIGH is the voltage level)
}

void left()
{
  motor1.setSpeed(100); //Define maximum velocity
  motor1.run(FORWARD); //rotate the motor clockwise
  motor2.setSpeed(0);
  motor2.run(RELEASE); //turn motor2 off
}

void right()
{
  motor1.setSpeed(0);
  motor2.setSpeed(100); //Define maximum velocity
  motor1.run(RELEASE); //turn motor1 off
  motor2.run(FORWARD); //rotate the motor clockwise
}

void Stop()
{
  motor1.setSpeed(0);
   motor2.setSpeed(0);
  motor2.run(RELEASE); //turn motor1 off
  motor2.run(RELEASE); //turn motor2 off
}



