  // Date and time functions using RX8025 RTC connected via I2C and Wire lib
  
  #include <Wire.h>
  #include "Sodaq_DS3231.h"
  
  char weekDay[][4] = {"Sun", "Mon", "Tue", "Wed", "Thu", "Fri", "Sat" };
  
  void setup () 
  {
  Serial.begin(57600);
  Wire.begin();
  rtc.begin();
  }
  
  uint32_t old_ts;
  
  void loop () 
  {
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
  if(now.hour()==0&&now.minute()==12)
  {
  Serial.println("Its time to blow up something");
  Serial.println("Opening Curtain");
  }
  
  //Close curtain its evening. Rotate motor anticlockwise
  //Set time in the command below
  if(now.hour()==0&&now.minute()==15){
  Serial.println("Its time to blow up something");
  Serial.println("Closing Curtain");
  }
  }
  delay(1000);
  }
