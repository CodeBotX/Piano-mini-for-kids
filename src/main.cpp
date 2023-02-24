#include<Arduino.h>
TaskHandle_t Task1;
TaskHandle_t Task2;

#define SoluongNote 42
const int music[]={0,0,7,7,9,9,7,5,5,4,4,2,2,0,7,7,5,5,4,4,2,7,7,5,5,4,4,2,0,0,7,7,9,9,7,5,5,4,4,2,2,0};
int melody1[1000], melodyIndex = 0;

const int BUTTON_PIN[]={21,22,23,25,26,27,32,33,35,34,36,39};

#define BUZZER_PIN 15

const float NOTE[]={261.6256,277.1826,293.6648,311.1270,329.6276,349.2282,369.9944,391.9954,415.3047,440,466.1638,493.8833};
// C-0, C#-1, D-2, D#-3, E-4, F-5, F#-6, G-7, G#-8, A-9, A#-10, B-11

#define Duration 350

const int LedPin[]={2,4,16,17,5,18,3,1,19,13,12,14};

bool button0State = false;
bool button11State = false;
bool button1State = false;
bool button2State = false;
bool button3State = false;
bool button4State = false;
// chan loa
#define LED_COUNT 12


void LedBlink( void *par ){
  
  for (int repeat = 0; repeat < 3; repeat++) {
    // Led sáng lên từ bóng 1 đến bóng 12
    for (int i = 0; i < LED_COUNT; i++) {
      digitalWrite(LedPin[i], HIGH);
      delay(83); // 1000ms / 12 LEDs = 83ms/LED
    }
    // Led tắt từ bóng 12 đến bóng 1
    for (int i = LED_COUNT - 1; i >= 0; i--) {
      digitalWrite(LedPin[i], LOW);
      delay(83); // 1000ms / 12 LEDs = 83ms/LED
    }
  }

  // Tất cả các LED cùng sáng trong 0.5s rồi tắt đi
  for (int i = 0; i < LED_COUNT; i++) {
    digitalWrite(LedPin[i], HIGH);
  }
  delay(500);
  for (int i = 0; i < LED_COUNT; i++) {
    digitalWrite(LedPin[i], LOW);
  }
  delay(1000);

  for (int i = 0; i < SoluongNote ; i++)
  {
    digitalWrite(LedPin[music[i]],HIGH);
    delay(450);
    digitalWrite(LedPin[music[i]],LOW);
  }
  
}

unsigned long lastPressedTime = 0;
const unsigned long MAX_WAIT_TIME = 5000; // 5 giay

// hàm để lưu nhạc
void loadMelody_1 ( void *par ){
  for (int i = 0; i < LED_COUNT; i++)
  {
    digitalWrite(LedPin[i],HIGH);
  }
  delay(1000);
  for (int i = 0; i < LED_COUNT; i++)
  {
    digitalWrite(LedPin[i],LOW);
  }
  
  bool recording = true;
  lastPressedTime = millis();
  do{
    // kiểm tra thời gian
  while (recording) {
    // Kiểm tra xem đã quá thời gian chưa
    if (millis() - lastPressedTime > MAX_WAIT_TIME) {
      recording = false;
    }
  }
  // Kiểm tra nút nào được bấm
  for (int i = 0; i < 12; i++) {
    if (digitalRead(BUTTON_PIN[i]) == HIGH) {
      melody1[melodyIndex++] = i; // Lưu nút được bấm vào mảng nhạc
      lastPressedTime = millis(); // Cập nhật thời gian lần cuối mà có sự kiện bấm nút
    }
  }
  }while(recording == true);
}

// hàm để phát nhạc
void playmelody(void *par ){
  for (int i = 0; i < melodyIndex; i++) {
    int note = melody1[i];
    digitalWrite(LedPin[i],HIGH);
    delay(450);
    digitalWrite(LedPin[i],LOW);
  }
}


void setup() {
  for (int i = 0; i < 12; i++)
  {
    pinMode(BUTTON_PIN[i],INPUT);
  }
  
  pinMode(BUZZER_PIN, OUTPUT);
  for (int i = 0; i < 12; i++)
  {
    pinMode(LedPin[i],OUTPUT);
  }
}


void loop() {
  button0State = digitalRead(BUTTON_PIN[0]);
  button11State = digitalRead(BUTTON_PIN[11]);
  button1State = digitalRead(BUTTON_PIN[1]);
  button1State = digitalRead(BUTTON_PIN[2]);

  if (button0State==true && button11State==true) {
    delay(2000);
    xTaskCreatePinnedToCore(LedBlink,"Task1",10000,NULL,1,&Task1,1);
  }
  if (button0State==true && button1State==true) {
    delay(2000);
    xTaskCreatePinnedToCore(loadMelody_1,"Task1",10000,NULL,1,&Task1,1);
  }
  if (button0State==true && button2State==true) {
    delay(2000);
    xTaskCreatePinnedToCore(playmelody,"Task1",10000,NULL,1,&Task1,1);
  }
  

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
