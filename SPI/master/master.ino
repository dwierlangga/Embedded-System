//#include <SPI.h>
//
//void setup() {
//  Serial.begin(115200);
//  Serial.println("\nSPI Master");
//  SPI.begin();
//}
//
//void loop() {
//  float pi = 3.14159;
//  uint8_t *ptr = (uint8_t *)&pi;    //cast the address of a float into a pointer of byte
//
//  SPI.beginTransaction(SPISettings(4000000, MSBFIRST, SPI_MODE0));
//  digitalWrite(SS, LOW);  
//  for (int i=0; i<sizeof(pi); i++) {
//    SPI.transfer(*ptr);    // send the pi byte by byte
//    Serial.print(*ptr);    // for debugging, print out each byte
//    Serial.print(", ");
//    *ptr++;
//  }
//  digitalWrite(SS, HIGH);
//  SPI.endTransaction();
//
//  Serial.println();
//  delay(5000);
//}

//YANG DIPAKAI PADA YOUTUBE KODE DIBAWAH INI
//KODE INI UNTUK MENGIRIM DATA HELLO WORLD KE SLAVE
#include <SPI.h> //library SPI

void setup() {
  Serial.begin(115200); //baudrate yang digunakan 115200
  Serial.println("\nSPI Master"); //print pada baris pertama SPI MASTER
  SPI.begin(); //Memulai Komunikasi SPI
}

void loop() {
  char helloWorld[] = "Hello, World!"; // Mendeklarasikan array karakter (string) "Hello, World!".
  uint8_t *ptr = (uint8_t *)helloWorld; // Ini digunakan untuk mengakses data string sebagai byte.

  SPI.beginTransaction(SPISettings(4000000, MSBFIRST, SPI_MODE0)); //Memulai transaksi SPI dengan konfigurasi kecepatan 4 MHz, bit-order MSBFIRST (Most Significant Bit First), dan mode SPI_MODE0.
  digitalWrite(SS, LOW); //Mengaktifkan Slave Select (SS) dengan menurunkan levelnya ke LOW

  //Loop untuk mengirim setiap byte dari string "Hello, World!" melalui SPI.
  for (int i = 0; i < sizeof(helloWorld); i++) {  
    SPI.transfer(*ptr); // mengirim karakter, byte demi byte
    Serial.print(*ptr); // Mencetak byte saat ini ke Serial Monitor untuk tujuan debugging
    Serial.print(", "); //mencetak koma dan spasi untuk memisahkan setiap byta yang dicetak
    *ptr++; //Memindahkan pointer ke byte berikutnya.
  }
  digitalWrite(SS, HIGH); //Menonaktifkan Slave Select (SS) dengan meninggikan levelnya ke HIGH.
  SPI.endTransaction(); // Mengakhiri transaksi SPI.

  Serial.println();  //Mencetak baris baru ke Serial Monitor.
  delay(5000); //Menunda eksekusi selama 5 detik sebelum mengulang proses kembali
}
