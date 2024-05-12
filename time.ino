 #include <Wire.h>
#include <LiquidCrystal_I2C.h>

 int lastUpdateTime = 0; 
unsigned long updateInterval = 500; 
 int currentTime = 0;
int countdown = 20; // Initial countdown value
LiquidCrystal_I2C lcd(0x27,16,2);
void setup() {
  lcd.init(); 
  lcd.backlight(); 
}

void loop() {
  currentTime = millis(); // Get the current time
  // Check if it's time to update the display
  if (currentTime - lastUpdateTime >= updateInterval) {
    // Update the display with the countdown value
    lcd.setCursor(0, 0); // Set cursor to the beginning of the first line
    lcd.print("Try again in:");
    lcd.print(countdown);
    lcd.print("s");

    lastUpdateTime = currentTime; // Update the last update time

    // Decrement the countdown value
    countdown--;

    // Check if countdown reaches 0, reset it to 20
    if (countdown < 0) {
      //countdown = 0;
      lcd.clear();
    lcd.print("enter pass");
    }
    
  }
  
  
  
}

  
