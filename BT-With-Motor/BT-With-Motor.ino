// connect motor controller pins to Arduino digital pins

// note that maximum speed is determined by the motor itself and the operating voltage
 // the PWM values sent by analogWrite() are fractions of the maximum speed possible by your hardware

// motor one
int enA = 10;
int in1 = 9;
int in2 = 8;


char command; 
int speed;

void setup() {
Serial.begin(9600);  //Set the baud rate to your Bluetooth module.
pinMode(5, OUTPUT); //Front lights
pinMode(3, OUTPUT);  //Back lights
// set all the motor control pins to outputs
pinMode(enA, OUTPUT);
pinMode(in1, OUTPUT);
pinMode(in2, OUTPUT);

}

void loop() {
// put your main code here, to run repeatedly:
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

}
} 

}

void forward()
{

// set speed to 200 out of possible range 0~255
 analogWrite(enA,speed);
// this function will run the motors in both directions at a fixed speed
 // turn on motor A
 digitalWrite(in1, HIGH);
 digitalWrite(in2, LOW);
 
}

void back()
{
// set speed to 200 out of possible range 0~255
 analogWrite(enA, speed);
// now change motor directions
 digitalWrite(in1, LOW);
 digitalWrite(in2, HIGH); 
 
}

void Stop()
{
// now turn off motors
 digitalWrite(in1, LOW);
 digitalWrite(in2, LOW); 
}

