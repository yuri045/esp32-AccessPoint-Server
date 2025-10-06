# esp32-AccessPoint-Server

## ESP32 Dashboard - Web Server in modalità Access Point


Dashboard web interattiva ospitata da un ESP32-WROOM-32D in modalità Access Point. Mostra dati fittizi come temperatura, umidità e stato LED, aggiornabili direttamente dal browser senza connessione internet esterna.

## 📌 Descrizione

Questo progetto crea un **Web Server su ESP32** configurato come **Access Point**, permettendo a dispositivi WiFi (come smartphone, PC o tablet) di connettersi direttamente al microcontrollore e accedere a una dashboard interattiva via browser.

La dashboard visualizza:
- Temperatura (valori simulati)
- Umidità (valori simulati)
- Stato LED (ON/OFF simulato)

Tutti i dati vengono aggiornati dinamicamente tramite JavaScript lato client, senza chiamate al backend o sensori reali.

## 🔧 Tecnologie utilizzate

- C++ (Arduino IDE)
- ESP32 WiFi Library
- WebServer Library
- HTML5 + CSS3
- JavaScript

## 🌐 Funzionamento

1. ESP32 si avvia come **Access Point** con SSID: `ESP32_Server` e password: `esp32web`
2. L'indirizzo IP viene stampato su monitor seriale (tipicamente `192.168.4.1`)
3. Un browser connesso alla rete può accedere alla dashboard digitando l’IP
4. I dati nella pagina vengono aggiornati simulando letture ogni 5 secondi

## 📷 Screenshot (Demo UI)

>  <img width="1118" height="497" alt="DASHBOARD_ESP32" src="https://github.com/user-attachments/assets/08edbca7-7bb7-43f6-93a7-6b350da09ee0" />
 
> *Interfaccia utente minimale, responsive e adatta a dispositivi mobili*

## 🛠️ Come usare il codice

1. **Hardware richiesto:**
   - ESP32 Dev Board
   - Cavo USB
   - PC con Arduino IDE

2. **Passaggi:**
   - Apri l’Arduino IDE
   - Installa supporto ESP32 via Board Manager
   - Incolla il codice nel tuo sketch
   - Carica il codice sull’ESP32
   - Apri il monitor seriale per leggere l’indirizzo IP
   - Connettiti alla rete WiFi `ESP32_Server` dal tuo dispositivo
   - Inserisci l’indirizzo IP nel browser

## ⚠️ Note

- Il progetto non legge sensori reali: i valori sono **generati casualmente**
- Lo stato LED è solo visivo (nessun LED fisico coinvolto)
- Perfetto per demo, test interfacce o basi per progetti più complessi

## 👨‍💻 Autore

**Yuri Vallone** – _ESP32 Dashboard Demo © 2025_  
GitHub: (https://github.com/yuri045)

---
