#include <LiquidCrystal.h>

#include "src/arduino/ecran/EcranServiceLiquid.hpp"
#include "src/arduino/button/arduinoButton.hpp"
#include "src/arduino/button/onSwitchModeListener.hpp"
#include "src/arduino/bandeLED/BandeLedServiceArduino.hpp"
#include "src/arduino/bandeLED/AllerRetourBehavior.hpp"
#include "src/arduino/bandeLED/OneByOneBehavior.hpp"
#include "src/arduino/string/StringServiceImpl.hpp"
#include "src/core/bandeLed/handler/BehaviorHandlerImpl.hpp"
#include "src/arduino/time/TimeServiceImpl.hpp"

#define PIN 8   // input pin Neopixel is attached to
#define NUMPIXELS      150 // number of neopixels in strip
#define PIN_BTN 7

Adafruit_NeoPixel pixels = Adafruit_NeoPixel(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);

// initialize the library with the numbers of the interface pins
ArduinoButton* buttonSwitchMode;
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

// services
StringServiceImpl stringService;
TimeServiceImpl timeService;
BandeLedServiceArduino bandeLedServiceArduino(pixels, NUMPIXELS);
EcranServiceLiquid ecranServiceLiquid(lcd);

// behaviors
AllerRetourBehavior allerRetourBehavior(stringService, bandeLedServiceArduino, NUMPIXELS, 0.03);
OneByOneBehavior oneByOneBehavior(stringService, bandeLedServiceArduino, NUMPIXELS, 0.03);

BehaviorHandlerImpl behaviorHandler(ecranServiceLiquid, stringService, timeService);
OnSwitchModeListener onSwitchModeListener(ecranServiceLiquid, behaviorHandler, bandeLedServiceArduino);

void setup() {
  buttonSwitchMode = new ArduinoButton(onSwitchModeListener, PIN_BTN);
  behaviorHandler.addBehavior(&allerRetourBehavior);
  behaviorHandler.addBehavior(&oneByOneBehavior);
  // Initialize the NeoPixel library.
  pixels.begin();
}

void loop() {
  // calcul du dt
  timeService.update();
  // met a jour l'action du click du bouton
  buttonSwitchMode->onClickUpdate();
  // met a jour la bande LED
  behaviorHandler.update(timeService.getDt());
  delay(10);
}