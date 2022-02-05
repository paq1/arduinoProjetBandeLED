#pragma once

#include "../../model/button/listener.hpp"

#include "../../core/ecran/EcranService.hpp"

#include "../../core/bandeLed/handler/BehaviorHandler.hpp"

class OnSwitchModeListener: public Listener {
private:
    EcranService& m_ecranService;
    BehaviorHandler& m_behaviorHandler;
public:
    OnSwitchModeListener(
        EcranService& ecranService, 
        BehaviorHandler& behaviorHandler
    );
    virtual void action();
};