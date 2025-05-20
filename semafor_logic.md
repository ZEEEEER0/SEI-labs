# Logica de funcționare – Semafor Inteligent cu FSM și FreeRTOS

## Descriere generală

- Semaforul controlează două direcții de trafic: **Est-Vest** și **Nord-Sud**.
- Fiecare direcție are LED-uri: **roșu, galben, verde**.
- **Butonul** de pe pinul 2 simulează cererea de traversare pentru direcția Nord-Sud.

---

## Secvența de funcționare

1. **Implicit:**  
   - **Est-Vest** are verde (LED_E_GREEN ON), Nord-Sud are roșu (LED_N_RED ON).
   - Această stare se menține atâta timp cât NU există cerere pe Nord-Sud (butonul nu este apăsat).

2. **Cerere Nord-Sud:**  
   - Dacă se apasă butonul (cerere Nord-Sud), semaforul va schimba starea la finalul ciclului verde Est-Vest.

3. **Tranziție Est-Vest → Nord-Sud:**
   - Est-Vest: verde → galben (LED_E_YELLOW ON, scurt timp)
   - Est-Vest: roșu (LED_E_RED ON), Nord-Sud: verde (LED_N_GREEN ON)

4. **Nord-Sud are verde:**  
   - Nord-Sud rămâne verde un timp fix (ex: 5 secunde), indiferent dacă butonul rămâne apăsat sau nu.

5. **Tranziție Nord-Sud → Est-Vest:**
   - Nord-Sud: verde → galben (LED_N_YELLOW ON, scurt timp)
   - Nord-Sud: roșu (LED_N_RED ON), Est-Vest: verde (LED_E_GREEN ON)
   - Cererea Nord-Sud se resetează.

6. **Ciclul se repetă:**  
   - Dacă nu există cerere Nord-Sud, Est-Vest rămâne verde.
   - Dacă apare cerere, ciclul se reia.

---

## Tabel stări simplificat

| Stare                | LED Est | LED Nord | Condiție de tranziție           |
|----------------------|---------|----------|---------------------------------|
| Est Verde            | Verde   | Roșu     | Cerere Nord-Sud (buton)         |
| Est Galben           | Galben  | Roșu     | Timeout scurt                   |
| Est Roșu / Nord Verde| Roșu    | Verde    | Timeout Nord-Sud                |
| Nord Galben          | Roșu    | Galben   | Timeout scurt                   |
| (revine la Est Verde)| Verde   | Roșu     | Timeout                         |

---

## Observații

- **Butonul** nu schimbă instant starea, ci doar semnalează cererea pentru Nord-Sud.
- **Tranzițiile** respectă regulile rutiere: verde → galben → roșu.
- **OLED-ul** și **serialul** afișează starea curentă a semaforului.

---
