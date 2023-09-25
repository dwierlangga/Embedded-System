#include <Arduino_FreeRTOS.h> //Library untuk RTOS

const int led1 = 2; //deklarasikan perameter led1 untuk pin 2 Arduino Uno
const int led2 = 3; //deklarasikan perameter led1 untuk pin 3 Arduino Uno

//membuat tugas untuk paremeter led1
void TaskBlink1(void *pvParameters){
  (void)pvParameters;

  pinMode(led1, OUTPUT); //Menginisiasi led1 sebagai output
  for(;;){
    digitalWrite(led1, HIGH); //menghidupkan led1
    vTaskDelay(1000/portTICK_PERIOD_MS); //tunggu 1 detik
    digitalWrite(led1, LOW); //menghidupkan led1
    vTaskDelay(1000/portTICK_PERIOD_MS); //tunggu 1 detik
  }
}

//membuat tugas untuk paremeter led2
void TaskBlink2(void *pvParameters){
  (void)pvParameters;

  pinMode(led2, OUTPUT); //Menginisiasi led1 sebagai output
  for(;;){
    digitalWrite(led2, HIGH); //menghidupkan led1
    vTaskDelay(2000/portTICK_PERIOD_MS); //tunggu 2 detik
    digitalWrite(led2, LOW); //menghidupkan led1
    vTaskDelay(1000/portTICK_PERIOD_MS); //tunggu 1 detik
  }
}

void setup(){
  xTaskCreate(TaskBlink1, "Blink1", 128, NULL, 1, NULL); //memanggil tugas 1
  xTaskCreate(TaskBlink2, "Blink2", 128, NULL, 2, NULL); //memanggil tugas 2

  vTaskStartScheduler(); //Memulai penjadwalan freeRTOS
}

void loop(){
}
