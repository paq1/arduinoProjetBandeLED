#pragma once

class Listener {
public:
    virtual ~Listener() {}
    virtual void action() = 0;
};