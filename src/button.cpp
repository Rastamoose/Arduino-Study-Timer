#include "Button.h"
#include <Arduino.h>

Button::Button(int ppinNumber, const unsigned long pdebounceDuration):
    lastButtonState(LOW), debounceDuration(pdebounceDuration), pinNumber(ppinNumber), isToggledHigh(false), isRisingEdge(true){
    lastTimeButtonStateChanged = millis();
}


// TODO: edit to make detect rising edge
void Button::update(){
    // if rising edge was true last loop, then turn it off
    if (isRisingEdge){
        isRisingEdge = false;
    }
    // if debounce duration has passed, then update state
    if (millis() - lastTimeButtonStateChanged >= debounceDuration){
        byte buttonState = digitalRead(pinNumber);
        // if state is different to previous state, then change
        if (buttonState != lastButtonState){
            lastTimeButtonStateChanged = millis();
            lastButtonState = buttonState;

            if (buttonState){
                isToggledHigh = !isToggledHigh;
                isRisingEdge = true;
            }
        }
    }
}


    // if (millis() - lastTimeButtonStateChanged >= debounceDuration){
        // byte buttonState = digitalRead(pinNumber);
        //if state is different to previous state, then change
        // if (buttonState != lastButtonState){
            // lastTimeButtonStateChanged = millis();
            // lastButtonState = buttonState;
            // if (buttonState){
                // isHigh = !isHigh;
            // }
        // }
    // }