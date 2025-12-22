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

  // sound button
  pinMode(10, INPUT);

  for (int thisNote = 0; thisNote < 8; thisNote++) {
    int noteDuration = 1000 / noteDurations[thisNote];

    tone(8, melody[thisNote], noteDuration);

    int pauseBetweenNotes = noteDuration * 1.30;

    delay(pauseBetweenNotes);
    
    noTone(8);
  }
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
  lightSwitchState = digitalRead(10);
  if (soundSwitchState == LOW) {

  }

}
