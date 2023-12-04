#include <Wire.h> //Library untuk komunikasi I2C

int input =0; //membuat variabel input dengan nilai 0

void setup()
{
  pinMode(4, INPUT); //mendeklarasikan pin 4 sebagai input
  Wire.begin(); //memulai library Wire
}

void loop()
{
  input = digitalRead(4); //membaca input pada pin 4
  Wire.beginTransmission(1); //memulai komunikasi dengan alamat tujuan 1
  Wire.write(input); //mengirimkan data input
  Wire.endTransmission(); //mengakhiri komunikasi
  delay(100);
}
