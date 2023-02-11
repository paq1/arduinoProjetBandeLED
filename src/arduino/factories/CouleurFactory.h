//
// Created by pierre on 11/02/2023.
//

#ifndef ARDUINOPROJETBANDELED_COULEURFACTORY_H
#define ARDUINOPROJETBANDELED_COULEURFACTORY_H

#include "../../model/couleur/couleur.hpp"


class CouleurFactory {
public:
    static CouleurFactory& get_instance();
    CouleurFactory();

    const Couleur& get_red() const;
    const Couleur& get_purple() const;

private:
    static CouleurFactory* m_instance;
    Couleur m_red, m_purple;
};


#endif //ARDUINOPROJETBANDELED_COULEURFACTORY_H
