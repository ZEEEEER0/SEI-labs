# Concluzie

Prin această structură modulară, proiectul permite controlul unui LED folosind un buton (automat finit/FSM), cu afișare pe OLED și interfață serială. Utilizatorul poate schimba starea LED-ului prin apăsarea butonului, iar sistemul afișează imediat starea curentă atât pe ecran, cât și pe serial. Arhitectura modulară permite extinderea rapidă pentru alte funcționalități sau senzori.

---

## Analiza Tehnologică & Context

Proiectul utilizează Arduino Mega 2560 pentru controlul unui LED pe baza unui buton, folosind un automat finit (FSM) pentru comutarea stării. Utilizatorul poate schimba starea LED-ului, iar sistemul afișează starea pe OLED și în terminal serial.

---

## Proiectare Arhitecturală & Explicații HW–SW

Arhitectura este modulară, cu fișiere separate pentru fiecare componentă:
- control FSM (automat finit) pentru LED,
- afișare OLED,
- citire buton.

---

## Structura Proiectului & Implementare Modulară

Codul este organizat pe module:
- `app.cpp` – logica principală și bucla de control
- `fsm_button_led.cpp/h` – logica FSM pentru control LED
- `lcd_display.cpp/h` – afișare pe OLED (SSD1306)
- `config.h` – configurări hardware și parametri

---

## Descrierea Componentelor Hardware

- **Arduino Mega 2560** – platforma principală de procesare
- **Buton** – pentru schimbarea stării LED-ului (pin 2)
- **LED** – controlat de FSM (pin 13)
- **OLED 128x32 I2C** – pentru afișare (SDA: 20, SCL: 21)

---

## Descrierea Modulelor Software

- **FSM Button-LED:** funcții pentru comutarea stării LED-ului la apăsarea butonului, cu debounce
- **Afișare OLED:** funcții pentru afișarea stării LED-ului (ON/OFF)
- **Citire buton:** funcții pentru citirea stării butonului cu debounce
- **Interfață serială:** raportare stare și debug

---

## Implementare Funcțională

Aplicația respectă cerințele laboratorului: control ON/OFF al LED-ului cu FSM, afișare pe OLED și serial, structură modulară pentru mentenanță și extindere ușoară.

---

## Prezentarea Rezultatelor

Rezultatele sunt afișate pe OLED și prin serial (`Serial.print`). Utilizatorul vede în timp real starea LED-ului (ON/OFF).

---

## Bibliografie

- https://docs.platformio.org/
- https://www.arduino.cc/reference/en/
- https://www.arduino.cc/en/Guide/ArduinoMega2560
- https://www.arduino.cc/en/Tutorial/DigitalPins
- https://www.arduino.cc/en/Reference/Serial
- https://www.tinkercad.com/learn/arduino
