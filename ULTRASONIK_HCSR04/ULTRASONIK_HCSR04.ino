const int trig = A0; //membuat parameter trig untuk HCSR-04 dan terhubung dengan pin A0 arduino
const int echo = A1; //membuat parameter echo untuk HCSR-04 dan terhubung dengan pin A1 arduino

void setup(){
  Serial.begin(9600); //konfigurasi serial monitor untuk menampilkan data pada baud rate 9600
  //setting paraemter sebagai input dan output
  pinMode(trig, OUTPUT);
  pinMode(echo, INPUT);
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

  //Tampilkan data pada serial monitor
  Serial.print("Jarak yang terbaca : ");
  Serial.print(cm);
  Serial.println(" CM"); //println untuk memberikan enter pada data yang akan dikeluarkan selanjutnya

  delay(500); //proses 0.5 detik sekali
}
