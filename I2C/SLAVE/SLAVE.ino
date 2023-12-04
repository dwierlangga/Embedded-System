#include <Wire.h> //Library untuk menggunakan I2C
int input = 0; //membuat variabel input dengan nilai 0

void setup(){
  Wire.begin(1); //memulai komunikasi I2C dengan memberikan alamat 1
  Wire.onReceive(receiveEvent); //menetapkan fungsi callback yang akan dipanggil ketika perangkat sebagai slave I2C menerima data dari perangkat sebagai master I2C
  pinMode(13, OUTPUT); //mendeklarasikan pin 13 sebagai output
}

void loop(){
}

void receiveEvent(int trigger){ //membuat tugas dengan nama receiveEvent dan memberikan parameter trigger
                                //parameter ini hanya sebagai syarat yang tidak berpengeruh, tapi keberadaanya harus tetap ada
  input = Wire.read(); // membaca data yang diterima dari perangkat master melalui bus I2C dan menyimpannya dalam variabel input.
  digitalWrite(13, input); //mencetak data pada pin 13 dengan parameter input
}
