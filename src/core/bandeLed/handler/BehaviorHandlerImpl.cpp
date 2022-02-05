#include "BehaviorHandlerImpl.hpp"

#include <stdlib.h>

BehaviorHandlerImpl::BehaviorHandlerImpl()
: m_behaviors(nullptr)
, m_taille(0)
, m_current(0) {}

/*virtual*/void BehaviorHandlerImpl::swichMode() {
    m_current = (m_current + 1) % m_taille;
}

/*virtual*/LedBehavior* BehaviorHandlerImpl::currentBehavior() {
    return m_taille > 0 ? m_behaviors[m_current] : nullptr;
}

/*virtual*/void BehaviorHandlerImpl::addBehavior(LedBehavior* ledBehavior) {
    if (m_behaviors == nullptr) {
        m_behaviors = (LedBehavior**) malloc (1 * sizeof(LedBehavior*));
        m_behaviors[0] = ledBehavior;
    } else {
        LedBehavior** nouvelleList = 
            (LedBehavior**) malloc ((m_taille + 1) * sizeof(LedBehavior*));

        for (unsigned int i(0); i < m_taille; i++) {
            nouvelleList[i] = m_behaviors[i];
        }
        nouvelleList[m_taille] = ledBehavior;
        delete m_behaviors;
        m_behaviors = nouvelleList;
    }

    m_taille++;
}