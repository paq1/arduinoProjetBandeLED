#pragma once

#include "../../core/bandeLed/BandeLedService.hpp"

#include <Adafruit_NeoPixel.h>

class BandeLedServiceArduino: public BandeLedService {
private:
    Adafruit_NeoPixel& m_pixels;
    unsigned int m_nbPixels;
public:
    BandeLedServiceArduino(Adafruit_NeoPixel& pixels, unsigned int nbPixels);
    virtual void setColorAt(const Couleur& couleur, int index);
    virtual void cleanAt(int index);
    virtual void cleanAll();
    virtual void show();
};