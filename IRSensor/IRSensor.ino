#include <LiquidCrystal.h>
int IRSensor = 2; // connect ir sensor to arduino pin 2
int LED = 13; // conect Led to arduino pin 13
LiquidCrystal lcd(12, 11, 6, 5, 4, 3);
void setup() 
{
  pinMode (IRSensor, INPUT); // sensor pin INPUT
  pinMode (LED, OUTPUT); // Led pin OUTPUT
  Serial.begin(9600);
  lcd.begin(16, 2);
  lcd.print("hello, world!");
}

void loop()
{
  int statusSensor = digitalRead (IRSensor);
  
  if (statusSensor == 1)
  {
    digitalWrite(LED, LOW); // LED LOW
    Serial.println("OBSTACLE!!, OBSTACLE!!");
    lcd.print("OBSTACLE!!, OBSTACLE!!");
    delay(100);
  }
  else  
  {
    Serial.println("Clear");
    digitalWrite(LED, HIGH); // LED High
    lcd.print("Clear");
    delay(100);
  }
  
}
