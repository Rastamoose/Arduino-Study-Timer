#ifndef BUTTON_H
#define BUTTON_H

#include <Arduino.h>

class Button{
    byte lastButtonState;
    unsigned long lastTimeButtonStateChanged;
    const unsigned long debounceDuration;
    int pinNumber;

    public:
    bool isToggledHigh;         // allows button to be used as toggle switch
    bool isRisingEdge;
    Button(int pinNumber, const unsigned long debounceDuration=50);
    // detect rising edge pulses
    void update();

};

#endif