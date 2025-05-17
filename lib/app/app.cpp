#include <Arduino.h>
#include <config.h>
#include <motor_control.h>
#include <lcd_display.h>
#include <sensor.h>
#include <pid_control.h>
#include <DHT.h>
#include <own_stdio.h>

// Variabile globale
static uint16_t setPoint = 512; // Valoarea implicită

// PID control instance
pid_control_t pid_control;

// DHT sensor setup
#define DHTPIN 2 // Pinul conectat la DHT22
#define DHTTYPE DHT22
DHT dht(DHTPIN, DHTTYPE);

// PWM pin for fan control
#define FAN_PWM_PIN 3

void buttons_init() {
    pinMode(BUTTON_INC_PIN, INPUT_PULLUP);
    pinMode(BUTTON_DEC_PIN, INPUT_PULLUP);
    pinMode(BUTTON_RESET_PIN, INPUT_PULLUP);
}

void buttons_process_input(uint16_t *setPoint, uint16_t min, uint16_t max) {
    if (digitalRead(BUTTON_INC_PIN) == LOW) {
        *setPoint = (*setPoint < max) ? (*setPoint + 1) : max;
        delay(200); // Debounce delay
    }
    if (digitalRead(BUTTON_DEC_PIN) == LOW) {
        *setPoint = (*setPoint > min) ? (*setPoint - 1) : min;
        delay(200); // Debounce delay
    }
    if (digitalRead(BUTTON_RESET_PIN) == LOW) {
        *setPoint = min; // Reset la valoarea minimă
        delay(200); // Debounce delay
    }
}

void app_setup() {
    Serial.begin(BAUD_RATE);
    motor_init();
    lcd_init(); // Inițializează LCD-ul
    buttons_init(); // Inițializează butoanele

    // Initialize DHT sensor
    dht.begin();

    // Initialize PID controller
    pid_control_init(&pid_control, PID_KP, PID_KI, PID_KD);
    pid_control_set_setpoint(&pid_control, HUMIDITY_SETPOINT_DEFAULT);

    // Set PWM pin as output
    pinMode(FAN_PWM_PIN, OUTPUT);

    own_stdio_setup(); // Initialize STDIO for printf
}

void app_loop() {
    // Read current humidity from DHT22
    pid_control.Input = dht.readHumidity();
    if (isnan(pid_control.Input)) {
        Serial.println("Failed to read from DHT sensor!");
        return;
    }

    // Update PID controller
    pid_control_compute(&pid_control);

    // Control fan speed using PWM
    analogWrite(FAN_PWM_PIN, (int)pid_control_get_output(&pid_control));

    // Update LCD display
    lcd_update_display(pid_control.SetPoint, pid_control.Input, pid_control.Output);

    // Send data to Serial Plotter
    Serial.print("SetPoint: ");
    Serial.print(pid_control.SetPoint);
    Serial.print(" Input: ");
    Serial.print(pid_control.Input);
    Serial.print(" Output: ");
    Serial.println(pid_control.Output);

    // Process button inputs
    buttons_process_input(&setPoint, SET_POINT_MIN, SET_POINT_MAX);

    delay(100);
}
