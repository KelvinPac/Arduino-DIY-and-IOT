/* Arduino Tutorial - 7 Segment 
   One 7 segment is one digit, from 0 to  9.
   Dev: Vasilakis Michalis // Date: 25/7/2015 // www.ardumotive.com */
#include <Servo.h>
Servo myservo;  // create servo object to control a servo
int servo = A0;

//Library
#include "SevenSeg.h"
#include <NewPing.h>

//Defines the segments A-G: SevenSeg(A, B, C, D, E, F, G);
SevenSeg disp (10,9,8,7,6,11,12);
//Number of 7 segments
const int numOfDigits =1;
//CC(or CA) pins of segment
int digitPins [numOfDigits]={4};

//Variables
int number=0; //Default number
int flag;
int cars =0;

#define TRIGGER_PIN 2
#define ECHO_PIN 3

#define TRIGGER_PIN_2 13
#define ECHO_PIN_2 5

#define MAX_DISTANCE 20


NewPing sonar(TRIGGER_PIN, ECHO_PIN, MAX_DISTANCE);
NewPing sonar2(TRIGGER_PIN_2, ECHO_PIN_2, MAX_DISTANCE);

void setup() {
  
  Serial.begin(9600);
  //Defines the number of digits to be "numOfDigits" and the digit pins to be the elements of the array "digitPins"
  disp.setDigitPins ( numOfDigits , digitPins );
  //Only for common cathode 7segments
  disp.setCommonCathode();
  //Control brightness (values 0-100);
  disp.setDutyCycle(50);
  //disp.writeDigit(4);
    myservo.attach(servo);  // attaches the servo on pin 9 to the servo object
    myservo.write(180);
}

void loop(){
  delay(500);
   Serial.print(cars);Serial.println(" cars in the parking");
  //delay(500);
   unsigned int uS = sonar.ping_cm();
   unsigned int uS2 = sonar2.ping_cm();
   Serial.print(uS); Serial.println(" sensor 1");
   Serial.print(uS2); Serial.println(" sensor 2");

if(cars<=7 ){
  //check if something is detected between the range of 10 and 20cm
 //car entering detected
   if(uS<=20  && uS>=10){
    //update car  variable;
    if(cars !=7){
        cars =  cars+1;
    }
  
   //display car variable in 7 segment display
   disp.writeDigit(cars);
    //open gate then close again
   if(cars <7 || cars==7){
        myservo.write(5);
    }
    //delay(150);
  
   
  Serial.print(cars);Serial.println(" cars in the parking");
    //delay 5 seconds
    delay(3000);
     if(cars <7 || cars==7){
        myservo.write(180);
    }
   }


if(cars !=0){
  //sensor 2
   //check if something is detected between the range of 10 and 20cm
 //car entering detected
   if(uS2<=20  && uS2>=10){
    //update car  variable;
    cars =  cars-1;
   //display car variable in 7 segment display
   disp.writeDigit(cars);
    myservo.write(5);
  Serial.print(cars);Serial.println(" cars in the parking");
    //delay 5 seconds
    delay(3000);
     myservo.write(180);
   }
}

} 

}

//void loop()
//{ 
//  //Check if incoming data is available:
//    if (Serial.available() > 0)
//    {
//      // If it is, we'll use parseInt() to pull out only numbers:
//      number = Serial.parseInt();
//      flag=0;
//    }
//
//  //Valid range is from 1 to 9
//  if (number>=1 && number<=9){
//    //Print number to 7 segment display
//    disp.writeDigit(6);
//    
//      //Print message to serial monito only once
//      if (flag==0){ 
//        //Print number to serial monitor
//        Serial.print("Number on 7 segment display:");
//        Serial.println(number);
//        flag=1;
//      }
//  }
//}

