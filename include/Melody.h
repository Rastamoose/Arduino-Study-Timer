// credit to  Robson Couto, 2019 
// More songs available at https://github.com/robsoncouto/arduino-songs                                                                                                                               

#ifndef MELODY_H
#define MELODY_H

#include <Arduino.h>

class Melody{
    int buzzerPin;
    int tempo;
    // notes of the moledy followed by the duration.
    // a 4 means a quarter note, 8 an eighteenth , 16 sixteenth, so on
    // !!negative numbers are used to represent dotted notes,
    // so -4 means a dotted quarter note, that is, a quarter plus an eighteenth!!
    int* melody;      // array containing all notes
    int notes;
    int wholenote;
    int divider;
    int noteDuration;
    int currentNote;
    long prevTime;


    public:
    bool isPlaying;
    
    Melody(int* pmelody, int sizeMelody, int sizeFirst, int ptempo, int pdivider=0, int pnoteDuration=0);
    ~Melody();;
    void play(int buzzerPin);   // start playing melody
    void pause();               // pause melody at current place (use play to unpause)
    void stop();                // stop melody and reset
    void update();              // keeps melody going in the background
};

#endif