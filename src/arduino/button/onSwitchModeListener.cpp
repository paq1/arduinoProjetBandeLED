#include "onSwitchModeListener.hpp"

#include <Arduino.h>

OnSwitchModeListener::OnSwitchModeListener(
    EcranService& ecranService, 
    BehaviorHandler& behaviorHandler
)
: m_ecranService(ecranService)
, m_behaviorHandler(behaviorHandler) {}
    
/*virtual*/void OnSwitchModeListener::action() {
    // on efface le message d'avant (TODO ameliorer ca)
    m_ecranService.afficheMessage("                ", 0);
    m_behaviorHandler.swichMode();
}