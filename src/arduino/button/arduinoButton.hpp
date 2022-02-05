#pragma once

#include "../../model/button/button.hpp"

class ArduinoButton: public Button {
private:
    int m_pin;
public:
    ArduinoButton(Listener& listener, int pin);

    void onClickUpdate();
};