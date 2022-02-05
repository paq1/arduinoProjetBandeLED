#include "StringServiceImpl.hpp"

#include <Arduino.h>

#include <string.h>
#include <stdlib.h>

/*virtual*/char* StringServiceImpl::copy(const char* chaine) const {
    int size = strlen(chaine);
    char* res = (char*) malloc((size + 1) * sizeof(char));
    for (unsigned int i(0); i < size; i++) {
        res[i] = chaine[i];
    } 
    res[size] = '\0';
    return res;
}

/*virtual*/char* StringServiceImpl::intToString(int number) const {
    return copy(String(number).c_str());
}

/*virtual*/char* StringServiceImpl::concat(const char* chaine1, const char* chaine2) const {
    return copy((String(chaine1) + String(chaine2)).c_str());
}