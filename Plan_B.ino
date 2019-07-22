#include<SoftwareSerial.h>
#include<SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#define OLED_RESET 4
Adafruit_SSD1306 display(OLED_RESET);

SoftwareSerial Bluetooth (5,6);
void setup()
{
 Wire.begin();
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);// initialize with the I2C addr 0x3C (for the 128x32)(initializing the display)
   Serial.begin(9600);
  Bluetooth.begin(9600);
  pinMode(7,OUTPUT);

  pinMode(8,INPUT);
  
}
void displayreading()
{
   if(Bluetooth.available()>0)
   {
   String val=Bluetooth.readString();
   Serial.print(val);
   display.clearDisplay();
  display.setTextColor(WHITE);
  display.setCursor(0,10);
  display.setTextSize(1);
  display.print(val);
}
}
void loop()
{
  displayreading();
  display.display();
}


