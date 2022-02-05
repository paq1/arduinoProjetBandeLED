#pragma once

#include "../../core/bandeLed/BandeLedService.hpp"

#include <Adafruit_NeoPixel.h>

class BandeLedServiceArduino: public BandeLedService {
private:
    Adafruit_NeoPixel& m_pixels;
public:
    BandeLedServiceArduino(Adafruit_NeoPixel& pixels);
    virtual void setColorAt(const Couleur& couleur, int index);
    virtual void cleanAt(int index);
    virtual void show();
};