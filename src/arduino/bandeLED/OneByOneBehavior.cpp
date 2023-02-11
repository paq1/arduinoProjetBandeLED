#include "OneByOneBehavior.hpp"

#include "../factories/CouleurFactory.h"

OneByOneBehavior::OneByOneBehavior(
    StringService& stringService,
    BandeLedService& bandeLedService, 
    int taille, 
    double dureeAnimation
)
: LedBehavior(stringService, "one-by-one")
, m_bandeLedService(bandeLedService)
, m_taille(taille)
, m_timer(0.0)
, m_current_index(0)
, m_sens(true)
, m_dureeAnimation(dureeAnimation)
, m_nb_allume(0) {}

/*virtual*/void OneByOneBehavior::action(
    double dt
) {
    update(dt);
}

void OneByOneBehavior::update(double dt) {
    m_timer += dt;
    if (m_timer > m_dureeAnimation) {
        m_timer = 0;
        // on allume jusqu'au m_taille - 1 - m_nbAllume (et on laisse la dernière allumé)
        const int lastId = m_taille - m_nb_allume - 1;
        if (m_current_index < lastId - 1) {
            // on allume la suivante
            m_current_index++;
            m_bandeLedService.setColorAt(CouleurFactory::get_instance().get_purple(), m_current_index);
            // on eteind la precedente
            m_bandeLedService.cleanAt(m_current_index - 1);
            if (m_current_index == lastId - 1) {
                m_nb_allume++;
                m_current_index = 0;
            }
        } else {
            m_bandeLedService.cleanAll();
            m_current_index = 0;
            m_nb_allume = 0;
        }
        m_bandeLedService.show();
    }
}