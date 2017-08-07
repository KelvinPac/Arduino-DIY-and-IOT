//Automate moisture control using a moisture sensor and relay module.
//Display moisture content in 19*2 LCD display
//if moisture content is low, trigger relay till moisture content is back to required level

//Step 1. Include LCD
//Step 2. Include moisture sensor
//Step 3. Include Relay
//Step 4. Logic

// include the library code:
#include <LiquidCrystal.h>

//moisture sensor
int rainPin = A0;
// initialize the library with the numbers of the interface pins
//LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
LiquidCrystal lcd(7, 8, 9, 10, 11, 12);
  
// you can adjust the threshold value
int thresholdValue = 800;

void setup() {
  // set up the LCD's number of columns and rows:
  lcd.begin(16, 2);
  pinMode(5, OUTPUT);
  // Print a message to the LCD.
  lcd.print("IRRIGATION SYSTEM");

}

void loop() {
  lcd.clear();
//  // Turn off the display:
//  lcd.noDisplay();
//  delay(500);
//  // Turn on the display:
//  lcd.display();
//  delay(500);

// read the input on analog pin 0:
  int sensorValue = analogRead(rainPin);

  Serial.print(sensorValue);
  if(sensorValue < thresholdValue){
    Serial.println("Doesn't need watering");
     lcd.print("No need to Water");
     lcd.setCursor(13, 1);
     lcd.print("OK");
  }
  else {
    Serial.println(" - Time to water your plant");
    lcd.print("Watering Plants");
    lcd.setCursor(10, 1);
    lcd.print("NOT-OK");

    digitalWrite(5, HIGH);   
    delay(7000);              
    digitalWrite(5, LOW);   
//  delay(1000);              
  }

  // Display sensorValue on second row
  lcd.setCursor(0, 1);

  // ----------------
  lcd.print("Moist ");
  lcd.setCursor(6, 1);
  lcd.print(sensorValue);
  delay(500);

}
