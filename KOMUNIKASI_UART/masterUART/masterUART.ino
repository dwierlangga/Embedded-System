void setup(){
  Serial.begin(9600); //menginisialisasi komunikasi serial antara mikrokontroler
}

void loop(){
  String request = ""; //Menginisiasi string kosong
  while(Serial.available()>0){ //looping akan terus berjalan ketika ada data yang masuk pada serial
    request +=char(Serial.read()); //menambahkan karakter request kedalam string
  }
  request.trim(); //menghapus spasi ekstra di awal dan di akhir string

  if(request == "Yes"){ //jika nilai request terpenuhi, maka data akan diproses
    SendData();
  }
  request = ""; //// Setelah memproses permintaan, mengosongkan request untuk permintaan selanjutnya
  delay(500);
}

//membuat void untuk tugas
void SendData(){
  int data1 = 0;
  int data2 = 2;
  data1 = data1 + 1;
  data2 = data2 + 2;

  String DataSend = String(data1)+"#"+String(data2);membuat sebuah objek String yang menggabungkan dua variabel atau nilai, yaitu data1 dan data2, dipisahkan oleh tanda pagar (#).
  Serial.println(DataSend); //mencetak data dari parameter string DataSend
}
