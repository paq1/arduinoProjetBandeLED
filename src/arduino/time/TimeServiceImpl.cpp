#include "TimeServiceImpl.hpp"

#include <Arduino.h>

TimeServiceImpl::TimeServiceImpl() 
: m_oldTime(0.0)
, m_newTime(0.0) 
, m_dt(0.0)
, m_time(0.0) {}

/*virtual*/void TimeServiceImpl::update() {
    m_newTime = millis() / 1000.0;
    m_dt = m_newTime - m_oldTime;
    m_oldTime = m_newTime;
    m_time += m_dt;
}

/*virtual*/double TimeServiceImpl::getDt() const {
    return m_dt;
}

/*virtual*/double TimeServiceImpl::getTimeSecond() const {
    return m_time;
}