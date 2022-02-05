#include "LedBehavior.hpp"

LedBehavior::LedBehavior(const StringService& stringService, const char* name)
: m_name(stringService.copy(name)) {}