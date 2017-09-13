 int pd=2; 
 int pd3=3; 
  int pd4=4;

  int led1 =  12;
  int led2 =  11;
  int led3 =  10;
  int led4 =  9;
  int led5 =  8;
  
 int senRead=A0;  
 int senRead2=A1; 
  int senRead3=A2;

void setup() {
  // put your setup code here, to run once:
   pinMode(pd,OUTPUT);
   digitalWrite(pd,HIGH);
   pinMode(pd3,OUTPUT);
   digitalWrite(pd3,HIGH);
   pinMode(pd4,OUTPUT);
    pinMode(led1,OUTPUT);
    pinMode(led2,OUTPUT);
    pinMode(led3,OUTPUT);
    pinMode(led4,OUTPUT);
    pinMode(led5,OUTPUT);
   digitalWrite(pd4,HIGH);
    Serial.begin(9600); 

}

void loop() {
//  digitalWrite(led1,HIGH);
// digitalWrite(led2,HIGH);
//  digitalWrite(led3,HIGH);
//  digitalWrite(led4,HIGH);
//  digitalWrite(led5,HIGH);
  // put your main code here, to run repeatedly:
  int val=analogRead(senRead);
  Serial.print(val); Serial.println(" sensor 1");
   int val2=analogRead(senRead2);
  Serial.print(val2); Serial.println(" sensor 2");

   int val3=analogRead(senRead3);
  Serial.print(val3); Serial.println(" sensor 3");

  if(val>300 && val<500){
  digitalWrite(led1,HIGH);
 digitalWrite(led2,HIGH);
  digitalWrite(led3,HIGH);
  digitalWrite(led4,LOW);
  digitalWrite(led5,LOW);
  }

  if(val2>300 && val<500){
    digitalWrite(led1,LOW);
 digitalWrite(led2,HIGH);
  digitalWrite(led3,HIGH);
  digitalWrite(led4,HIGH);
  digitalWrite(led5,LOW);
    
  }


  if(val3>300 && val<500){
    digitalWrite(led1,LOW);
 digitalWrite(led2,LOW);
  digitalWrite(led3,HIGH);
  digitalWrite(led4,HIGH);
  digitalWrite(led5,HIGH);
  }
  Serial.println();
  Serial.println();
  delay(50);

}
