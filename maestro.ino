#include <PString.h>
#include <Wire.h>

String inputString = "";
boolean stringComplete = false;

void setup() 
{
  Wire.begin(); 
  Serial.begin(9600);
  inputString.reserve(200);
}

void loop() 
{   
   if (stringComplete)
   {
   String direccions = inputString.substring(0,2);
   String informacion = inputString.substring(2);
   char arreglo[22];
   PString(arreglo,sizeof(arreglo),informacion);
   int direc = direccions.toInt();
   Wire.beginTransmission(direc);
   Wire.write(arreglo);
   Wire.endTransmission();
   inputString = "";
   stringComplete = false;
   }
   delay(25);
   
   recoger(1);
   recoger(2);
   recoger(3);
   recoger(4);
   recoger(5);
   recoger(6);
   recoger(7);
   recoger(8);
   recoger(9);
   recoger(10);
   recoger(11);
   recoger(12);
   recoger(13);
   recoger(14);
   recoger(15);
   recoger(16);
   recoger(17);
   recoger(18);
   recoger(19);
   recoger(20);   
}

void serialEvent() 
{
  while (Serial.available()) 
  {
    char inChar = (char)Serial.read(); 
    if (inChar == '\n') 
    {
      stringComplete = true;
    }
   else
    {
      inputString += inChar;
    } 
  }
}

void recoger(int valor) 
{
   Wire.requestFrom(valor, 1);    // request 1 bytes from slave device #8
   while (Wire.available()) 
   {
    char c = Wire.read();
    Serial.print(valor);
    Serial.print(":");
    Serial.print(c);
    Serial.print("\n");
   }
   delay(20);
}