#pragma once

#include "../LedBehavior.hpp"

class BehaviorHandler {
public:
    virtual ~BehaviorHandler() {}
    virtual void swichMode() = 0;
    virtual LedBehavior* currentBehavior() = 0;
    virtual void addBehavior(LedBehavior* ledBehavior) = 0;
    virtual void update(double dt) = 0;
};