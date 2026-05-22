#include <WiFi.h>
#include <PubSubClient.h>
#include "DHTesp.h"

#define DHTPIN 15
#define PIRPIN 13

const char* ssid = "Wokwi-GUEST";
const char* password = "";

const char* mqtt_server = "broker.hivemq.com";

WiFiClient espClient;
PubSubClient client(espClient);

DHTesp dhtSensor;

void setupWifi() {

  Serial.print("Conectando WiFi");

  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {

    delay(500);
    Serial.print(".");
  }

  Serial.println("");
  Serial.println("WiFi conectado!");
}

void reconnectMQTT() {

  while (!client.connected()) {

    Serial.print("Conectando MQTT...");

    String clientId = "ESP32Client-";
    clientId += String(random(1000));

    if (client.connect(clientId.c_str())) {

      Serial.println(" conectado!");

    } else {

      Serial.println(" falhou");
      delay(2000);
    }
  }
}

void setup() {

  Serial.begin(115200);

  dhtSensor.setup(DHTPIN, DHTesp::DHT22);

  pinMode(PIRPIN, INPUT);

  setupWifi();

  client.setServer(mqtt_server, 1883);

  Serial.println("Sistema iniciado");
}

void loop() {

  if (!client.connected()) {
    reconnectMQTT();
  }

  client.loop();

  // Leitura sensores
  TempAndHumidity data = dhtSensor.getTempAndHumidity();

  float temperatura = data.temperature;
  float umidade = data.humidity;

  int movimento = digitalRead(PIRPIN);

  // Status do pet
  String statusPet = "Normal";

  if (temperatura > 39 || movimento == HIGH) {
    statusPet = "Alerta";
  }

  // Criar JSON
  String payload = "{";
  payload += "\"temperatura\":";
  payload += temperatura;
  payload += ",";
  payload += "\"umidade\":";
  payload += umidade;
  payload += ",";
  payload += "\"movimento\":";
  payload += movimento;
  payload += ",";
  payload += "\"status\":\"";
  payload += statusPet;
  payload += "\"}";

  // Enviar MQTT
  client.publish("clyvo/pet", payload.c_str());

  // Mostrar no Serial
  Serial.println(payload);

  delay(3000);
}