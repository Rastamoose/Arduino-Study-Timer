// credit to  Robson Couto, 2019 
// More songs available at https://github.com/robsoncouto/arduino-songs   

#include <Melody.h>
#include "Arduino.h"

Melody::Melody(int* pmelody, int sizeMelody, int sizeFirst, int ptempo, int pdivider, int pnoteDuration):
    buzzerPin(NULL),tempo(ptempo),melody(pmelody),divider(pdivider),noteDuration(pnoteDuration),currentNote(0),prevTime(0.0l), isPlaying(false){
    // sizeof gives the number of bytes, each int value is composed of two bytes (16 bits)
    // there are two values per note (pitch and duration), so for each note there are four bytes
    notes = sizeMelody / sizeFirst / 2;
    // this calculates the duration of a whole note in ms
    wholenote = (60000 * 4) / tempo;
}

Melody::~Melody(){
    delete[] melody;
}


// TODO: MAKE ASYNCHORNOUS
void Melody::play(int buzzer){
  isPlaying = true;
  buzzerPin = buzzer;
  // // iterate over the notes of the melody. 
  // // Remember, the array is twice the number of notes (notes + durations)
  // for (int thisNote = 0; thisNote < notes * 2; thisNote = thisNote + 2) {
  //   // calculates the duration of each note
  //   divider = melody[thisNote + 1];
  //   if (divider > 0) {
  //     // regular note, just proceed
  //     noteDuration = (wholenote) / divider;
  //   } else if (divider < 0) {
  //     // dotted notes are represented with negative durations!!
  //     noteDuration = (wholenote) / abs(divider);
  //     noteDuration *= 1.5; // increases the duration in half for dotted notes
  //   }

  //   // we only play the note for 90% of the duration, leaving 10% as a pause
  //   tone(buzzerPin, melody[thisNote], noteDuration*0.9);

  //   // Wait for the specief duration before isPlaying the next note.
  //   delay(noteDuration);
    
  //   // stop the waveform generation before the next note.
  //   noTone(buzzerPin);
  // }
}

void Melody::pause(){
  isPlaying = false;
}

void Melody::stop(){
  isPlaying = false;
  currentNote = 0;
}

void Melody::update(){
  if (isPlaying && buzzerPin!=NULL){
    if (millis()-prevTime >= noteDuration){
      noTone(buzzerPin);

      if (currentNote < notes*2){
        divider = melody[currentNote + 1];
        if (divider > 0) {
          // regular note, just proceed
          noteDuration = (wholenote) / divider;
        } else if (divider < 0) {
          // dotted notes are represented with negative durations!!
          noteDuration = (wholenote) / abs(divider);
          noteDuration *= 1.5; // increases the duration in half for dotted notes
        }

        // we only play the note for 90% of the duration, leaving 10% as a pause
        tone(buzzerPin, melody[currentNote], noteDuration*0.9);
        prevTime = millis();

        currentNote+=2;
      } else{
        stop();
      }
    }
  } 
}

