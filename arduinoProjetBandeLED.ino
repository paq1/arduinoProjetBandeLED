#include <LiquidCrystal.h>

#include "src/arduino/ecran/EcranServiceLiquid.hpp"
#include "src/arduino/button/arduinoButton.hpp"
#include "src/arduino/button/onSwitchModeListener.hpp"
#include "src/arduino/bandeLED/BandeLedServiceArduino.hpp"
#include "src/arduino/bandeLED/AllerRetourBehavior.hpp"
#include "src/arduino/bandeLED/OneByOneBehavior.hpp"
#include "src/arduino/string/StringServiceImpl.hpp"
#include "src/core/bandeLed/handler/BehaviorHandlerImpl.hpp"

#define PIN 8   // input pin Neopixel is attached to
#define NUMPIXELS      150 // number of neopixels in strip
#define PIN_BTN 7

Adafruit_NeoPixel pixels = Adafruit_NeoPixel(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);

// initialize the library with the numbers of the interface pins
ArduinoButton* buttonSwitchMode;
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
int buttonState = 0;

// time
double oldTime = 0.0;
double newTime = 0.0;
double dt = 0.0;
double time = 0;

// services
StringServiceImpl stringService;
BandeLedServiceArduino bandeLedServiceArduino(pixels);
EcranServiceLiquid ecranServiceLiquid(lcd);

// behaviors
AllerRetourBehavior allerRetourBehavior(
  stringService,
  bandeLedServiceArduino,
  NUMPIXELS, 
  0.03
);
OneByOneBehavior oneByOneBehavior(
  stringService,
  bandeLedServiceArduino,
  NUMPIXELS, 
  0.03
);

BehaviorHandlerImpl behaviorHandler;
OnSwitchModeListener onSwitchModeListener(ecranServiceLiquid, behaviorHandler);

void setup() {
  buttonSwitchMode = new ArduinoButton(onSwitchModeListener, PIN_BTN);
  behaviorHandler.addBehavior(&allerRetourBehavior);
  behaviorHandler.addBehavior(&oneByOneBehavior);
  pinMode(LED_BUILTIN, OUTPUT);
  // Initialize the NeoPixel library.
  pixels.begin();
  
  // Print a message to the LCD.
}

void loop() {
  // calcul du dt
  updateDt();

  // met a jour l'action du click du bouton
  buttonSwitchMode->onClickUpdate();

  // met a jour la bande LED
  behaviorHandler.currentBehavior()->action(dt);
  
  affichageInfos();

  delay(10);
}


/////////////////////////////////////////////////////////////////////////////////////

void updateDt() {
  newTime = millis()/1000.0;
  dt = newTime - oldTime;
  oldTime = newTime;
  time += dt;
}

void affichageInfos() {
  ecranServiceLiquid.afficheMessage(behaviorHandler.currentBehavior()->getName(), 0);
  // on affiche le temps d'execution en seconde
  char * str_temps = stringService.intToString((int) time);
  char * message = stringService.concat("time : ", str_temps);
  char * message_avec_unites = stringService.concat(message, " sec");
  ecranServiceLiquid.afficheMessage(message_avec_unites, 1);
  
  // on supprime le message de la memoire
  delete str_temps;
  delete message;
  delete message_avec_unites;
}
