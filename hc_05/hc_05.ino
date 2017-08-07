#include<software serial.h>// import the serial library//
software serial Genotronex(2,3;)// rx,tx)
int led pin=13// led on pin 13
int bluetooth Data;//the data given from computer 


void setup (){
  
  // put your main code here, to run repeatedly:
Genotronex.begin (9600)
Genotronex.printin ("bluetooth on press 1 or 0 blink led")
pinmode (led pin output);

char junk;
String inputString="";

void setup()                    // run once, when the sketch starts
{
 Serial.begin(9600);            // set the baud rate to 9600, same should be of your Serial Monitor
 pinMode(13, OUTPUT);
}

void loop()
{
  if(Serial.available()){
  while(Serial.available())
    {
      char inChar = (char)Serial.read(); //read the input
      inputString += inChar;        //make a string of the characters coming on serial
    }
    Serial.println(inputString);
    while (Serial.available() > 0)  
    { junk = Serial.read() ; }      // clear the serial buffer
    if(inputString == "a"){         //in case of 'a' turn the LED on
      digitalWrite(13, HIGH);  
    }else if(inputString == "b"){   //incase of 'b' turn the LED off
      digitalWrite(13, LOW);
    }
    inputString = "";
  }
}
