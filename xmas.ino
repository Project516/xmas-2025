/*

  Light and sound code for 2025 Arduino XMAS project

  Author: project516 <project516.progress139@slmail.me>
  */

#include "pitches.h"

int lightSwitchState = 0;
int soundSwitchState = 0;

int melody[] = {
  NOTE_E5, NOTE_E5, NOTE_E5,  // Jingle bells
  NOTE_E5, NOTE_E5, NOTE_E5,  // Jingle bells
  NOTE_E5, NOTE_G5, NOTE_C5, NOTE_D5, // Jingle all
  NOTE_E5,                    // The way
  NOTE_F5, NOTE_F5, NOTE_F5, NOTE_F5, // Oh what fun
  NOTE_F5, NOTE_E5, NOTE_E5, NOTE_E5, NOTE_E5, // It is to ride
  NOTE_E5, NOTE_D5, NOTE_D5, NOTE_E5,
  NOTE_D5, NOTE_G5            // Open sleigh
};

// Note durations: 4 = quarter note, 8 = eighth note, etc.
int noteDurations[] = {
  8, 8, 4,
  8, 8, 4,
  8, 8, 8, 8,
  2,
  8, 8, 8, 8,
  8, 8, 8, 16, 16,
  8, 8, 8, 8,
  4, 4
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

  }

  // sound
  soundSwitchState = digitalRead(10);
  if (soundSwitchState == HIGH) {
    playSound();
  }
}

void playSound() {
  for (int thisNote = 0; thisNote < 26; thisNote++) {
    int noteDuration = 1000 / noteDurations[thisNote];
    tone(8, melody[thisNote], noteDuration);
    int pauseBetweenNotes = noteDuration * 1.30;
    delay(pauseBetweenNotes);
    noTone(8);
  }
}
