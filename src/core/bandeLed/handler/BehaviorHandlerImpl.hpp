#pragma once

#include "BehaviorHandler.hpp"

class BehaviorHandlerImpl: public BehaviorHandler {
private:
    LedBehavior** m_behaviors;
    int m_taille;
    int m_current;
public:
    BehaviorHandlerImpl();

    virtual ~BehaviorHandlerImpl() {
        for (unsigned int i(0); i < m_taille; i++) {
            delete m_behaviors[i];
        }
        delete m_behaviors;
    }

    virtual void swichMode();
    virtual LedBehavior* currentBehavior();
    virtual void addBehavior(LedBehavior* ledBehavior);

private:
    LedBehavior** createBehaviorsEmpty();
};