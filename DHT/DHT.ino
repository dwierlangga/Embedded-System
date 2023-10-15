#include <DHT.h> //masukan library DHT, download pada sketch>include library>manages libraries>ketik "Dht sensor library">download by Adafruit
#define DHTPIN 9 //definsikan bahwa DHTPIN pada pin 9
#define DHTTYPE DHT11 //definisikan bahwa yang dipakai adalah DHT tipe 11

DHT dht(DHTPIN, DHTTYPE); //digunakan untuk menginisialisasi objek dari library DHT

void setup(){
  Serial.begin(9600); //membuka komunikasi pada serial monitor dengan baudrate 9600
  dht.begin(); //menginisialisasi sensor DHT dan persiapan untuk membaca data dari sensor
}

void loop(){
  //baca data dari sensor DHT
  float humi = dht.readHumidity();
  float temp = dht.readTemperature();

  //menampilkan data sensor
  Serial.print("Kelembaban  : ");
  Serial.print(humi);
  Serial.println("%");
  Serial.print("Temperatur  : ");
  Serial.print(temp);
  Serial.println("C");
  delay(200);
}
