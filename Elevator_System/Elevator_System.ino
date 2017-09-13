  #include <EEPROM.h>
  
  /*
  The circuit: LCD
  * LCD RS pin to digital pin 12
  * LCD Enable pin to digital pin 11
  * LCD D4 pin to digital pin 5
  * LCD D5 pin to digital pin 4
  * LCD D6 pin to digital pin 3
  * LCD D7 pin to digital pin 2
  * LCD R/W pin to ground
  * LCD VSS pin to ground
  * LCD VCC pin to 5V
  * 10K resistor:
  * ends to +5V and ground
  * wiper to LCD VO pin (pin 3)
  */
  
  // include the library code:
  #include <LiquidCrystal.h>
  #include <Stepper.h>
  
  // initialize the library with the numbers of the interface pins
  LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
  
  #include <AccelStepper.h>
  #define HALFSTEP 8
  
  // Motor pin definitions
  #define motorPin1  6     // IN1 on the ULN2003 driver 1
  #define motorPin2  7     // IN2 on the ULN2003 driver 1
  #define motorPin3  8     // IN3 on the ULN2003 driver 1
  #define motorPin4  9     // IN4 on the ULN2003 driver 1
  
  const int buttonPin1 = A0;     // the number of the pushbutton pin
  const int buttonPin2= A1;     // the number of the pushbutton pin
  const int buttonPin3 = A2;     // the number of the pushbutton pin
  const int buttonPin4 = A3;     // the number of the pushbutton pin
  
  // variables will change:
  int buttonState1 = 0;         // variable for reading the pushbutton status
  int buttonState2 = 0;         // variable for reading the pushbutton status
  int buttonState3 = 0;         // variable for reading the pushbutton status
  int buttonState4 = 0;         // variable for reading the pushbutton status
  
  int elevatorFloor;                // variable to hold the floor the elevator is
  int elevatorFloor2;                // variable to hold the floor the elevator is
  
  int stateR=0;
  
  // Initialize with pin sequence IN1-IN3-IN2-IN4 for using the AccelStepper with 28BYJ-48
  AccelStepper stepper1(HALFSTEP, motorPin1, motorPin3, motorPin2, motorPin4);
  
  void setup() {
      Serial.begin(9600);
      // set up the LCD's number of columns and rows:
      lcd.begin(16, 2);
      // Print a message to the LCD.
      lcd.print("Elevator System.");
      lcd.setCursor(0,1);
      lcd.print("Loading...");
      blinkLcd();
      stateR=1;
      //check stored LED state on EEPROM using function defined at the end of the code
      checkelevatorFloor2(); 
  
  }
  
  void loop() {
      stateR=2;
      // set the cursor to column 0, line 1
      // (note: line 1 is the second row, since counting begins with 0):
      lcd.setCursor(0, 1);
      // print the number of seconds since reset:
      //lcd.print(millis() / 1000);
      
      // read the state of the pushbutton value:
      buttonState1 = digitalRead(buttonPin1);
      buttonState2 = digitalRead(buttonPin2);
      buttonState3 = digitalRead(buttonPin3);
      buttonState4 = digitalRead(buttonPin4);
      // check if the pushbutton is pressed.
      // if it is, the buttonState is HIGH:
      if (buttonState1 == HIGH) {
        delay(500);
        /*start rotating the stepper motor
        *check the room the is in
        */
        elevatorFloor2 = EEPROM.read(0);
        /*
        * params -> buttonPressed, current elevator floor
        */
        
        
        lcd.clear();
        lcd.print("Thank You! Going");
        lcd.setCursor(0, 1);
        lcd.print("to the 1st Floor");
        rotateStepper(1,elevatorFloor);
        // save the current LED state in the EEPROM
        EEPROM.update(0, 1);
        delay(150);
        checkelevatorFloor2(); 
      }
      if (buttonState2 == HIGH) {
        delay(500);
        
        elevatorFloor2 = EEPROM.read(0);
        
        lcd.clear();
        lcd.print("Thank You! Going");
        lcd.setCursor(0, 1);
        lcd.print("to the 2nd Floor");
        rotateStepper(2,elevatorFloor);
        // save the current LED state in the EEPROM
        EEPROM.update(0, 2);
        delay(150);
        checkelevatorFloor2(); 
      }
      if (buttonState3 == HIGH) {
        delay(500);
        
        elevatorFloor2 = EEPROM.read(0);
        lcd.clear();
        lcd.print("Thank You! Going");
        lcd.setCursor(0, 1);
        lcd.print("to the 3rd Floor");
        rotateStepper(3,elevatorFloor);
        // save the current LED state in the EEPROM
        EEPROM.update(0, 3);
        delay(150);
        checkelevatorFloor2(); 
      }
      if (buttonState4 == HIGH) {
        delay(500);
        
        elevatorFloor2 = EEPROM.read(0);
        //rotateStepper(4,elevatorFloor);
        
        lcd.clear();
        lcd.print("Thank You! Going");
        lcd.setCursor(0, 1);
        lcd.print("to the 4th Floor");
        rotateStepper(4,elevatorFloor);
        // save the current LED state in the EEPROM
        EEPROM.update(0, 4);
        delay(150);
        checkelevatorFloor2(); 
      }
      delay(100);
      
      stateR=2;
  }
  
  // Prints and upates the LED state
  // when the Arduino board restarts or powers up
  void checkelevatorFloor() {
      Serial.println("Elevator status after restart: ");
      elevatorFloor = EEPROM.read(0);
      
      if(elevatorFloor == 1) {
      Serial.println ("Your in the 1st floor");
      } 
      if(elevatorFloor == 2) {
      Serial.println ("Your in the 2nd floor");
      
      }
      if(elevatorFloor == 3) {
      Serial.println ("Your in the 3rd floor");
      
      }
      if(elevatorFloor == 4) {
      Serial.println ("Your in the 4th floor");
      
      }
  }
  
  // Prints and upates the LED state
  // when the Arduino board restarts or powers up
  void checkelevatorFloor2() {
      //Serial.println("Elevator status after restart: ");
      // blinkLcd();
      
      lcd.clear();
      elevatorFloor = EEPROM.read(0);
      //lcd.print("Your in the");
      lcd.print("WELCOME! Your in");
      if(elevatorFloor == 1) {
        //Serial.println ("Your in the 1st floor");
        lcd.setCursor(0, 1);
        lcd.print("the 1st floor.");
        if(stateR==2){
          blinkLcd();
        }
      
      } 
      if(elevatorFloor == 2) {
        // Serial.println ("Your in the 2nd floor");
        lcd.setCursor(0, 1);
        lcd.print("the 2nd floor.");
        if(stateR ==2){
          blinkLcd();
        }
      }
      if(elevatorFloor == 3) {
        // Serial.println ("Your in the 3rd floor");
        lcd.setCursor(0, 1);
        lcd.print("the 3rd floor.");
        if(stateR ==2){
          blinkLcd();
        }
      }
      if(elevatorFloor == 4) {
        // Serial.println ("Your in the 4th floor");
        lcd.setCursor(0, 1);
        lcd.print("the 4th floor.");
        if(stateR ==2){
          blinkLcd();
        }
      }
  }
  
  void blinkLcd(){
      int wait=500;
      // Turn off the display:
      lcd.noDisplay();
      delay(wait);
      // Turn on the display:
      lcd.display();
      delay(wait);
      // Turn off the display:
      lcd.noDisplay();
      delay(wait);
      // Turn on the display:
      lcd.display();
      delay(wait);
      // Turn off the display:
      lcd.noDisplay();
      delay(wait);
      // Turn on the display:
      lcd.display();
      delay(wait);
  }
  
  void rotateStepper(int floorToGo, int currentFloor){
      stepper1.setMaxSpeed(1000);
      stepper1.setAcceleration(200);
      stepper1.setSpeed(200);
      //one revolution is 2048
      //floor 1 logic
      if(floorToGo==1 && currentFloor !=1){
        int rev = floorToGo-currentFloor;
        Serial.println(rev);
        stepper1.moveTo(2048*rev);
        
        while(stepper1.distanceToGo() !=0){
          stepper1.run();
        }
      }
      
      //floor 2 logic
      if(floorToGo==2 && currentFloor !=2){
        int rev = floorToGo-currentFloor;
        Serial.println(rev);
        stepper1.moveTo(2048*rev);
        
        while(stepper1.distanceToGo() !=0){
          stepper1.run();
        }
      }
      
      //floor 3 logic
      if(floorToGo==3 && currentFloor !=3){
        int rev = floorToGo-currentFloor;
        Serial.println(rev);
        stepper1.moveTo(2048*rev);
        
        while(stepper1.distanceToGo() !=0){
          stepper1.run();
        }
      }
      
      //floor 4 logic
      if(floorToGo==4 && currentFloor !=4){
        int rev = floorToGo-currentFloor;
        Serial.println(rev);
        stepper1.moveTo(2048*rev);
        
        while(stepper1.distanceToGo() !=0){
          stepper1.run();
        }
      
      }
  
  }

