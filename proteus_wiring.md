# Model conexiuni Proteus – Semafor Inteligent cu Arduino Mega2560

## Pini utilizați

| Componentă         | Pin Arduino Mega2560 | Observații                        |
|--------------------|---------------------|-----------------------------------|
| LED Est - Roșu     | 4                   |                                   |
| LED Est - Galben   | 5                   |                                   |
| LED Est - Verde    | 6                   |                                   |
| LED Nord - Roșu    | 7                   |                                   |
| LED Nord - Galben  | 8                   |                                   |
| LED Nord - Verde   | 9                   |                                   |
| Buton cerere Nord  | 2                   | Un capăt la pin 2, celălalt la GND|
| OLED SDA           | 20                  | I2C SDA                           |
| OLED SCL           | 21                  | I2C SCL                           |
| OLED VCC           | 5V                  |                                   |
| OLED GND           | GND                 |                                   |

---

## Schema de conectare (text)

- **LED-uri Est-Vest:**  
  - LED roșu: pin 4 (prin rezistor 220Ω la GND)
  - LED galben: pin 5 (prin rezistor 220Ω la GND)
  - LED verde: pin 6 (prin rezistor 220Ω la GND)

- **LED-uri Nord-Sud:**  
  - LED roșu: pin 7 (prin rezistor 220Ω la GND)
  - LED galben: pin 8 (prin rezistor 220Ω la GND)
  - LED verde: pin 9 (prin rezistor 220Ω la GND)

- **Buton cerere Nord:**  
  - Un capăt la pinul 2 (BUTTON_NORTH)
  - Celălalt capăt la GND

- **OLED 128x32 I2C:**  
  - VCC la 5V
  - GND la GND
  - SDA la pin 20 (SDA)
  - SCL la pin 21 (SCL)

---

## Recomandări

- Folosește rezistențe de 220Ω pentru fiecare LED între pin și GND.
- Butonul se conectează între pinul 2 și GND (folosește INPUT_PULLUP în cod).
- OLED-ul se conectează pe magistrala I2C (SDA/SCL).
- Poți simula totul în Proteus cu Arduino Mega2560, 6 LED-uri, 1 buton și un modul OLED I2C.

---
