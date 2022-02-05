#pragma once

#include "../string/StringService.hpp"

class LedBehavior {
private:
    char* m_name;
public:
    LedBehavior(const StringService& stringService, const char* name);
    virtual ~LedBehavior() {
        delete m_name;
    }
    virtual void action(double dt) = 0;

    const char* getName() const { return m_name; }
};