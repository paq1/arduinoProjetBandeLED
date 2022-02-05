#include "arduinoButton.hpp"
#include <Arduino.h>

ArduinoButton::ArduinoButton(Listener& Listener, int pin)
: Button(Listener), m_pin(pin) {
    pinMode(m_pin, INPUT);
}

void ArduinoButton::onClickUpdate() {
    int state = digitalRead(m_pin);
    update(state, HIGH);
}