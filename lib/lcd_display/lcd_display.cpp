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
    display.setTextSize(1);
    display.setTextColor(SSD1306_WHITE);
    display.setCursor(0, 0);
    display.println("OLED OK");
    display.display();
    delay(500);
    display.clearDisplay();
    display.display();
}

void lcd_update_display(uint16_t setPoint, uint16_t humidity, uint16_t output) {
    display.clearDisplay();
    display.setCursor(0, 0);
    display.print("SP:");
    display.print(setPoint);
    display.print(" H:");
    display.print(humidity);

    display.setCursor(0, 16);
    display.print("PWM:");
    display.print(output);

    display.display();
}
