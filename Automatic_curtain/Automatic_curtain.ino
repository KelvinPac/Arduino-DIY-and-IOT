      /*
      * http://hardwarefun.com/tutorials/creating-robots-using-arduino-h-bridge
      * 
      */
      
      #define E1 10  // Enable Pin for motor 1
      #define I1 8  // Control pin 1 for motor 1
      #define I2 9  // Control pin 2 for motor 1
      
      #include <Wire.h>
      #include "Sodaq_DS3231.h"
      
      char weekDay[][4] = {"Sun", "Mon", "Tue", "Wed", "Thu", "Fri", "Sat" };
      
      void setup() {
      
      Serial.begin(57600);
      Wire.begin();
      rtc.begin();
      
      pinMode(E1, OUTPUT);
      pinMode(I1, OUTPUT);
      pinMode(I2, OUTPUT);
      
      }
      
      uint32_t old_ts;
      
      void loop() {
      
      digitalWrite(E1, LOW);
      DateTime now = rtc.now(); //get the current date-time
      uint32_t ts = now.getEpoch();
      
      if (old_ts == 0 || old_ts != ts) {
      old_ts = ts;


      Serial.print(now.year(), DEC);
  Serial.print('/');
  Serial.print(now.month(), DEC);
  Serial.print('/');
  Serial.print(now.date(), DEC);
  Serial.print(' ');
  Serial.print(now.hour(), DEC);
  Serial.print(':');
  Serial.print(now.minute(), DEC);
  Serial.print(':');
  Serial.print(now.second(), DEC);
  Serial.print(' ');
  Serial.print(weekDay[now.dayOfWeek()]);
  Serial.println();
      
      //Open Curtain in the morning .Rotate motor clockwise
      //Set time in the command below
      if(now.hour()==0&&now.minute()==37)
      {
      Serial.println("Its time to blow up something");
      Serial.println("Opening Curtain");
      
      //digitalWrite(E1, HIGH);
      // set speed to 200 out
      analogWrite(E1, 90);
      digitalWrite(I1, HIGH);
      digitalWrite(I2, LOW);
      }
      
      //Close curtain its evening. Rotate motor anticlockwise
      //Set time in the command below
      if(now.hour()==0&&now.minute()==39)
      {
      Serial.println("Its time to blow up something");
      Serial.println("Closing Curtain");
      // set speed to 200 out
      analogWrite(E1, 90);
      //digitalWrite(E1, HIGH);
      digitalWrite(I1, LOW);
      digitalWrite(I2, HIGH);
      }
      }
      delay(1000);
      }
