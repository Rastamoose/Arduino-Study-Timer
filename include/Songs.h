#include "Pitches.h"
/* 

 * Song definitions - 4 variables per song
 * 1st array defines notes in melody
 * 2nd array defines duration of notes
   * Note durations:
   * 4 = quarter note, 8 = eighth note, etc.
 * Int length of song i.e. number of notes
 * Int tempo multiplier

*/

/* shave and a haircut */
int haircut[] = {
  NOTE_C4,4, NOTE_G3,8, NOTE_G3,8, NOTE_A3,4, NOTE_G3,4, REST,4, NOTE_B3,4, NOTE_C4,4
};
int haircutLength = 8;
int haircutTempo = 100;

/* mario theme */
int mario[] = {
  NOTE_E4,8, NOTE_E4,8, REST,8, NOTE_E4,8, REST,8, NOTE_C4,8, NOTE_E4,8, REST,8, NOTE_G4,8, REST,3, NOTE_G3
};
int marioLength = 11;
int marioTempo = 150;

/* mii theme */
int mii[] = {
  NOTE_FS4,8, REST,8, NOTE_A4,8, NOTE_CS5,8, REST,8, NOTE_A4,8, REST,8, NOTE_FS4,8,
  NOTE_D4,8, NOTE_D4,8, NOTE_D4,8, REST,8, NOTE_D5,8, NOTE_D5,8, NOTE_D5,8
};
int miiLength = 15;
int miiTempo = 160;

/* harry potter */
int hp[] = {
  NOTE_D4,4, NOTE_G4,4, NOTE_AS4,8, NOTE_A4,4, NOTE_G4,2, NOTE_D5,4, NOTE_C5,-2,
  NOTE_A4,-2, NOTE_G4,-4, NOTE_AS4,8, NOTE_A4,4, NOTE_F4,2, NOTE_GS4,4, NOTE_D4,1
};
int hpLength = 14;
int hpTempo = 140;

/* take on me */
int takeonme[] = {
  NOTE_FS5,8, NOTE_FS5,8, NOTE_D5,8, NOTE_B4,8, REST,8, NOTE_B4,8, REST,8, NOTE_E5,8,
  REST,8, NOTE_E5,8, REST,8, NOTE_E5,8, NOTE_GS5,8, NOTE_GS5,8, NOTE_A5,8, NOTE_B5,8,
  NOTE_A5,8, NOTE_A5,8, NOTE_A5,8, NOTE_E5,8, REST,8, NOTE_D5,8, REST,8, NOTE_FS5,8, 
  REST,8, NOTE_FS5,8, REST,8, NOTE_FS5,8, NOTE_E5,8, NOTE_E5,8, NOTE_FS5,8, NOTE_E5,8
};
int takeonmeLength = 32;
int takeonmeTempo = 120;
