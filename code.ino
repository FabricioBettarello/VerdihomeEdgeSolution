#include <WiFi.h>
#include <PubSubClient.h>

// Configurações WiFi e MQTT
const char* ssid = "Wokwi-GUEST";
const char* password = "";
const char* mqtt_server = "broker.hivemq.com";
const int mqtt_port = 1883;

WiFiClient espClient;
PubSubClient client(espClient);

#define LDR_PIN A0
#define LED_PIN 2

int limiteConsumo = 800; 

void setup_wifi() {
  delay(10);
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
  }
}

void callback(char* topic, byte* payload, unsigned int length) {
  String message;
  for (int i = 0; i < length; i++) {
    message += (char)payload[i];
  }
  if (String(topic) == "verdiHome/comando") {
    if (message == "ligar") {
      digitalWrite(LED_PIN, HIGH);
    } else if (message == "desligar") {
      digitalWrite(LED_PIN, LOW);
    }
  }
}

void setup() {
  pinMode(LED_PIN, OUTPUT);
  digitalWrite(LED_PIN, LOW);

  setup_wifi();
  client.setServer(mqtt_server, 1883);
  client.setCallback(callback);
}

void loop() {
  if (!client.connected()) {
    while (!client.connect("VerdiHomeClient")) {
      delay(500);
    }
    client.subscribe("verdiHome/comando");
  }


  int consumo = analogRead(LDR_PIN);
  String consumoStr = String(consumo);
  client.publish("verdiHome/consumo", consumoStr.c_str());


  if (consumo > limiteConsumo) {
    client.publish("verdiHome/alerta", "Consumo elevado detectado!");
  }

  client.loop();
  delay(2000);
}
