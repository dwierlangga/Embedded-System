const int ledPin = 8; //membuat parameter ledPin dengan pin arduino 8

void setup(){
  pinMode(ledPin, OUTPUT); //deklarasikan ledPin sebagai output
}

void loop(){
  //menuliskan kondisi led hidup selama 1 detik (1000milisecond)
  digitalWrite(ledPin, HIGH);
  delay(1000);
  //menuliskan kondisi led mati selama 1 detik (1000milisecond)
  digitalWrite(ledPin, LOW);
  delay(1000);
}
