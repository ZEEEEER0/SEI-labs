#include <main.h>
#include "timer-api.h"

#define BUTTON_PIN 7 
#define LED_PIN 2 
#define FLASHING_LED_PIN 1 
#define INCREASE_BUTTON_PIN 6 
#define DECREASE_BUTTON_PIN 5 

unsigned long flashInterval = 500; // Flashing interval in milliseconds

void handleButtonPress(void); // Forward declaration
void handleFlashingLED(void); 
void handleFrequencyButtons(void); 

void setup(void) {
    timer_init_ISR_1KHz(TIMER_DEFAULT);

    pinMode(LED_PIN, OUTPUT);
    pinMode(FLASHING_LED_PIN, OUTPUT);
    pinMode(BUTTON_PIN, INPUT_PULLUP); // Initialize the button pin with internal pull-up resistor
    pinMode(INCREASE_BUTTON_PIN, INPUT_PULLUP); 
    pinMode(DECREASE_BUTTON_PIN, INPUT_PULLUP);  
}

void loop(void) 
{
    handleButtonPress(); // Check for button press in the loop
    handleFlashingLED(); 
    handleFrequencyButtons(); 
}

void handleButtonPress(void) 
{
    static bool lastButtonState = HIGH;
    bool currentButtonState = digitalRead(BUTTON_PIN);

    if (lastButtonState == HIGH && currentButtonState == LOW) {
        // Button was pressed
        digitalWrite(LED_PIN, !digitalRead(LED_PIN)); // Toggle LED state
    }

    lastButtonState = currentButtonState;
}

void handleFlashingLED(void) 
{
    static unsigned long lastFlashTime = 0;
    unsigned long currentTime = millis();

    if (digitalRead(LED_PIN) == LOW) {
        // LED on pin 2 is off, flash the LED on pin 1
        if (currentTime - lastFlashTime >= flashInterval) { // Use flashInterval for the flashing interval
            digitalWrite(FLASHING_LED_PIN, !digitalRead(FLASHING_LED_PIN)); // Toggle flashing LED state
            lastFlashTime = currentTime;
        }
    } else {
        // LED on pin 2 is on, turn off the flashing LED
        digitalWrite(FLASHING_LED_PIN, LOW);
    }
}

void handleFrequencyButtons(void) 
{
    static bool lastIncreaseButtonState = HIGH;
    static bool lastDecreaseButtonState = HIGH;
    
    bool currentIncreaseButtonState = digitalRead(INCREASE_BUTTON_PIN);
    bool currentDecreaseButtonState = digitalRead(DECREASE_BUTTON_PIN);

    if (lastIncreaseButtonState == HIGH && currentIncreaseButtonState == LOW) {
        if (flashInterval > 200) { // Ensure the interval doesn't get too short
            flashInterval -= 100; // Decrease the interval to increase the frequency
        }
    }

    if (lastDecreaseButtonState == HIGH && currentDecreaseButtonState == LOW) {
        if (flashInterval < 1000) { // Ensure the interval doesn't get too long
            flashInterval += 100; // Increase the interval to decrease the frequency
        }
    }

    lastIncreaseButtonState = currentIncreaseButtonState;
    lastDecreaseButtonState = currentDecreaseButtonState;
}

void timer_handle_interrupts(int timer) 
{
    // No need for LED task timer logic
}