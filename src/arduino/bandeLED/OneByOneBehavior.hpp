#pragma once

#include "../../core/bandeLed/LedBehavior.hpp"
#include "../../core/bandeLed/BandeLedService.hpp"
#include "../../core/string/StringService.hpp"

class OneByOneBehavior: public LedBehavior {
private:
    BandeLedService& m_bandeLedService;
    int m_taille;
    double m_timer;
    int m_current_index;
    bool m_sens;
    double m_dureeAnimation;
    int m_nb_allume;
public:
    OneByOneBehavior(
        StringService& stringService,
        BandeLedService& bandeLedService, 
        int taille, 
        double dureeAnimation
    );
    
    virtual void action(double dt);
private:
    void update(double dt);
};