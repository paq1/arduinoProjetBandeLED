#include "onSwitchModeListener.hpp"

#include <Arduino.h>

OnSwitchModeListener::OnSwitchModeListener(
    EcranService& ecranService, 
    BehaviorHandler& behaviorHandler,
    BandeLedService& bandeLedService
)
: m_ecranService(ecranService)
, m_behaviorHandler(behaviorHandler)
, m_bandeLedService(bandeLedService) {}
    
/*virtual*/void OnSwitchModeListener::action() {
    // on efface le message d'avant (TODO ameliorer ca)
    m_ecranService.afficheMessage("                ", 0);
    // on efface la bande led
    m_bandeLedService.cleanAll();
    // on passe au mode suivant
    m_behaviorHandler.swichMode();
}