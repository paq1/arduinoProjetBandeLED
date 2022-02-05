#include "button.hpp"

Button::Button(Listener& listener): m_listener(listener) {}

void Button::update(const int digitalValue, const int highValue) {
    int state = digitalValue;
    if (state == highValue) {
        m_isPressed = true;
    } else {
        if (m_isPressed) {
            m_listener.action();
        }

        m_isPressed = false;
    }
}