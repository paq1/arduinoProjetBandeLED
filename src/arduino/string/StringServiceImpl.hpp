#pragma once

#include "../../core/string/StringService.hpp"

class StringServiceImpl: public StringService {
public:
    virtual char* copy(const char* chaine) const;
    virtual char* intToString(int number) const;
    virtual char* concat(const char* chaine1, const char* chaine2) const;
private:

};