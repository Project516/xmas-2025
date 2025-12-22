/*

  Light and sound code for 2025 Arduino XMAS project

  Author: project516 <project516.progress139@slmail.me>
  */

#include "pitches.h"

int lightSwitchState = 0;
int soundSwitchState = 0;

int melody[] = {
  NOTE_C4, NOTE_G3, NOTE_A3, NOTE_G3, 0 , NOTE_B3, NOTE_C4
};

int noteDurations[] = {
  4, 8, 8, 4, 4, 4, 4, 4
};

void setup() {
  // setup code, runs once

  // light button
  pinMode(2, INPUT);

  // lights
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);

  // sound
  pinMode(8, OUTPUT);

  // sound button
  pinMode(10, INPUT);

  /*

  // working sound code

  for (int thisNote = 0; thisNote < 8; thisNote++) {
    int noteDuration = 1000 / noteDurations[thisNote];

    tone(8, melody[thisNote], noteDuration);

    int pauseBetweenNotes = noteDuration * 1.30;

    delay(pauseBetweenNotes);
    
    noTone(8);
  }

  */
  

  // serial console
  Serial.begin(9600);

}

void loop() {
  // main code, runs repeatedly

  // lights
  lightSwitchState = digitalRead(2);
  if (lightSwitchState == LOW) {
    digitalWrite(3, LOW);
    digitalWrite(4, LOW);
    digitalWrite(5, LOW);
    digitalWrite(6, LOW);

  } else {
    digitalWrite(3, HIGH);
    digitalWrite(4, HIGH);
    digitalWrite(5, HIGH);
    digitalWrite(6, HIGH);
    Serial.println("light button on");

  }

  // sound
  soundSwitchState = digitalRead(10);
  if (soundSwitchState == HIGH) {
    Serial.println("sound button on");

    for (int thisNote = 0; thisNote < 8; thisNote++) {
    int noteDuration = 1000 / noteDurations[thisNote];

    tone(8, melody[thisNote], noteDuration);

    int pauseBetweenNotes = noteDuration * 1.30;

    delay(pauseBetweenNotes);
    
    noTone(8);
  }
  }

}
