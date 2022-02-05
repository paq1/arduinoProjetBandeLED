#include "EcranServiceLiquid.hpp"

EcranServiceLiquid::EcranServiceLiquid(LiquidCrystal& lcd): m_lcd(lcd) {
    m_lcd.begin(16, 2);
}

void EcranServiceLiquid::afficheMessage(
    const char* message, 
    const int lineNumber
) {
    m_lcd.setCursor(0, lineNumber);
    m_lcd.print(message);
}