 
//Prateek
//www.prateeks.in

#include<LiquidCrystal.h>
LiquidCrystal lcd(9,8,7,6,5,4);
int state = 0;
const int pin = 2;
void setup()
{
  //Set Exact Baud rate of the GSM/GPRS Module.
  lcd.begin(16,2);
 lcd.setCursor(0, 0);
 lcd.print("WOMEN SAFETY ");
 lcd.setCursor(0, 1);
 lcd.print("SYSTEM");
 delay(3000);
 lcd.clear();
  lcd.setCursor(0, 0);
 lcd.print("WOMEN IS SAFE ");
  Serial.begin(9600);
  
}
void loop()
{
  if (digitalRead(pin) == HIGH && state == 0) {
    Serial.print("\r");
    delay(1000);
    Serial.print("AT+CMGF=1\r");
    delay(1000);
    /*Replace XXXXXXXXXX to 10 digit mobile number & ZZ to 2 digit country code*/
    Serial.print("AT+CMGS=\"+918830584864\"\r");
    delay(1000);
    //The text of the message to be sent.
    Serial.print("Prateek Singh");
      lcd.setCursor(0, 0);
   lcd.print("WOMEN IN DANGER ");
   delay(3000);
   lcd.clear();
    delay(1000);
    Serial.write(0x1A);
    delay(1000);
    state = 1;
  }
 if (digitalRead(pin) == LOW && state == 1) {
    state = 0;
  }
}
