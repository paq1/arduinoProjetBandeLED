#pragma once

#include "listener.hpp"

class Button {
private:
    Listener& m_listener;
    bool m_isPressed = false;
public:

    Button(Listener& listener);
    virtual ~Button() {}
    void update(const int digitalValue, const int highValue);
};