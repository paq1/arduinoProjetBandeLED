#pragma once

#include "../../model/button/listener.hpp"
#include "../../core/ecran/EcranService.hpp"
#include "../../core/bandeLed/handler/BehaviorHandler.hpp"
#include "../../core/bandeLed/BandeLedService.hpp"

class OnSwitchModeListener: public Listener {
private:
    EcranService& m_ecranService;
    BehaviorHandler& m_behaviorHandler;
    BandeLedService& m_bandeLedService;
public:
    OnSwitchModeListener(
        EcranService& ecranService, 
        BehaviorHandler& behaviorHandler,
        BandeLedService& bandeLedService
    );
    virtual void action();
};