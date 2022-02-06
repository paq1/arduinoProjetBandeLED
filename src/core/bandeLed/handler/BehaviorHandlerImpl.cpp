#include "BehaviorHandlerImpl.hpp"

#include <stdlib.h>

BehaviorHandlerImpl::BehaviorHandlerImpl(EcranService& ecranService, StringService& stringService, TimeService& timeService)
: m_behaviors(nullptr)
, m_taille(0)
, m_current(0)
, m_ecranService(ecranService)
, m_stringService(stringService)
, m_timeService(timeService) {}

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

/*virtual*/void BehaviorHandlerImpl::update(double dt) {
    currentBehavior()->action(dt);
    afficheInfos();
}

void BehaviorHandlerImpl::afficheInfos() {
    m_ecranService.afficheMessage(currentBehavior()->getName(), 0);
    // on affiche le temps d'execution en seconde
    // TODO Ajouter le temps
    char * str_temps = m_stringService.intToString((int) m_timeService.getTimeSecond());
    char * message = m_stringService.concat("time : ", str_temps);
    char * message_avec_unites = m_stringService.concat(message, " sec");
    m_ecranService.afficheMessage(message_avec_unites, 1);

    // on supprime le message de la memoire
    delete str_temps;
    delete message;
    delete message_avec_unites;
}