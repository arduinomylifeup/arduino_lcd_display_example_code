/*
  Arduino DS18B20
  Created: 04/20/2016
  By Gus
  Modified N/A
  By Gus
  https://arduinomylifeup.com/
*/
#include <LiquidCrystal.h>

// initialize the library with the numbers of the interface pins
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

void setup() {
  // put your setup code here, to run once:
  lcd.begin(16, 2);
  lcd.print("hello, world!");
}

void loop() {
  delay(2000);
  lcd.clear();
  autoscrollExample();
  lcd.clear();
  cursorExample();
  lcd.clear();
  blinkExample();
  lcd.clear();
  displayOffExample();
  lcd.clear();
  scrollExample();
  lcd.clear();
  textDirectionExample();
}

void autoscrollExample(){
  lcd.print("Auto Scroll!");
  delay(2000);
  lcd.clear();

  lcd.setCursor(16, 1);
  lcd.autoscroll();
  for (int thisChar = 0; thisChar < 10; thisChar++) {
    lcd.print(thisChar);
    delay(500);
  }
  //No Auto Scroll Example
  lcd.noAutoscroll();
  lcd.clear();
  lcd.print("No Auto Scroll!");
  delay(2000);
  lcd.clear();
  // set the cursor to (0,0):
  lcd.setCursor(0, 0);
    for (int thisChar = 0; thisChar < 10; thisChar++) {
    lcd.print(thisChar);
    delay(500);
  }
}
void cursorExample(){
   lcd.print("Cursor On!");
  // Turn on the cursor:
  lcd.cursor();
  delay(3000);
  // Turn off the cursor:
  lcd.clear();  
  lcd.print("Cursor Off!");
  lcd.noCursor();
  delay(3000);
}

void blinkExample(){
  lcd.print("Blinking On!");
  // Turn on the blinking cursor:
  lcd.blink();
  delay(3000);
  lcd.clear(); 
  // Turn off the blinking cursor:
  lcd.print("Blinking Off!");
  lcd.noBlink();
  delay(3000);
}

void displayOffExample(){
  lcd.print("Display On!");
  delay(2000);
  // Turn off the display:
  lcd.noDisplay();
  delay(2000);
  // Turn on the display:
  lcd.display();
  delay(2000);
}

void scrollExample() {
  lcd.print("Scroll Right!");
  delay(3000);
  lcd.clear();  
  lcd.print("GO!");
  // scroll 29 positions (string length + display length) to the right
  // to move it offscreen right:
  for (int positionCounter = 0; positionCounter < 18; positionCounter++) {
    // scroll one position right:
    lcd.scrollDisplayRight();
    // wait a bit:
    delay(250);
  }
  lcd.clear();  
  lcd.print("Scroll Left!");
  lcd.clear();
  lcd.setCursor(16, 0);  
  lcd.print("GO!");
  // scroll 16 positions (display length + string length) to the left
  // to move it back to center:
  for (int positionCounter = 0; positionCounter < 16; positionCounter++) {
    // scroll one position left:
    lcd.scrollDisplayLeft();
    // wait a bit:
    delay(250);
  }
  // delay at the end of the full loop:
  delay(2000);
}

void textDirectionExample(){
  lcd.print("Text Direction!");
  delay(2000);
  lcd.clear();
  lcd.cursor();
  int thisChar = 'a';
  while(thisChar <= 'z'){
    // reverse directions at 'm':
    if (thisChar == 'm') {
      // go right for the next letter
      lcd.rightToLeft();
    }
    // reverse again at 's':
    if (thisChar == 's') {
      // go left for the next letter
      lcd.leftToRight();
    }
    // print the character
    lcd.write(thisChar);
    // wait a second:
    delay(250);
    // increment the letter:
    thisChar++;
  }
  // go to (0,0):
  lcd.home();
  // start again at 0
  thisChar = 'a';
}

