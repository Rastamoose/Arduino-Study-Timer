#include <LiquidCrystal.h>
#include "Pitches.h"
#include "Songs.h"
#include "Melody.h"
#include "Button.h"
#include "Timer.h"

#define LDR A5
#define BUTTON 2
#define ALARM_LED 3
#define LOCK_LED 4
#define BUZZER 5
#define RS 6
#define EN 7
#define D4 8
#define D5 9
#define D6 10
#define D7 11

Melody miiMusic = Melody(mii, sizeof(mii), sizeof(mii[0]), miiTempo);
Melody haircutMusic = Melody(haircut, sizeof(haircut), sizeof(haircut[0]), haircutTempo);
Melody marioMusic = Melody(mario, sizeof(mario), sizeof(mario[0]), marioTempo);
Melody hpMusic = Melody(hp, sizeof(hp), sizeof(hp[0]), hpTempo);
Melody takeonmeMusic = Melody(takeonme, sizeof(takeonme), sizeof(takeonme[0]), takeonmeTempo);

Melody* failMusic = &haircutMusic;
Melody* successMusic = &hpMusic;

Button lockButton = Button(BUTTON);
LiquidCrystal lcd(RS, EN, D4,D5,D6,D7);

// FPS stuff
int LCDFPS = 24;
long prevTime = millis();
long currTime;
int frameGap;
int frametime;
String lcdFirstLine = ""; 
String lcdSecondLine = "";

int timerDuration = 2*60;
Timer timer = Timer(timerDuration);
bool lock = false;
const int LDRTHRESHOLD = 100;

String formatTime(long time_ms){
  div_t minsSecs = div((time_ms/1000),60.0l);
  // add extra 0 if number is singe digit (always format as xx:xx)
  String mins = (minsSecs.quot > 9) ? minsSecs.quot:((String)"0"+minsSecs.quot);
  String secs = (minsSecs.rem > 9) ? minsSecs.rem:((String)"0"+minsSecs.rem);
  return (mins + ":" + secs);
}

void setup() {
  Serial.begin(9600);
  pinMode(LDR, INPUT);
  pinMode(BUTTON, INPUT);
  pinMode(ALARM_LED, OUTPUT);
  pinMode(LOCK_LED, OUTPUT);
  pinMode(BUZZER, OUTPUT);
  lcd.begin(16, 2);
}

inline void printPutPhoneIn(){
  lcdFirstLine = "Put your phone";
  lcdSecondLine = "in to begin. :)";
}

inline void printGetBackToWork(){
  lcdFirstLine = "Get back to work!";
  lcdSecondLine = ">:(";
}

inline void printFinished(){
  lcdFirstLine = "You finished!!!";
  lcdSecondLine = "Well done!!!";
  successMusic->play(BUZZER);
}

void loop() {
  timer.update();
  int ldr = analogRead(LDR);
  successMusic->update();
  haircutMusic.update();
  lockButton.update();
  digitalWrite(LOCK_LED, lock);

  if (lockButton.isRisingEdge && !lock){
    lock = true;
    timer.start();
  }


  if (successMusic->isPlaying){
    printFinished();
  } else{
    lcdFirstLine = (lock)?"Working...":"Ready to work?";
    lcdSecondLine = "";
  }

  // handle locked state
  if (lock){
    successMusic->stop();
    // check if phone has been taken out
    if (ldr < LDRTHRESHOLD){
      // check for case that phone has been put in and timer hasnt begun yet
      if (timer.getDuration()/1000>=timerDuration-1){    // check for within 1 sec
        timer.pause();
        printPutPhoneIn();
      } else{
        digitalWrite(ALARM_LED, HIGH);
        timer.pause();
        failMusic->play(BUZZER);
        printGetBackToWork();
      }
    } else{
      digitalWrite(ALARM_LED, LOW);
      failMusic->stop();
      timer.unpause();
      lcdSecondLine = formatTime(timer.getDuration());
    }
  } 
  if (timer.finishTrigger){
    lock = false;
    successMusic->play(BUZZER);
    printFinished();
  }

  currTime = millis();
  frametime = currTime-prevTime;
  frameGap = 1000-(frametime*LCDFPS);
  frameGap = (frameGap>0) ? frameGap:0;

  if (currTime-prevTime >= frameGap){
    prevTime = currTime;
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print(lcdFirstLine);
    lcd.setCursor(0,1);
    lcd.print(lcdSecondLine);
  }
}
