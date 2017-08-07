#include<software serial.h>// import the serial library//
software serial Genotronex(2,3;)// rx,tx)
int led pin=13// led on pin 13
int bluetooth Data;//the data given from computer 



void setup (){
  
  // put your main code here, to run repeatedly:
Genotronex.begin (9600)
Genotronex.printin ("bluetooth on press 1 or 0 blink led")
pinmode (led pin output);
}
void loop()
//put your main code here to run repeatedly//
if (Genotronex.available()){
  bluetooth Data=Genotronex.read();
  if (bluetooth Data=="1")// if 1 is pressed //
  digital write (led pin 1)
  genotronex.print in("led on d13 on ")
  if (bluetooth data==0//if number 0 is pressed;
  digital write (led pin 0;)
  Genoronex .print in("led on d13 off")  
}
  delay (100);//prepare for next data//
  char junk;
  string input ="";
  void setup() 

{
while(serial);
serial.begin(9600);
}
void loop()
if (serial.available())
 
{
  char in char=(char)serial.read ()//readthe input //
  inputstring+=inchar;//make a string of the characters//
}
serial.print in (inputstring);
while (serial.available()>0)
{
  junk=serial.read();
}
input strings=""
}
}
}

