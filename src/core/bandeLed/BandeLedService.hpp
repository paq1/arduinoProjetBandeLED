#pragma once

#include "../../model/couleur/couleur.hpp"

class BandeLedService {
public:
    virtual ~BandeLedService() {}
    virtual void setColorAt(const Couleur& couleur, int index) = 0;
    virtual void cleanAt(int index) = 0;
    virtual void cleanAll() = 0;
    virtual void show() = 0;
};