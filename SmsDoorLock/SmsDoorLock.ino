char* particulars[3];
String data_str;
char sms_rx[122]; //Received text SMS
boolean data_received = false;//
int light_1 = 13;
int light_2 =12;
int light_3 =11;
char buffer[50];
char number[13];
void setup()
{
  
   Serial.begin(115200);
  pinMode(light_1, OUTPUT); 
  pinMode(light_2, OUTPUT); 
  pinMode(light_3, OUTPUT);  
 delay(30000);  //delay 1 minute for GSM to power up and accept commands  

 Serial.println("ATE0\r");
 delay(100);
 Serial.println("AT+CMGF=1\r");
 delay(100);
 Serial.println("AT+CNMI=2,2\r");
 delay(100);
// Serial.println("AT+CNMI=3\r");

}
int index = 0;


void loop()
{
   //Serial.println("ATE0\r");
 while(Serial.available()>0)
  {
    
    sms_rx[index] = Serial.read();
    index++;
    data_received = true;
  }
  sms_rx[index] = '\0';
  
   
  if(data_received)
  {
    data_received = false;
     String Token = strstr(sms_rx,"+2");
    String number = (Token.substring(0,13));
   
   if (strcasestr_P( sms_rx, PSTR("light1on")) != 0)
  {
    digitalWrite(light_1, HIGH);
  }
   else if (strcasestr_P( sms_rx, PSTR("light1off")) != 0)
  {
    digitalWrite(light_1,LOW);
  }

  
   else if (strcasestr_P( sms_rx, PSTR("open")) != 0)
  {
    digitalWrite(light_2,HIGH);
  }
   else if (strcasestr_P( sms_rx, PSTR("close")) != 0)
  {
   digitalWrite(light_2, LOW);
  }

  
  else if (strcasestr_P( sms_rx, PSTR("light3on")) != 0)
  {
   digitalWrite(light_3, HIGH);
  }
    else if (strcasestr_P( sms_rx, PSTR("light3off")) != 0)
  {
   digitalWrite(light_3, LOW);
  }
  

  
  delay(1000);
 
    for(int j = 0;j<=sizeof(sms_rx);j++)
    {
      sms_rx[j] = '\0';
    }
    index =0;
  }
 
}
void ping_GSM()
{
   Serial.println("ATE0\r");
   delay(500);
  for(int k= 0;k<10;k++){
    Serial.println("AT\r");
    delay(200);
  }
}


