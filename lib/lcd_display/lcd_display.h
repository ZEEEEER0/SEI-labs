#ifndef LCD_DISPLAY_H
#define LCD_DISPLAY_H

#include <stdint.h>

void lcd_init(void);
void lcd_update_display(uint16_t setPoint, uint16_t currentPosition);

#endif // LCD_DISPLAY_H
