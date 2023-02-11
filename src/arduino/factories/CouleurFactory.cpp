//
// Created by pierre on 11/02/2023.
//

#include "CouleurFactory.h"

/*static*/CouleurFactory* CouleurFactory::m_instance = nullptr;

CouleurFactory& CouleurFactory::get_instance() {
    if (CouleurFactory::m_instance == nullptr) {
        CouleurFactory::m_instance = new CouleurFactory();
    }
    return *CouleurFactory::m_instance;
}

CouleurFactory::CouleurFactory()
    : m_red(255, 0, 0)
    , m_purple(128,0,128) {}

const Couleur& CouleurFactory::get_red() const {
    return m_red;
}
const Couleur& CouleurFactory::get_purple() const {
    return m_purple;
}