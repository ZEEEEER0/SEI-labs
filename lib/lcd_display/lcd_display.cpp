#include <config.h>
#include <Arduino.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

// OLED setup
Adafruit_SSD1306 display(OLED_WIDTH, OLED_HEIGHT, &Wire, -1);

void lcd_init(void) {
    if (!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) { // 0x3C este adresa standard
        for (;;); // Blochează dacă nu găsește display-ul
    }
    display.clearDisplay();
    display.setTextSize(2);
    display.setTextColor(SSD1306_WHITE);
    display.setCursor(0, 0);
    display.println("FSM LED");
    display.display();
    delay(500);
    display.clearDisplay();
    display.display();
}

void lcd_show_state(const char* state) {
    display.clearDisplay();
    display.setTextSize(2);
    display.setCursor(0, 0);
    display.print("LED: ");
    display.println(state);
    display.display();
}
