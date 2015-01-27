#include <Arduino.h>
#include "LED.h"
#include "BTN.h"
#include "TrafficLight.h"

TrafficLight tl = TrafficLight();

// the setup routine runs once when you press reset ================================
void setup() {   
  tl.init(3);
}

// the loop routine runs over and over again forever =================================
void loop() {
  unsigned long currentTimestamp = millis();

  switch (tl.getMode()) {
    case 1:
      tl.lightChangeRoutine();
      tl.switchToBlinkingGreen();
      break;

    case 0:
      // Blink green
      if (tl.greenLed.isTimeToChange(currentTimestamp)){
        tl.greenLed.toggle();
      }

      // Check for button click
      if (tl.button.clicked()) {     
        // turn LED on:    
        tl.startLightChangeRoutine();
      }
      break;
  }
}












