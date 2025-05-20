#include <Arduino.h>
#include <LiquidCrystal_I2C.h>
#include <config.h>

// Setează adresa LCD-ului (0x27 sau 0x3F, după modulul tău)
#define LCD_ADDR 0x27
#define LCD_COLS 16
#define LCD_ROWS 2

LiquidCrystal_I2C lcd(LCD_ADDR, LCD_COLS, LCD_ROWS);

void lcd_init(void) {
    lcd.init();
    lcd.backlight();
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Semafor");
    delay(500);
    lcd.clear();
}

// state trebuie să fie de forma "E:VERDE N:ROSU" etc.
void lcd_show_state(const char* state) {
    lcd.clear();
    lcd.setCursor(0, 0);
    // Caută poziția "N:" ca să spargi stringul pe linii
    const char* n_ptr = strstr(state, "N:");
    if (n_ptr) {
        // Scrie E:... pe prima linie
        char buf[17] = {0};
        size_t len = n_ptr - state;
        if (len > 16) len = 16;
        strncpy(buf, state, len);
        lcd.print(buf);
        // Scrie N:... pe a doua linie
        lcd.setCursor(0, 1);
        lcd.print(n_ptr);
    } else {
        // Dacă nu găsește N:, scrie tot pe prima linie
        lcd.print(state);
    }
}
