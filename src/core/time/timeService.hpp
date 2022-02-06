#pragma once

class TimeService {
public:
    virtual ~TimeService() {}

    virtual void update() = 0;
    virtual double getDt() const = 0;
    virtual double getTimeSecond() const = 0;
};