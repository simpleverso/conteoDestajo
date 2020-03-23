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
  lcd.print("DIRECCION: 20");
  Wire.onReceive(receiveEvent);
  Wire.onRequest(requestEvent);
  pinMode(7, INPUT);
  pinMode(6, INPUT);
  pinMode(5, INPUT);
}

void loop() 
{
  delay(120);
  int boton = digitalRead(7);
  if (boton == HIGH) 
  {
   bandera='1';  
   contador++;
   lcd.setCursor(0, 3);
   lcd.print(contador); 
   delay(200);
  }
  
  int boton2 = digitalRead(6);
  if (boton2 == HIGH) 
  {
    delay(1500);
    boton2 = digitalRead(6);
    if (boton2 == HIGH) 
    {
        delay(1500);
        boton2 = digitalRead(6);
        if (boton2 == HIGH) 
        {
           bandera='f';  
           contador=0;
           lcd.setCursor(0, 3);
           lcd.print("Tarea Finalizada.");
           delay(850);
           lcd.clear();
           lcd.print("DIRECCION: 20");
           delay(250);
        }
     }
  }


 int boton3 = digitalRead(5);
  if (boton3 == HIGH) 
  {
    delay(1500);
    boton3 = digitalRead(5);
    if (boton3 == HIGH) 
    {
        delay(1500);
        boton3 = digitalRead(5);
        if (boton3 == HIGH) 
        {
           bandera='p';  
           contador=0;
           lcd.setCursor(0, 3);
           lcd.print("Tarea Pausada.");
           delay(850);
           lcd.clear();
           lcd.print("DIRECCION: 20");
           delay(250);
        }
     }
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
