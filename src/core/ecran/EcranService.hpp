#pragma once

class EcranService {
    public:
        virtual ~EcranService() {}
        virtual void afficheMessage(
            const char* chaine, 
            const int lineNumber
        ) = 0;
};