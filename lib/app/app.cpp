#include <Arduino.h>
#include <config.h>
#include <motor_control.h>
#include <pid_control.h>
#include <DHT.h>
#include <lcd_display.h>

// DHT setup
DHT dht(DHTPIN, DHTTYPE);

// PID control instance
pid_control_t pid_control;

void app_setup() {
    Serial.begin(BAUD_RATE);
    lcd_init();
    dht.begin();
    pinMode(POT_PIN, INPUT);
    motor_init();
    delay(2000); // Stabilizare DHT22
    pid_control_init(&pid_control, PID_KP, PID_KI, PID_KD);
    pid_control_set_setpoint(&pid_control, 50.0); // Setpoint implicit 50%
}

void app_loop() {
    // Citire setpoint din potentiometru (0-1023 -> 0-100%)
    int potValue = analogRead(POT_PIN);
    double setPoint = map(potValue, 0, 1023, 0, 100);
    pid_control_set_setpoint(&pid_control, setPoint);

    // Citire umiditate din DHT
    double humidity = dht.readHumidity();
    if (isnan(humidity)) {
        Serial.println("Failed to read from DHT sensor!");
        delay(1000);
        return;
    }
    pid_control.Input = humidity;

    // Calcul PID
    pid_control_compute(&pid_control);
    int pwm = (int)pid_control_get_output(&pid_control);
    pwm = constrain(pwm, 0, 255);

    // Control motor DC prin L298N
    analogWrite(MOTOR_EN_PIN, pwm);
    // Optional: setează direcția dacă ai nevoie
    // digitalWrite(MOTOR_IN1_PIN, HIGH);
    // digitalWrite(MOTOR_IN2_PIN, LOW);

    // Serial debug
    Serial.print("SetPoint: "); Serial.print(setPoint);
    Serial.print(" Humidity: "); Serial.print(humidity);
    Serial.print(" PWM: "); Serial.println(pwm);

    lcd_update_display((uint16_t)setPoint, (uint16_t)humidity, pwm);

    delay(200);
}
