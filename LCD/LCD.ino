#include <LiquidCrystal_I2C.h> //library untuk LCD I2C

LiquidCrystal_I2C lcd(0x27, 16, 2); //mendeklarasikan parameter lcd untuk LCD I2C dan memberikan alamat LCD (0x27) serta ukuran LCD (16, 2) artinya 16x2
//alamat lain dari LCD adalah 0x3f. Silahkan cari cara di google untuk menentukan alamat LCD

void setup(){
  lcd.begin();//memulai untuk memunculkan symbol, huruf atau angka pada lcd
  //jika error dapat gunakan perintah > lcd.init();
  lcd.setBacklight(HIGH); //perintah untuk dapat mengatur pencahayaan lcd redup (LOW) atau terang (HIGH)
                          //untuk kondisi terang(HIGH) bisa  saja tidak harus dideklarasikan perintahnya
}

void loop(){
  //setting keluaran dan posisi LCD
  lcd.setCursor(0,0); //seting posisi penempatann pada titik 0,0
  lcd.print("Embedded S."); //mencetak variabel string kedalam lcd dengan posisi sesuai perintah sebelumnya
  lcd.setCursor(0,1);
  lcd.print("Lab. Workshop");
}
