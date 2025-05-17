Analiza Tehnologică & Context

Proiectul utilizează platforma Arduino Mega 2560 pentru a implementa un sistem de control al releelor prin comenzi seriale. Contextul aplicației este de a permite utilizatorului să controleze, prin comenzi simple, starea a trei relee (Red, Green, Blue) conectate la pinii digitali ai plăcii.

Proiectare Arhitecturală & Explicații HW–SW

Arhitectura proiectului este modulară, cu funcții separate pentru fiecare funcționalitate principală: interpretarea comenzilor seriale, controlul releelor și afișarea stării acestora. Diagrama bloc evidențiază fluxul de date de la interfața serială către microcontroler, unde comenzile sunt procesate și direcționate către modulele de releu. Fiecare comandă este interpretată și executată imediat, asigurând un control rapid și intuitiv.

Structura Proiectului & Implementare Modulară

Codul este organizat modular, cu fișiere separate pentru fiecare funcționalitate (parsing comenzi, control releu, configurare). Fișierele de antet (.h) conțin declarațiile funcțiilor și structurilor, iar fișierele sursă (.cpp) conțin implementarea acestora. Această structură permite o dezvoltare și mentenanță facilă, respectând principiile de separare a interfeței de implementare.

Descrierea Componentelor Hardware

- Arduino Mega 2560 – platforma principală de procesare.
- Relee (Red, Green, Blue) – conectate la pinii digitali 13, 12, 11, pentru controlul unor sarcini externe.
- Conexiuni Serial – pentru transmiterea comenzilor și afișarea rezultatelor către PC/terminal serial.

Descrierea Modulelor Software

- Parsat comenzi seriale: Primește și interpretează comenzile de la utilizator.
- Control relee: Module software pentru fiecare releu, cu funcții de toggle, on/off și raportare stare.
- Afișare stare: Răspunde la comenzi cu starea actuală a fiecărui releu sau a tuturor releelor.
- (Opțional) Task de Idle: Poate fi folosit pentru operații de fundal sau pentru afișarea suplimentară a informațiilor.

Implementare Funcțională

Aplicația îndeplinește cerințele de laborator: comenzile seriale sunt interpretate corect, fiecare releu poate fi controlat individual, iar starea sistemului este afișată clar. Structura modulară permite extinderea facilă a proiectului pentru funcționalități suplimentare.

Prezentarea Rezultatelor

Rezultatele sunt prezentate prin intermediul comunicației seriale, utilizând funcțiile STDIO pentru a afișa informațiile relevante despre starea sistemului. Utilizatorul primește feedback imediat pentru fiecare comandă introdusă.

Concluzie Finală

Proiectul demonstrează o implementare eficientă a unui sistem de control al releelor pe un microcontroler Arduino Mega 2560. Structura modulară a codului, interpretarea clară a comenzilor și prezentarea rezultatelor asigură o soluție robustă, intuitivă și ușor de extins.

---

Schema bloc

- Comenzi Serial (User)
    - |
    - v
- Arduino Mega 2560
    - |
    - v
- Procesare comenzi (parsing)
    - |
    - v
- Module Relay (Red, Green, Blue)
    - |
    - v
- Ieșiri fizice (pini 13, 12, 11)

```
User (Serial) --> Arduino --> Parsing comenzi --> Control Relay (Red/Green/Blue) --> Pini Digitali
```

---

Bibliografie

- https://docs.platformio.org/
- https://www.arduino.cc/reference/en/
- https://www.freertos.org/Documentation/RTOS_book.html
- https://www.arduino.cc/en/Guide/ArduinoMega2560
- https://www.arduino.cc/en/Tutorial/BuiltInExamples/Blink
- https://www.arduino.cc/en/Tutorial/DigitalPins
- https://www.arduino.cc/en/Tutorial/SerialEvent
- https://www.arduino.cc/en/Reference/Serial
- https://www.electronicwings.com/nodemcu/relay-module-interfacing-with-nodemcu
- https://lastminuteengineers.com/arduino-relay-tutorial/
- https://www.tutorialspoint.com/arduino/arduino_multitasking.htm
- https://www.tinkercad.com/learn/arduino
- https://github.com/ZEEEEER0/SEI-labs/tree/lab.3.1
