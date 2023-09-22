#include <LiquidCrystal_I2C.h> //library untuk LCD I2C
#include <Wire.h> //library untuk membaca pin SCL dan SDA
#include <Servo.h> //library untuk Servo

const int trig = A0; //membuat parameter trig untuk HCSR-04 dan terhubung dengan pin A0 arduino
const int echo = A1; //membuat parameter echo untuk HCSR-04 dan terhubung dengan pin A1 arduino

const int enA = 3; //membuat parameter enA untuk L298N dan terhubung dengan pin 3 arduino
const int IN1 = 4; //membuat parameter IN1 untuk L298N dan terhubung dengan pin 4 arduino
const int IN2 = 5; //membuat parameter IN2 untuk L298N dan terhubung dengan pin A1 arduino

LiquidCrystal_I2C lcd(0x27, 16, 2); //mendeklarasikan parameter lcd untuk LCD I2C dan memberikan alamat LCD (0x27) serta ukuran LCD (16, 2) artinya 16x2
//alamat lain dari LCD adalah 0x3f. Silahkan cari cara di google untuk menentukan alamat LCD
Servo myServo; //mendeklarasikan parameter myServo untuk Servo

void setup(){
  lcd.begin();//memulai untuk memunculkan symbol, huruf atau angka pada lcd
  //jika error dapat gunakan perintah > lcd.init();
  lcd.backlight(); //perintah untuk dapat mengatur pencahayaan lcd dengan memutar knop dengan obeng plus
  myServo.attach(10); //setting parameter myServo dengan pin 10 Arduino uno

  //setting paraemter sebagai input dan output
  pinMode(trig, OUTPUT);
  pinMode(echo, INPUT);
  pinMode(enA, OUTPUT);
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
}

void loop(){
  //mengatur pembacaan sensor HCSR04
  digitalWrite(trig, LOW);
  delayMicroseconds(2);
  digitalWrite(trig, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig, LOW);
  long duration = pulseIn(echo, HIGH); //pembacaan frequensi suara dengan jarak didepannya
  float cm = duration*0.0034/2; //rumus untuk konversi frequensi suara menjadi jarak

  //setting keluaran dan posisi LCD
  lcd.setCursor(0,0); //seting posisi penempatann pada titik 0,0
  lcd.print("Cek Jarak"); //mencetak variabel string kedalam lcd dengan posisi sesuai perintah sebelumnya
  lcd.setCursor(1,1);
  lcd.print(cm); //cetak yang didapatkan sensor HCSR04 di atas
  lcd.print("CM"); //cetak string setelah cetak perintah sebelumnya

  //membuat kondisi untuk servo dan motor DC/L298N dengan parameter sensor
  //kondisi sensor > 10 cm
  if(cm>10){
    myServo.write(90); //memutar servo ke arah 90 derajat
    analogWrite(enA, 60); //membuat kecepatan motor DC sebesar 60
    //membuat kondisi motor dc berputar kedepan/kebelakang sesuaikan saja
    digitalWrite(IN1, HIGH);
    digitalWrite(IN2, LOW);
  }
  //bukan lebih dari 10 cm
  else{
    myServo.write(0); //memutar servo ke arah 0 derajat
    analogWrite(enA, 60); //membuat kecepatan motor DC sebesar 60
    //membuat kondisi motor dc berputar kebalikan dari yang diatas
    digitalWrite(IN1, LOW);
    digitalWrite(IN2, HIGH);
  }
}
