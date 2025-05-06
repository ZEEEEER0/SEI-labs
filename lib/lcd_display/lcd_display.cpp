#include <LiquidCrystal_I2C.h>
#include <config.h>

// LCD setup
LiquidCrystal_I2C lcd(LCD_I2C_ADDRESS, LCD_COLUMNS, LCD_ROWS);

void lcd_init(void) {
    lcd.init();
    lcd.backlight();
    lcd.setCursor(0, 0);
    lcd.print("SetPoint:");
    lcd.setCursor(0, 1);
    lcd.print("Current:");
}

void lcd_update_display(uint16_t setPoint, uint16_t currentPosition) {
    lcd.setCursor(10, 0);
    lcd.print(setPoint);
    lcd.setCursor(10, 1);
    lcd.print(currentPosition);
}
