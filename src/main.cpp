#include<Arduino.h>

TaskHandle_t Task1;
TaskHandle_t Task2;


// bai hat huong dan mac dinh
#define SoluongNote 42
const int music[]={0,0,7,7,9,9,7,5,5,4,4,2,2,0,7,7,5,5,4,4,2,7,7,5,5,4,4,2,0,0,7,7,9,9,7,5,5,4,4,2,2,0};
// khai bao chan nut
const int BUTTON_PIN[]={21,22,23,25,26,27,32,33,35,34,36,39};
// khai bao chan loa
#define BUZZER_PIN 15

// khai bao tan so note nhac
const float NOTE[]={261.6256,277.1826,293.6648,311.1270,329.6276,349.2282,369.9944,391.9954,415.3047,440,466.1638,493.8833};
// C-0, C#-1, D-2, D#-3, E-4, F-5, F#-6, G-7, G#-8, A-9, A#-10, B-11

#define Duration 400 // do tre am thanh
// khai bao chan led
const int Led_Pins[]={2,4,16,17,5,18,3,1,19,13,12,14};

bool button0State = false;
bool button11State = false;
bool button1State = false;
bool button2State = false;
bool button3State = false;
bool button4State = false;

#define LED_COUNT 12

// Hàm nháy led hướng dẫn chơi nhạc //
void LedBlink( void *par ){

  for (int k = 0; k < 3; k++) {
    // Led sáng lên từ bóng 1 đến bóng 12
    for (int i = 0; i < LED_COUNT; i++) {
      digitalWrite(Led_Pins[i], HIGH);
      delay(43); // 500ms / 12 LEDs = 43ms/LED
    }
    // Led tắt từ bóng 1 đến bóng 12
    for (int i = 0; i < LED_COUNT; i++) {
      digitalWrite(Led_Pins[i], LOW);
      delay(43); // 500ms / 12 LEDs = 43ms/LED
    }
  }

  // Tất cả các LED cùng sáng trong 0.5s rồi tắt đi
  for (int i = 0; i < LED_COUNT; i++) {
    digitalWrite(Led_Pins[i], HIGH);
  }
  // sau 0.5s bắt đầu hướng dẫn chơi nhạc
  delay(500);
  for (int i = 0; i < LED_COUNT; i++) {
    digitalWrite(Led_Pins[i], LOW);
  }
  delay(1000);


  // biến i là chỉ số của music[i], giá trị của music[i] là chỉ số của Led_Pins[]

  for (int i = 0; i < SoluongNote ; i++)
  {
    digitalWrite(Led_Pins[music[i]],HIGH);
    delay(1000);
    digitalWrite(Led_Pins[music[i]],LOW);
  }
  
}
// setup các chân
void setup() {

  for (int i = 0; i < 12; i++)
  {
    pinMode(BUTTON_PIN[i],INPUT);
  }
  
  pinMode(BUZZER_PIN, OUTPUT);
  for (int i = 0; i < 12; i++)
  {
    pinMode(Led_Pins[i],OUTPUT);
  }
}


void loop() {

  // đọc giá trị các button
  button0State = digitalRead(BUTTON_PIN[0]);
  button1State = digitalRead(BUTTON_PIN[1]);

  // Nếu bấm phím 1 and 2 thì gọi hàm hướng dẫn ( core 1 )
  if (button0State==true && button1State==true) {
    delay(2000);
    xTaskCreatePinnedToCore(LedBlink,"Task1",10000,NULL,1,&Task1,1);
  }
  
  // cài đặt các phím đàn ( core 0 )

  if (digitalRead(BUTTON_PIN[0]) == HIGH) {
    tone(BUZZER_PIN,NOTE[0]);
    delay(Duration);
    noTone(BUZZER_PIN);
  }

  if (digitalRead(BUTTON_PIN[1]) == HIGH) {
    tone(BUZZER_PIN,NOTE[1]);
    delay(Duration);
    noTone(BUZZER_PIN);
  }
  
  if (digitalRead(BUTTON_PIN[2]) == HIGH) {
    tone(BUZZER_PIN,NOTE[2]);
    delay(Duration);
    noTone(BUZZER_PIN);
  }
  
  if (digitalRead(BUTTON_PIN[3]) == HIGH) {
    tone(BUZZER_PIN,NOTE[3]);
    delay(Duration);
    noTone(BUZZER_PIN);
  }
  
  if (digitalRead(BUTTON_PIN[4]) == HIGH) {
    tone(BUZZER_PIN,NOTE[4]);
    delay(Duration);
    noTone(BUZZER_PIN);
  }
  
  if (digitalRead(BUTTON_PIN[5]) == HIGH) {
    tone(BUZZER_PIN,NOTE[5]);
    delay(Duration);
    noTone(BUZZER_PIN);
  }
  
  if (digitalRead(BUTTON_PIN[6]) == HIGH) {
    tone(BUZZER_PIN,NOTE[6]);
    delay(Duration);
    noTone(BUZZER_PIN);
  }
  
  if (digitalRead(BUTTON_PIN[7]) == HIGH) {

    tone(BUZZER_PIN,NOTE[7]);
    delay(Duration);
    noTone(BUZZER_PIN);
  }
  
  if (digitalRead(BUTTON_PIN[8]) == HIGH) {
    tone(BUZZER_PIN,NOTE[8]);
    delay(Duration);
    noTone(BUZZER_PIN);
  }
  
  if (digitalRead(BUTTON_PIN[9]) == HIGH) {
    tone(BUZZER_PIN,NOTE[9]);
    delay(Duration);
    noTone(BUZZER_PIN);
  }
  
  if (digitalRead(BUTTON_PIN[10]) == HIGH) {
    tone(BUZZER_PIN,NOTE[10]);
    delay(Duration);
    noTone(BUZZER_PIN);
  }
  
  if (digitalRead(BUTTON_PIN[11]) == HIGH) {
    tone(BUZZER_PIN,NOTE[11]);
    delay(Duration);
    noTone(BUZZER_PIN);
  }
}
