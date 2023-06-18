#include "Timer.h"
#include <Arduino.h>

Timer::Timer(long pduration_s):
    startTime(0.0l), originalDuration(pduration_s*1000), duration(pduration_s*1000), isPaused(false), pauseStart(0.0l), isRunning(false), isFinished(false), finishTrigger(false){}

void Timer::start(){
    startTime = millis();
    duration = originalDuration;
    isRunning = true;
    isFinished = false;
}

void Timer::pause(){
    // only update to current time if hasnt been paused before, else pause time will keep updating to current moment
    if (pauseStart == 0){
        isPaused = true;
        pauseStart = millis();   
    }
}

void Timer::unpause(){
    // if paused last loop then unpause now
    if (isPaused){
        duration += millis()-pauseStart;        // add on paused time to timer
        isPaused = false;
        pauseStart = 0;
    }
}

void Timer::update(){
    // if finished for more than one loop than turn finishtrigger off
    if (isFinished){
        finishTrigger = false;
    }
    // if timer has been running longer than duration (i.e if duration-(currTime-startTime) is negative)
    if (!isPaused && isRunning && ((millis()-startTime) >= duration)){
        isFinished = true;
        finishTrigger = true;
        isRunning = false;
    }
}

long Timer::getDuration(){
    if (isRunning){
        if (isPaused){
            return duration-(pauseStart-startTime);
        } else{
            return duration-(millis()-startTime);
        }
    } else{
        return 0;
    }
}