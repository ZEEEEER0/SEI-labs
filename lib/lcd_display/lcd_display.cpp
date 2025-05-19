#include <LiquidCrystal_I2C.h>
#include <config.h>

// LCD setup
LiquidCrystal_I2C lcd(LCD_I2C_ADDRESS, LCD_COLUMNS, LCD_ROWS);

void lcd_init(void) {
    lcd.init(); // Inițializează LCD-ul
    lcd.backlight(); // Activează iluminarea de fundal
    lcd.clear(); // Șterge ecranul
}

void lcd_update_display(uint16_t setPoint, uint16_t currentPosition, uint16_t output) {
    lcd.setCursor(0, 0);
    lcd.print("SP:");
    lcd.print(setPoint);
    lcd.print(" H:");
    lcd.print(currentPosition);

    lcd.setCursor(0, 1);
    lcd.print("PWM:");
    lcd.print(output);
    lcd.print("   "); // pentru a șterge caractere vechi dacă scade PWM
}
