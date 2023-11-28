#include<SoftwareSerial.h>

SoftwareSerial dataSerial(12, 13);

unsigned long previousMillis = 0;
const long interval = 2000;

String arrData[2];
float temp, hum;

void setup() {
  Serial.begin(9600);
  dataSerial.begin(9600);
}

void loop() {
  unsigned long currentMillis = millis();
  if(currentMillis - previousMillis >= interval){
    previousMillis = currentMillis;

    String data = "";
    while(dataSerial.available()>0){
      data += char(dataSerial.read());
    }
    data.trim();

    if(data != ""){
      int index = 0;
      for(int i=0; i<= data.length(); i++){
        char delimiter = '#';
        if(data[i] != delimiter){
          arrData[index] += data[i];
        }
        else{
          index++;
        }
      }

      if(index == 1){
        Serial.println("Temperature : " + arrData[0]);
        Serial.println("Humidity    : " + arrData[1]);
        Serial.println();
      }

      temp = arrData[0].toFloat();
      hum  = arrData[1].toFloat();
      
      arrData[0] = "";
      arrData[1] = "";
    }

    dataSerial.println("Yes");
  }
}
