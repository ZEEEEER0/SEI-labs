#include <Arduino.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <config.h>

// Dimensiuni OLED
#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 32
#define OLED_RESET    -1

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

void lcd_init(void) {
    if (!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) { // Adresa uzuală 0x3C
        // Eroare inițializare
        for (;;);
    }
    display.clearDisplay();
    display.setTextSize(2);
    display.setTextColor(SSD1306_WHITE);
    display.setCursor(0, 0);
    display.print("6.1");
    display.display();
    delay(500);
    display.clearDisplay();
    display.display();
}

void lcd_show_state(const char* state) {
    display.clearDisplay();
    display.setTextSize(2);
    display.setTextColor(SSD1306_WHITE);
    display.setCursor(0, 0);
    display.print(state);
    display.display();
}
