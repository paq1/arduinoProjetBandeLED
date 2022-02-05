#pragma once

#include "../../core/bandeLed/LedBehavior.hpp"
#include "../../core/bandeLed/BandeLedService.hpp"
#include "../../core/string/StringService.hpp"

class AllerRetourBehavior: public LedBehavior {
private:
    BandeLedService& m_bandeLedService;
    int m_taille;
    double m_timer;
    int m_current_index;
    bool m_sens;
    double m_dureeAnimation;
public:
    AllerRetourBehavior(
        StringService& stringService,
        BandeLedService& bandeLedService, 
        int taille, 
        double dureeAnimation
    );
    
    virtual void action(double dt);
};