#include <PubSubClient.h> 
#include <WiFi.h>

const int potentiometerPin = 32;
// Wi-Fi configuration
const char * ssid = "RT-WiFi_8234";
const char * password = "TMTMc3K3";
// MQTT configuration
const char * server = "192.168.0.15";
const char * topic = "/sensors";
const char * clientName = "com.esp8266";
String payload;
WiFiClient wifiClient;
PubSubClient client(wifiClient);
void wifiConnect() {
    Serial.println();
    Serial.print("Connecting to ");
    Serial.println(ssid);
    WiFi.begin(ssid, password);
    while (WiFi.status() != WL_CONNECTED) {
        delay(500);
        Serial.print(".");
    }
    Serial.println("");
    Serial.print("WiFi connected.");
    Serial.print("IP address: ");
    Serial.println(WiFi.localIP());
}
void mqttReConnect() {
    while (!client.connected()) {
        Serial.print("Attempting MQTT connection...");
        if (client.connect(clientName)) {
            Serial.println("connected");
        } else {
            Serial.print("failed, rc=");
            Serial.print(client.state());
            Serial.println(" try again in 5 seconds");
            delay(5000);
        }
    }
}
void mqttEmit(String topic, String value) {
    client.publish((char * ) topic.c_str(), (char * ) value.c_str());
}
void setup() {
    Serial.begin(115200);
    wifiConnect();
    client.setServer(server, 1883);
    delay(1500);
}
void loop() {
    if (!client.connected()) {
        mqttReConnect();
    }
   // int current = (int)((analogRead(potentiometerPin) * 100) / 4095);
   // mqttEmit(topic, (String) current);
    delay(500);
}
