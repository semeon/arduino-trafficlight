class TrafficLight {

	private:
		int mode; 	// 0 - Blinking green
					// 1 - Btton routine
		int greenBlinksBeforeChange;
	
	public:

		LED greenLed;
		LED yellowLed;
		LED redLed;
		BTN button;

		LED stdLed;

	    TrafficLight(): greenLed(8), yellowLed(7), redLed(4), button(2), stdLed(13) {
			mode = 0;
			greenBlinksBeforeChange = 6;
	    }

	    void init(int times) {
	    	for (int i=0; i<times; i++) {
			  greenLed.blink(200);
			  yellowLed.blink(200);
			  redLed.blink(200);
	    	}
	    }

	    int getMode() {
	    	return mode;
	    }

	    void startLightChangeRoutine() {
	    	mode = 1;
	    }

	    void switchToBlinkingGreen() {
	    	redLed.off();
	    	yellowLed.off();
	    	mode = 0;
	    }

	    void lightChangeRoutine() {
	    	stdLed.on();

	    	// Keep blinking green for a while
	    	int blinks = 0;
	    	do {
			    if (greenLed.isTimeToChange(millis())){
			      greenLed.toggle();
			      blinks++;
			    }
	    	}
	    	while (blinks < greenBlinksBeforeChange);

	    	// Stale Green
	    	greenLed.on();
			delay(5000);
	    	greenLed.off();

	    	// Swithch to Yellow
			yellowLed.on();
			delay(5000);
			yellowLed.off();

	    	stdLed.off();

	    	// Swithch to Red
			redLed.on();
			delay(20000);
			redLed.off();
	    }


};