#pragma once

#include "../../core/time/timeService.hpp"

class TimeServiceImpl: public TimeService {
private:
    double m_oldTime;
    double m_newTime;
    double m_dt;
    double m_time;
public:
    TimeServiceImpl();

    virtual void update();
    virtual double getDt() const;
    virtual double getTimeSecond() const;
};