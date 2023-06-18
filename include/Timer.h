#ifndef TIMER_H
#define TIMER_H

#include <Arduino.h>

class Timer{
    long startTime;
    long originalDuration;  
    long duration;          // time may be added to this duration due to pauses
    bool isPaused;
    long pauseStart;

    public:
    bool isRunning;
    bool isFinished;
    bool finishTrigger;              // only stays true for 1 loop to be used as a trigger for 1 time events
    Timer(long pduration_s);                
    void start();                    // resets timer if already running
    void pause();                    // delay timer until unpause
    void unpause();                  // can call continuously, will only unpause if already paused
    void update();
    long getDuration();                   // get remaining time on a timer in ms
};

#endif


