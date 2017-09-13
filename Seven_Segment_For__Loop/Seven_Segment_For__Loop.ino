//Library
#include "SevenSeg.h"

//Defines the segments A-G: SevenSeg(A, B, C, D, E, F, G);
//SevenSeg disp (10,9,8,7,6,11,12);
SevenSeg disp (7,6,10,3,9,4,2);
//Number of 7 segments
const int numOfDigits =2;
//CC(or CA) pins of segment
int digitPins [numOfDigits]={8};

//Variables
int number=0; //Default number
int flag;

void setup() {
  // put your setup code here, to run once:
 Serial.begin(9600);
  //Defines the number of digits to be "numOfDigits" and the digit pins to be the elements of the array "digitPins"
  disp.setDigitPins ( numOfDigits , digitPins );
  //Only for common cathode 7segments
  disp.setCommonCathode();
  //Control brightness (values 0-100);
  disp.setDutyCycle(50);
   ///disp.writeDigit(1);
}

void loop() {
  // put your main code here, to run repeatedly:
  int a;
  int b;
  Serial.println();
    Serial.println();
  for(a=1; a<=9; a=a+1){
    delay(2000);
    Serial.println(a);
    disp.writeDigit(a);
  }
  delay(10000);

    Serial.println();
    Serial.println();
    
  for(b=9; b>=1; b=b-1){
    delay(2000);
    Serial.println(b);
    disp.writeDigit(b);
  }
  delay(10000);
}
