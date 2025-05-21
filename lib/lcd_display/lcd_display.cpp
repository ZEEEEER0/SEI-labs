#include <config.h>
#include <Arduino.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);

void lcd_init(void) {
    lcd.init();
    lcd.backlight();
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Semafor");
    delay(500);
    lcd.clear();
}

void lcd_show_state(const char* state) {
    // Împarte textul în două linii la '\n'
    char line1[17] = {0};
    char line2[17] = {0};
    const char* nl_ptr = strchr(state, '\n');
    if (nl_ptr) {
        size_t len1 = nl_ptr - state;
        if (len1 > 16) len1 = 16;
        strncpy(line1, state, len1);
        line1[len1] = '\0';
        strncpy(line2, nl_ptr + 1, 16);
        line2[16] = '\0';
    } else {
        strncpy(line1, state, 16);
        line1[16] = '\0';
        line2[0] = '\0';
    }
    // Completează cu spații până la 16 caractere
    for (size_t i = strlen(line1); i < 16; ++i) line1[i] = ' ';
    line1[16] = '\0';
    for (size_t i = strlen(line2); i < 16; ++i) line2[i] = ' ';
    line2[16] = '\0';

    lcd.setCursor(0, 0);
    lcd.print(line1);
    lcd.setCursor(0, 1);
    lcd.print(line2);
}
