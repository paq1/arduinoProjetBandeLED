#include "BandeLedServiceArduino.hpp"

BandeLedServiceArduino::BandeLedServiceArduino(
    Adafruit_NeoPixel& pixels, 
    unsigned int nbPixels)
: m_pixels(pixels)
, m_nbPixels(nbPixels) {
    pixels.begin();
}

/*virtual*/void BandeLedServiceArduino::setColorAt(
    const Couleur& couleur, 
    int index
) {
    int r(couleur.getR()), g(couleur.getG()), b(couleur.getB());
    m_pixels.setPixelColor(index, m_pixels.Color(r,g,b));
}

/*virtual*/void BandeLedServiceArduino::cleanAt(
    int index
) {
    m_pixels.setPixelColor(index, m_pixels.Color(0,0,0));
}

/*virtual*/void BandeLedServiceArduino::cleanAll() {
    for (unsigned int i(0); i < m_nbPixels; i++) {
        cleanAt(i);
    }
}

/*virtual*/void BandeLedServiceArduino::show() {
    m_pixels.show();
}