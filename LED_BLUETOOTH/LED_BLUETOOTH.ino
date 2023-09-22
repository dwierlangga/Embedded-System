const int led = 8; //deklarasikan parameter led dengan pin 8 Arduino

void setup(){
  Serial.begin(9600); //membuat komunikasi serial monitor dengan baud rate 9600
  pinMode(led, OUTPUT); //Parameter led menjadi output
}

void loop(){
  if (Serial.available()>0) //jika dalam Serial terdapat data maka akan dilanjut dengan perintah selanjutnya
  {
    char data = Serial.read(); //membuat parameter data jika Serial membaca data yang dikirimkan
    //membuat kondisi, bisa menggunakan switch case atau if else
    switch(data) //mengambil data dan memilih sesuai yang ada pada case-case yang dibuat
    {
      case '1': //membuat pilihan dengan value '1'
      digitalWrite(led, HIGH); //Membuat kondisi Led menyala
      break; //berhenti jiga nilai sudah terpenuhi
      case '2':
      digitalWrite(led, LOW);
      break;
    }
  }
}
