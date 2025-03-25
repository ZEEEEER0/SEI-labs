#include "scheduler.h"

#define BUTTON_PIN 7 // Define the button pin
#define LED_PIN 2 // Define the LED pin
#define FLASHING_LED_PIN 1 // Define the flashing LED pin
#define INCREASE_BUTTON_PIN 6 // Define the pin for increasing frequency
#define DECREASE_BUTTON_PIN 5 // Define the pin for decreasing frequency

#define LED_TASK_OFFSET 500
#define LED_TASK_RECURRENCE 500
#define BUTTON_TASK_RECURRENCE 50 // Define the recurrence for button task
#define FLASHING_LED_TASK_RECURRENCE 500 // Define the default recurrence for flashing LED task
#define DEBOUNCE_DELAY 100 // Define the debounce delay in milliseconds

volatile uint8_t led_state = LOW;
unsigned long flashInterval = 500; // Flashing interval in milliseconds

void flashing_led_task(void);
void handleFrequencyButtons(void); // Forward declaration for frequency buttons
void scheduler_setup(void)
{
    timer_init_ISR_1KHz(TIMER_DEFAULT);
    pinMode(LED_PIN, OUTPUT); // Initialize the LED pin as output
    pinMode(FLASHING_LED_PIN, OUTPUT); // Initialize the flashing LED pin as output
    pinMode(BUTTON_PIN, INPUT_PULLUP); // Initialize the button pin with internal pull-up resistor
    pinMode(INCREASE_BUTTON_PIN, INPUT_PULLUP); // Initialize the increase button pin with internal pull-up
    pinMode(DECREASE_BUTTON_PIN, INPUT_PULLUP); // Initialize the decrease button pin with internal pull-up
}

void timer_handle_interrupts(int timer)
{
    static uint32_t ledTaskTimer = LED_TASK_OFFSET;
    static uint32_t buttonTaskTimer = BUTTON_TASK_RECURRENCE;
    static uint32_t flashingLedTaskTimer = FLASHING_LED_TASK_RECURRENCE;

    if (--ledTaskTimer == 0)
    {
        ledTaskTimer = LED_TASK_RECURRENCE;
        led_task();
    }

    if (--buttonTaskTimer == 0)
    {
        buttonTaskTimer = BUTTON_TASK_RECURRENCE;
        button_task();
    }

    if (--flashingLedTaskTimer == 0)
    {
        flashingLedTaskTimer = flashInterval / 2; // Adjust recurrence based on flashInterval
        flashing_led_task();
    }

    handleFrequencyButtons(); // Check the frequency control buttons during each interrupt cycle
}

void led_task(void)
{
    static uint8_t prev_state = LOW;

    if (led_state != prev_state)
    {
        digitalWrite(LED_PIN, led_state);
        prev_state = led_state;
    }   
}

void button_task(void)
{
    static bool lastButtonState = HIGH;
    static unsigned long lastDebounceTime = 0;
    unsigned long currentTime = millis(); // Define currentTime
    bool currentButtonState = digitalRead(BUTTON_PIN);

    if (currentButtonState != lastButtonState) {
        lastDebounceTime = currentTime;
    }

    if ((currentTime - lastDebounceTime) > DEBOUNCE_DELAY) {
        if (currentButtonState == LOW) {
            // Button was pressed
            led_state = !led_state; // Toggle LED state
        }
    }

    lastButtonState = currentButtonState;
}

void flashing_led_task(void)
{
    static bool ledFlashingState = LOW;
    ledFlashingState = !ledFlashingState; // Toggle the flashing LED state
    digitalWrite(FLASHING_LED_PIN, ledFlashingState);
}

void handleFrequencyButtons(void)
{
    static bool lastIncreaseButtonState = HIGH;
    static bool lastDecreaseButtonState = HIGH;
    
    bool currentIncreaseButtonState = digitalRead(INCREASE_BUTTON_PIN);
    bool currentDecreaseButtonState = digitalRead(DECREASE_BUTTON_PIN);

    // Check if the increase button was pressed
    if (lastIncreaseButtonState == HIGH && currentIncreaseButtonState == LOW) {
        if (flashInterval > 200) { // Ensure the interval doesn't get too short
            flashInterval -= 100; // Decrease the interval to increase the frequency
        }
    }

    // Check if the decrease button was pressed
    if (lastDecreaseButtonState == HIGH && currentDecreaseButtonState == LOW) {
        if (flashInterval < 1000) { // Ensure the interval doesn't get too long
            flashInterval += 100; // Increase the interval to decrease the frequency
        }
    }

    lastIncreaseButtonState = currentIncreaseButtonState;
    lastDecreaseButtonState = currentDecreaseButtonState;
}