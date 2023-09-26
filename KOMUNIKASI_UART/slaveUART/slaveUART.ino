String arrData[2]; //mendefinisikan sebuah array yang berisi dua elemen bertipe data String

int data11, data22; //mendefinisikan integer dengan parameter data11, data22

void setup(){
  Serial.begin(9600); //menginisialisasi komunikasi serial antara mikrokontroler
}

void loop(){
  String data = ""; //Menginisiasi string kosong
  while(Serial.available()>0){ //looping akan terus berjalan ketika ada data yang masuk pada serial
    data += char(Serial.read()); //menambahkan karakter request kedalam string
  }
  data.trim(); //menghapus spasi ekstra di awal dan di akhir string

  if(data != ""){ //memeriksa apakah variabel data tidak kosong
    int index = 0;  // Deklarasi dan inisialisasi variabel index
    for(int i=0; i<= data.length(); i++){ //mengulangi sebuah blok kode dengan variabel penghitung i dimulai dari 0 dan terus bertambah hingga i mencapai panjang string data.
      char delimeter = '#'; //mendeklarasikan variabel bertipe data char yang disebut delimiter dan memberikan nilai karakter '#' ke dalam variabel tersebut.
      if(data[i] != delimeter){ //memeriksa apakah karakter pada indeks i dalam string data tidak sama dengan karakter yang disimpan dalam variabel delimiter.
        arrData[index] += data[i]; //digunakan untuk menambahkan karakter data[i] ke dalam elemen array arrData pada indeks index. Ini menggabungkan karakter data[i] dengan konten yang sudah ada di elemen array tersebut.
      }
      else{ //jika logika diatas tidak terpenuhi
        index++; // Pindah ke elemen array berikutnya jika delimiter '#' ditemukan
      }
    }
    if(index == 1){ //digunakan untuk memeriksa apakah nilai dari variabel index
      Serial.println("Data 1 count : " + arrData[0]); //cetak data yang terbaca
      Serial.println("Data 2 count : " + arrData[1]);
    }
  }
  Serial.println("yes"); //memberikan nilai request
  delay(500);
}
