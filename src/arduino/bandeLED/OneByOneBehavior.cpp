#include "OneByOneBehavior.hpp"

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
, m_dureeAnimation(dureeAnimation) {}

/*virtual*/void OneByOneBehavior::action(
    double dt
) {
    m_timer += dt;
    if (m_timer > m_dureeAnimation) {
        m_timer = 0;

        // on eteint le pixel
        m_bandeLedService.cleanAt(m_current_index);

        // on incremente le pixel courant

        if (m_sens && m_current_index < m_taille - 1) m_current_index++;
        if (!m_sens && m_current_index > 0) m_current_index--;

        if (m_current_index >= m_taille - 1 && m_sens) {
            m_sens = !m_sens;
        }

        if (m_current_index == 0 && !m_sens) {
            m_sens = !m_sens;
        }

        // on allume le pixel
        m_bandeLedService.setColorAt(Couleur(0, 255, 0), m_current_index);
        m_bandeLedService.show();
    }

    
}