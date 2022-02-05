#include "../../core/ecran/EcranService.hpp"

#include <LiquidCrystal.h>

class EcranServiceLiquid: public EcranService {

    private:
        LiquidCrystal& m_lcd;
    public:

        EcranServiceLiquid(LiquidCrystal& lcd);
            

        virtual void afficheMessage(
            const char* chaine, 
            const int lineNumber = 0
        );
};