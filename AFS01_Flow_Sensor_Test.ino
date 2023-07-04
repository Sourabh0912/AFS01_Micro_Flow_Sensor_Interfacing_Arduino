#include <Wire.h>

u8 Data[3];
u16 Value,Temp1,Temp2;

void setup() 
{
  Wire.begin(); 
  Serial.begin(9600);       
  delay (100);
  Wire.beginTransmission(0x40);
  Wire.write(0x10);
  Wire.write(0x00);
  Wire.endTransmission();
  delay (80);
}

void loop()
{
  Wire.requestFrom(0x40, 3);

  if (Wire.available() > 0)
  {
    Wire.readBytes(Data, 3);
  }

  Temp1 = ((Data[0])<<8);
  Temp2 = Data[1];
  
  Serial.print("Data[0]:");
  Serial.print(Data[0]);
  Serial.print(" Data[1]:");
  Serial.print(Data[1]);
  Serial.print(" Data[2]:");
  Serial.print(Data[2]);
  Serial.print("\n");

  Value = Temp1 | Temp2;

  Serial.print(Value);
  Serial.print("\n");
  delay(500);
} 
