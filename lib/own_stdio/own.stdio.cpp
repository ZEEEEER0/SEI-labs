#include "own_stdio.h"

static FILE stream = {0};

static LiquidCrystal lcd(LCD_RS, LCD_RW, LCD_EN, LCD_D0, LCD_D1, LCD_D2, LCD_D3, LCD_D4, LCD_D5, LCD_D6, LCD_D7);
static char key = 0;

static char hexaKeys[KEYPAD_ROWS][KEYPAD_COLS] = 
{
      {'1','2','3','A'},
      {'4','5','6','B'},
      {'7','8','9','C'},
      {'*','0','#','D'}
};

static uint8_t rowPins[KEYPAD_ROWS] = {KEYPAD_ROW_0, KEYPAD_ROW_1, KEYPAD_ROW_2, KEYPAD_ROW_3};
static uint8_t colPins[KEYPAD_COLS] = {KEYPAD_COL_0, KEYPAD_COL_1, KEYPAD_COL_2, KEYPAD_COL_3};

static Keypad KeyPad = Keypad(makeKeymap(hexaKeys), rowPins, colPins, KEYPAD_ROWS, KEYPAD_COLS);

int own_lcd_putchar(char ch, FILE *stream)
{
  if (ch == '\f')
  {
    lcd.clear();
    lcd.setCursor(0, 0);
    return 0;
  }
  if (ch == '\n')
  {
    lcd.setCursor(0, 1);
    return 0;
  }
  lcd.write(ch);
  return 0;
}

int own_keypad_getchar(FILE *stream)
{
  while (key == NO_KEY ) 
  {
    key = KeyPad.getKey();
  }
    if (key == '#')
  {
    key = '\n';
  }
 return key;
}

uint8_t keypadGetState(void)
{
  key = KeyPad.getKey();

  if (key == NO_KEY)
  {
    return 0;
  }
  else
  {
    return 1;
  }
}

void own_stdio_setup()
{
  Serial.begin(BAUDRATE);

  lcd.begin(LCD_COLS, LCD_ROWS);

  lcd.clear();

  fdev_setup_stream(&stream, own_lcd_putchar, own_keypad_getchar, _FDEV_SETUP_RW);
  stdin = stdout = &stream;
}