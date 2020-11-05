#include "pitches.h"

#define buzzer 9
#define Blue_LED 3
#define Red_LED 5
#define Green_LED 2
#define pot A4

int potValue;

void setup() {
  Serial.begin(9600);
  pinMode(Blue_LED, OUTPUT);
  pinMode(Green_LED, OUTPUT);
  pinMode(Red_LED, OUTPUT);
  pinMode(pot, INPUT);

}

void loop() {
   if(getPot() == 0){
     //LED OFF : No Music
     digitalWrite(Blue_LED, LOW);
     digitalWrite(Red_LED, LOW);
     digitalWrite(Green_LED, LOW);
     killSound();
   }
   else if (getPot() == 1){
    //GREEN LED ON : Play Music 1
    digitalWrite(Green_LED, HIGH);
    digitalWrite(Red_LED, LOW);
    digitalWrite(Blue_LED, LOW);
    song1();
   }
   else if (getPot() == 2){
    //RED LED ON : Play Music 2
    digitalWrite(Red_LED, HIGH);
    digitalWrite(Blue_LED, LOW);
    digitalWrite(Green_LED, LOW);
    song2();
   }
   else if (getPot() == 3){
    //BLUE LED ON : Play Music 3
    digitalWrite(Blue_LED, HIGH);
    digitalWrite(Red_LED, LOW);
    digitalWrite(Green_LED, LOW);
    song3();
   }
}


int getPot(){
  potValue = analogRead(pot);
  potValue = map(potValue,0,1023,0,3);
  Serial.println(potValue);
  return potValue;
}

void killSound(){
  noTone(buzzer);
}

int note_dur;

void song1(){
  note_dur = 200;
  play(NOTE_E5,1); play(NOTE_E5,1); play(REST,1); play(NOTE_C5,1);  play(NOTE_E5,1);
  play(NOTE_G5,1); play(REST,1); play(NOTE_G4,1); play(REST,1); play(NOTE_C5,1);
}


void song2(){
  note_dur = 144;
  play(NOTE_E5,1); play(NOTE_B4,1); play(NOTE_C5,1); play(NOTE_D5,1); play(NOTE_C5,1);
  play(NOTE_B4,1); play(NOTE_A4,1); play(NOTE_A4,2); play(NOTE_C5,1); play(NOTE_E5,1);
  
}

void song3(){
  note_dur = 105;
  play(NOTE_B4,1); play(NOTE_B5,1); play(NOTE_FS5,1); play(NOTE_DS5,1); play( NOTE_B5,1);
  play(NOTE_FS5,1); play(NOTE_DS5,1); play(NOTE_C5,1); play(NOTE_C6,1); play(NOTE_G6,1);
  play(NOTE_E6,1); play(NOTE_C6,1); play(NOTE_G6,1); play(NOTE_E6,1);
  
}

void play(int note , int dur){
  tone(buzzer, note);
  delay(dur* note_dur);
  noTone(buzzer);
  delay(dur*note_dur/3);
}
