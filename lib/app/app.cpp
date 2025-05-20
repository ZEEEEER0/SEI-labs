#include <Arduino.h>
#include <config.h>
#include <motor_control.h>
#include <lcd_display.h>
#include <DHT.h>

// DHT setup
DHT dht(DHTPIN, DHTTYPE);

void app_setup() {
    Serial.begin(BAUD_RATE);
    lcd_init();
    pinMode(POT_PIN, INPUT);
    motor_init();
    pinMode(MOTOR_IN1_PIN, OUTPUT);
    pinMode(MOTOR_IN2_PIN, OUTPUT);
    pinMode(MOTOR_EN_PIN, OUTPUT);
    pinMode(LED_PIN, OUTPUT);
    digitalWrite(MOTOR_IN1_PIN, HIGH);
    digitalWrite(MOTOR_IN2_PIN, LOW);
    dht.begin();
    delay(1000);
}

void app_loop() {
    // Citire setpoint din potențiometru (0-1023 -> 0-100%)
    int potValue = analogRead(POT_PIN);
    int setPoint = map(potValue, 0, 1023, 0, 100);

    // Citire umiditate din DHT11
    float humidity = dht.readHumidity();
    if (isnan(humidity)) {
        Serial.println("Failed to read from DHT sensor!");
        lcd_update_display(0, 0, 0);
        delay(1000);
        return;
    }

    // Motor ON dacă umiditatea este diferită de setpoint (la nivel de întreg)
    int pwm = 0;
    if ((int)humidity != setPoint) {
        digitalWrite(MOTOR_IN1_PIN, HIGH);
        digitalWrite(MOTOR_IN2_PIN, LOW);
        pwm = 128; // 50% putere
        digitalWrite(LED_PIN, HIGH);
    } else {
        pwm = 0;
        analogWrite(MOTOR_EN_PIN, 0);
        digitalWrite(LED_PIN, LOW);
    }
    analogWrite(MOTOR_EN_PIN, pwm);

    // Afișare LCD și serial
    lcd_update_display(setPoint, (uint16_t)humidity, pwm);
    Serial.print("SetPoint: "); Serial.print(setPoint);
    Serial.print(" Umiditate: "); Serial.print(humidity);
    Serial.print(" Motor: "); Serial.println(pwm > 0 ? "ON" : "OFF");

    delay(200);
}
