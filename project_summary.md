# Concluzie

Prin această structură modulară, proiectul permite controlul facil al unui motor DC (prin driver L298N) și monitorizarea unui parametru (umiditate sau poziție) cu histereză, cu afișare pe OLED și interfață serială. Utilizatorul poate seta valoarea de referință (setpoint) prin potențiometru, iar sistemul răspunde imediat cu starea actuală pe ecran și serial. Arhitectura modulară permite extinderea rapidă pentru alte funcționalități sau senzori.

---

## Analiza Tehnologică & Context

Proiectul utilizează Arduino Mega 2560 pentru controlul unui motor DC cu driver L298N, pe baza valorilor citite de la senzori (DHT11 sau potențiometru). Utilizatorul poate seta setpoint-ul, iar sistemul acționează motorul automat, cu histereză, pentru a evita comutările frecvente. Starea sistemului este afișată pe OLED și în terminal serial.

---

## Proiectare Arhitecturală & Explicații HW–SW

Arhitectura este modulară, cu fișiere separate pentru fiecare componentă: control motor, histereză, afișare OLED, citire senzori. Diagrama bloc evidențiază fluxul:

```
Potențiometru (Setpoint) / DHT11 (Umiditate)
                |
                v
        Arduino Mega 2560
                |
    +-----------+-----------+
    |           |           |
Control Motor  Histereză   Afișare OLED/Serial
    |           |           |
    +-----------+-----------+
                |
           Motor DC (L298N)
```

---

## Structura Proiectului & Implementare Modulară

Codul este organizat pe module:
- `app.cpp` – logica principală și bucla de control
- `motor_control.cpp/h` – inițializare și control motor L298N
- `hysteresis.cpp/h` – logica de histereză ON/OFF
- `lcd_display.cpp/h` – afișare pe OLED (SSD1306)
- `config.h` – configurări hardware și parametri
- (opțional) `pid_control.cpp/h` – pentru control PID, dacă se dorește

---

## Descrierea Componentelor Hardware

- **Arduino Mega 2560** – platforma principală de procesare
- **Driver L298N** – pentru controlul unui motor DC (pini 7, 8, 9)
- **Motor DC** – conectat la L298N
- **Potențiometru** – pentru setarea valorii de referință (A0)
- **DHT11** – pentru măsurarea umidității (pin 2)
- **OLED 128x32 I2C** – pentru afișare (SDA: 20, SCL: 21)
- **LED (pin 13)** – indică starea motorului

---

## Descrierea Modulelor Software

- **Control motor L298N:** funcții pentru pornire/oprire și comutare direcție în funcție de abatere
- **Histereză:** funcții pentru ON/OFF cu bandă de toleranță (anti-flutter)
- **Afișare OLED:** funcții pentru afișarea valorilor relevante (setpoint, valoare curentă, PWM)
- **Citire senzori:** funcții pentru citirea potențiometrului și DHT11
- **Interfață serială:** raportare stare și debug

---

## Implementare Funcțională

Aplicația respectă cerințele laboratorului: control ON/OFF cu histereză, comutare automată a direcției motorului, afișare pe OLED și serial, structură modulară pentru mentenanță și extindere ușoară.

---

## Prezentarea Rezultatelor

Rezultatele sunt afișate pe OLED și prin serial (`Serial.print`). Utilizatorul vede în timp real setpoint-ul, valoarea curentă și starea motorului.

---

## Bibliografie

- https://docs.platformio.org/
- https://www.arduino.cc/reference/en/
- https://www.arduino.cc/en/Guide/ArduinoMega2560
- https://www.arduino.cc/en/Tutorial/DigitalPins
- https://www.arduino.cc/en/Reference/Serial
- https://www.electronicwings.com/nodemcu/relay-module-interfacing-with-nodemcu
- https://lastminuteengineers.com/arduino-relay-tutorial/
- https://www.tinkercad.com/learn/arduino
