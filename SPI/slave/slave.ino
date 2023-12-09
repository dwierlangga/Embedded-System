//#include <SPI.h>
//
//volatile uint8_t byteCount = 0;
//volatile bool dataReady = false;
//
//float data;
//uint8_t *ptr = (uint8_t *)&data;
//
//// SPI interrupt routine
//ISR (SPI_STC_vect) {
//  ptr[byteCount++] = SPDR;    //read one byte form SPI Data Regiser
//  if (byteCount == 4) {
//    dataReady = true;
//  }
//}
//
//void setup (void) {
//  Serial.begin(115200);
//  Serial.println("\nSPI Slave");
//  SPCR |= bit(SPE);        // enable SPI slave mode
//  pinMode(MISO, OUTPUT);   // set MISO as OUTPUT
//  SPI.attachInterrupt();
//}
//
//void loop (void) {
//  if (dataReady) {
//    Serial.println(data, 5);
//    byteCount = 0;    // reset byteCount and dataReady flag
//    dataReady = false;
//  }
//}

//YANG DIPAKAI PADA YOUTUBE KODE DIBAWAH INI
//KODE INI DIGUNAKAN UNTUK MENERIMA KATA HELLO WORLD DARI MASTER

#include <SPI.h> //Library SPI

volatile uint8_t byteCount = 0; //Mendeklarasikan variabel byteCount sebagai volatile yang dapat diakses dari luar fungsi dan diatur ulang oleh interrupt.
volatile bool dataReady = false; //Mendeklarasikan variabel dataReady sebagai volatile yang menandakan kapan data siap untuk diproses.

char receivedData[14]; // Panjang string "Hello, World!" adalah 13, tambahkan satu untuk karakter null-terminator
uint8_t *ptr = (uint8_t *)receivedData; // Ubah tipe data pointer menjadi uint8_t

// SPI interrupt routine
ISR (SPI_STC_vect) {

  //Jika byteCount mencapai 13 (ukuran string), menambahkan null-terminator ('\0') untuk membentuk string dan mengatur dataReady menjadi true untuk menandakan bahwa data sudah lengkap.
  ptr[byteCount++] = SPDR;    // Baca satu byte dari SPI Data Register
  if (byteCount == sizeof(receivedData) - 1) {
    receivedData[byteCount] = '\0'; // Tambahkan null-terminator untuk membentuk string
    dataReady = true; 
  }
}

void setup (void) {
  Serial.begin(115200); //Inisialisasi komunikasi serial dengan kecepatan baud 115200 bps.
  Serial.println("\nSPI Slave");
  SPCR |= bit(SPE);        // Aktifkan mode SPI slave
  pinMode(MISO, OUTPUT);   // Set MISO sebagai OUTPUT
  SPI.attachInterrupt(); //Mengaktifkan interrupt pada SPI.
}

void loop (void) {

  //Jika dataReady bernilai true, artinya data sudah lengkap diterima
  if (dataReady) {
    Serial.println(receivedData); //Mencetak nilai receivedData ke Serial Monitor.
    byteCount = 0;    //  Mereset byteCount kembali ke 0
    dataReady = false; //Mengatur dataReady kembali menjadi false untuk menunggu data selanjutnya.
  }
}
