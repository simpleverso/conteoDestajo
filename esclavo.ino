#include <Wire.h>
#include <LiquidCrystal.h>
LiquidCrystal lcd(13, 12, 11, 10, 9, 8);

int boton = 0;
int contador = 0;
char bandera = '0';

void setup() 
{
  lcd.begin(20, 4);
  Wire.begin(20); //direccion
  lcd.print("Direccion: 20");
  Wire.onReceive(receiveEvent);
  Wire.onRequest(requestEvent);
  pinMode(7, INPUT);
}

void loop() 
{
  delay(125);
  int boton = digitalRead(7);
  if (boton == HIGH) 
  {
   bandera='1';  
   contador++;
   lcd.setCursor(0, 3);
   lcd.print(contador); 
   delay(250);
  }
  else
  {
  }
}

void receiveEvent(int howMany) 
{
  int i = 0;
  while (Wire.available()) 
  {
   if(i==0)
   {
    char c = Wire.read();
    if(c=='1')
    {
        lcd.setCursor(0, 1);
    }
    if(c=='2')
    {
        lcd.setCursor(0, 2);
    }
    i++;
   }
   else
   {
    char c = Wire.read();
    lcd.print(c);
   }
  }
}

void requestEvent() 
{
    Wire.write(bandera);
    bandera='0';
}