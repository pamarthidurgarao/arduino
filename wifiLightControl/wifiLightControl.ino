// Wi-Servo v1.0 By Igor Fonseca Albuquerque

//include libraries
#include  "ESP8266WiFi.h"
#include "ESP8266HTTPClient.h"
#include "ArduinoJson.h"

//**************
// Arduino Setup
//**************
const char* ssid     = "Sorry";
const char* password = "Welcome@1";
const char* host = "192.168.0.17";
const int port = 80;
int pin = D2;

WiFiClient client;

void  setup () {
  pinMode(pin, OUTPUT);    
  Serial.begin(9600);
  delay(10);

  Serial.println();
  Serial.println();
  Serial.print("Connecting to ");
  Serial.println(ssid);

  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  Serial.println("");
  Serial.println("\nWiFi connected");
  Serial.println("IP address: ");
  Serial.print(WiFi.localIP());

}

//**********
// Main Loop
//**********
void loop()
{

  Serial.println("000000000000000000000000");
  HTTPClient http; //Object of class HTTPClient
  http.begin("http://pkm65gn7xrwr.cloud.wavemakeronline.com/IOT/services/iot/Control/1");
  int httpCode = http.GET();

  if (httpCode > 0)
  {
    DynamicJsonDocument root(1024);
    DeserializationError err = deserializeJson(root, http.getString());

    int id = root["id"];
    const char* name = root["name"];
    const char* username = root["type"];
    const boolean status = root["status"];

    Serial.print("Name:");
    Serial.println(name);
    Serial.print("Username:");
    Serial.println(username);
    Serial.print("Status:");
    Serial.println(status);

    if(status){
      Serial.print("On");
      digitalWrite(pin, HIGH);
    }else{
      Serial.print("Off");
      digitalWrite(pin, LOW);
    }
  }
  delay(2000);
}
