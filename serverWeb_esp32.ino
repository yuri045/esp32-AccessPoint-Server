#include <WiFi.h>
#include <WebServer.h>

// Imposta il nome della rete (SSID) e la password dell'Access Point
const char* ssid = "ESP32_Server";
const char* password = "esp32web";  // almeno 8 caratteri

WebServer server(80);

void handleRoot() {
  String page = R"rawliteral(
  <!DOCTYPE html>
  <html lang="it">
  <head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>ESP32 Dashboard♠♣</title>
    <style>
      body { font-family: Arial; padding: 20px; background: #f0f0f0; }
      header {background-color: #007bff; color: white; width: 100%; padding: 20px; text-align: center; border-radius: 5px;}
      .data-field { margin: 10px 0; font-size: 18px; }
      button { padding: 10px 20px; font-size: 16px; background-color: #28a745; color: white; }
      button:hover { background-color: #218838; }
      footer { margin-top: 30px; font-size: 14px; color: #666; text-align: center; }
      #description { margin-top: 40px; font-size: 16px; line-height: 1.5; max-width: 700px; background: white; padding: 15px 20px; border-radius: 8px; box-shadow: 0 2px 5px rgba(0,0,0,0.1); }
    </style>
  </head>
  <body>
    <h1>Dashboard ESP32♠</h1>
    <div class="data-field">Temperatura: <span id="temp">25.0</span> °C</div>
    <div class="data-field">Umidità: <span id="hum">60</span> %</div>
    <div class="data-field">LED Stato: <span id="ledStatus">OFF</span></div>
    <button onclick="updateData()">Aggiorna Dati</button>

    <p id="description">
      Questa pagina web funziona come dashboard locale ospitata da un ESP32 configurato in modalità Access Point. 
      Qui puoi visualizzare dati fittizi come temperatura e umidità, aggiornabili dinamicamente cliccando il pulsante “Aggiorna Dati”. 
      Lo stato del LED rappresenta un esempio di toggle visivo senza collegamento hardware. 
      Tutti i dati sono gestiti direttamente nel browser tramite JavaScript, senza necessità di connessione a internet o server esterni. 
      L’interfaccia è semplice, responsive e utilizza uno stile pulito per facilitare la lettura e l’interazione.
    </p>


    <footer>
      ESP32 Demo &copy; 2025♠valloneyuri
    </footer>


    <script>
      let temperature = 25.0;
      let humidity = 60;
      let ledOn = false;

      function updateData() {
        console.log("Funzione chiamata");
        temperature = (20 + Math.random() * 10).toFixed(1);
        humidity = (40 + Math.random() * 30).toFixed(0);
        ledOn = !ledOn;

        document.getElementById('temp').innerText = temperature;
        document.getElementById('hum').innerText = humidity;
        document.getElementById('ledStatus').innerText = ledOn ? 'ON' : 'OFF';

        // ogni 5 secondi aggiorna updateData (5000 millisecondi)
        setInterval(updateData, 5000);
      }
    </script>
  </body>
  </html>
  )rawliteral";

  server.send(200, "text/html", page);
}

void handleNotFound() {
  server.send(404, "text/plain", "404: Pagina non trovata");
}

void setup() {
  Serial.begin(115200);
  delay(1000);

  Serial.println("📡 Avvio Access Point...");

  WiFi.softAP(ssid, password);
  IPAddress IP = WiFi.softAPIP();

  Serial.print("✅ Access Point creato. IP: ");
  Serial.println(IP);

  server.on("/", handleRoot);
  server.onNotFound(handleNotFound);
  server.begin();

  Serial.println("🚀 Web server avviato.");
}

void loop() {
  server.handleClient();
}



