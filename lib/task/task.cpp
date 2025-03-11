#include "task.h"


static volatile uint32_t blinkFrequency;
static volatile uint32_t blinkLedTaskCounter = BLINK_LED_TASK_OFFSET;

void buttonLedTaskSetup(void)
{
    pinMode(BUTTON_PIN, INPUT_PULLUP);
    pinMode(LED_GREEN_PIN, OUTPUT);
}

void buttonLedTask(void)
{
    static uint8_t needInit = true;
    static uint32_t debounceTime = 0;

    if (needInit)
    {
        buttonLedTaskSetup();
        needInit = false;
    }

    if (digitalRead(BUTTON_PIN) == LOW)
    {
        if (millis() - debounceTime > 50) // assuming 50ms debounce interval
        {
            digitalWrite(LED_GREEN_PIN, !digitalRead(LED_GREEN_PIN));
            debounceTime = millis();
        }
    }
    else
    {
        debounceTime = millis();
    }
}

void setBlinkFrequencyTaskSetup(void)
{
    blinkFrequency = DEFAULT_BLINK_FREQUENCY;

    pinMode(BUTTON_UP_PIN, INPUT_PULLUP);
    pinMode(BUTTON_DOWN_PIN, INPUT_PULLUP);
}

void setBlinkFrequency(void)
{
    static uint8_t needInit = true;
    static uint32_t debounceTime = 0;

    if (needInit)
    {
        setBlinkFrequencyTaskSetup();
        needInit = false;
    }

    if (digitalRead(BUTTON_UP_PIN) == LOW)
    {
        if (millis() - debounceTime > 50) // assuming 50ms debounce interval
        {
            if (blinkFrequency < MAXIMUM_BLINK_FREQUENCY)
            {
                blinkFrequency++;
            }
            debounceTime = millis();
        }
    }
    else if (digitalRead(BUTTON_DOWN_PIN) == LOW)
    {
        if (millis() - debounceTime > 50) // assuming 50ms debounce interval
        {
            if (blinkFrequency > MINIMUM_BLINK_FREQUENCY)
            {
                blinkFrequency--;
            }
            debounceTime = millis();
        }
    }
    else
    {
        debounceTime = millis();
    }
}

void setBlindFrequency(void)
{
    static uint32_t setBlinkFrequencyTaskCounter = SET_BLINK_FREQUENCY_TASK_OFFSET;

    if (--setBlinkFrequencyTaskCounter == 0)
    {
        setBlinkFrequency();
        setBlinkFrequencyTaskCounter = SET_BLINK_FREQUENCY_TASK_RECURRENCE;
void idleTaskSetup(void)
{
    // Initialize standard I/O
    own_stdio_setup();
}
{
    own_stdio_setup();
}}}

void idleTask(void)
{
    static uint8_t needInit = true;
    static uint32_t nextTime = 0;

    if (needInit)
    {
        idleTaskSetup();
        needInit = false;
    }

    if (millis() >= nextTime)
    {
        printf("Blink frequency: %d\n", blinkFrequency);
        printf("Green LED state: %d\n", digitalRead(LED_GREEN_PIN));
        nextTime = millis() + DATA_REFRESH;
    }
}