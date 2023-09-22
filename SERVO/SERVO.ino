#include <Servo.h> //library untuk Servo

Servo myServo; //mendeklarasikan parameter myServo untuk Servo

void setup(){
  myServo.attach(10); //setting parameter myServo dengan pin 10 Arduino uno
}

void loop(){
  myServo.write(90); //membuat servo 90 derajat
  delay(2000); //waktu tunggu 2 detik
  myServo.write(0);
  delay(2000);
}
