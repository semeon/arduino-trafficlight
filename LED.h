class LED {
  public:
    int pin;
    int state;
    unsigned long lastChanged;
    long blinkingInterval;

    LED(int p) {
      pin = p;
      state = LOW;
      lastChanged = 0;
      blinkingInterval = 1000;
      pinMode(pin, OUTPUT);     
    }

    void on() {
      lastChanged = millis();
      state = HIGH;
      digitalWrite(pin, HIGH);
    }

    void off(){
      lastChanged = millis();
      state = LOW;
      digitalWrite(pin, LOW);
    }

    void blink(int duration) {
      on();
      delay(duration);
      off();
    }

    void toggle() {
      if (state == LOW) { 
        on();
      } else {
        off();
      }
    }

    bool isTimeToChange(unsigned long ts) {
      bool result = ts - lastChanged > blinkingInterval;
      return result;
    }

};
