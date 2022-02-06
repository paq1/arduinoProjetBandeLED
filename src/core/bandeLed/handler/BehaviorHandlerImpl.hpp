#pragma once

#include "BehaviorHandler.hpp"
#include "../../ecran/EcranService.hpp"
#include "../../string/StringService.hpp"
#include "../../time/timeService.hpp"

class BehaviorHandlerImpl: public BehaviorHandler {
private:
    LedBehavior** m_behaviors;
    int m_taille;
    int m_current;

    EcranService& m_ecranService;
    StringService& m_stringService;
    TimeService& m_timeService;
public:
    BehaviorHandlerImpl(EcranService& ecranService, StringService& stringService, TimeService& timeService);

    virtual ~BehaviorHandlerImpl() {
        for (unsigned int i(0); i < m_taille; i++) {
            delete m_behaviors[i];
        }
        delete m_behaviors;
    }

    virtual void swichMode();
    virtual LedBehavior* currentBehavior();
    virtual void addBehavior(LedBehavior* ledBehavior);
    virtual void update(double dt);

private:
    void afficheInfos();
};