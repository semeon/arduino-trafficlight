class BTN {

	private:
		int lastState;
		long previousMillis;
		long interval;
	
	public:
	    int pin;

	    BTN(int p) {
	    	pin = p;
			int lastState = LOW;
			previousMillis = 0;  
			interval = 300; 			
	    }

	    int clicked() {

	    	unsigned long currentMillis = millis();
	    	int newState = digitalRead(pin);
	    	
	    	bool result = (newState == HIGH) 
	    					&& (lastState == LOW);
	    					// && ( (currentMillis - previousMillis) > interval );

	    	lastState = newState;
	    	previousMillis = currentMillis;
	    	return result;
	    }

};