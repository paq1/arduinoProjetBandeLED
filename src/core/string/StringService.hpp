#pragma once

class StringService {
public:
    virtual ~StringService() {}
    virtual char* copy(const char* chaine) const = 0;
    virtual char* intToString(int number) const = 0;
    virtual char* concat(const char* chaine1, const char* chaine2) const = 0;
};