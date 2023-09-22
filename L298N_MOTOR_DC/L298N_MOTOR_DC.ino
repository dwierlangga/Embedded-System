const int enA = 3; //membuat parameter enA untuk L298N dan terhubung dengan pin 3 arduino
const int IN1 = 4; //membuat parameter IN1 untuk L298N dan terhubung dengan pin 4 arduino
const int IN2 = 5; //membuat parameter IN2 untuk L298N dan terhubung dengan pin A1 arduino

void setup(){
  //setting paraemter sebagai input dan output
  pinMode(enA, OUTPUT);
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
}

void loop(){
  analogWrite(enA, 60); //membuat kecepatan motor DC sebesar 60
  //membuat kondisi motor dc berputar kedepan/kebelakang sesuaikan saja
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  delay(500); //jeda proses 0.5 detik\

  analogWrite(enA, 60); //membuat kecepatan motor DC sebesar 60
  //membuat kondisi motor dc berputar kedepan/kebelakang sesuaikan saja
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  delay(500); //jeda proses 0.5 detik
}
