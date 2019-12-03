#include <ESP8266WiFi.h>
#include <ESP8266HTTPClient.h>
#include <ArduinoJson.h>
 
// Sustituir por los datos de vuestro WiFi
const char* ssid = "robots";
const char* password = "robots2020";
String url = "http://api.thingspeak.com/update?api_key=ZOFHFACTCXN4WVTU&field1=";
String url1 = "http://api.thingspeak.com/talkbacks/36150/commands/execute.json";
int sensorPin = A0;
int ledPin = D2;
const size_t capacity = JSON_OBJECT_SIZE(5) + 130;
DynamicJsonBuffer jsonBuffer(capacity);

void setup()
{
   Serial.begin(115200);
   delay(10);
   pinMode(ledPin, OUTPUT);
   pinMode(sensorPin, INPUT);
   // Conectar WiFi
   WiFi.begin(ssid, password);
   while (WiFi.status() != WL_CONNECTED) 
      delay(500);
}
 
void loop()
{
   HTTPClient http;
   WiFiClient client;
 
   if (http.begin(client, url+String(analogRead(sensorPin)))) //Iniciar conexión
   {
      Serial.print("[HTTP] GET...\n");
      int httpCode = http.GET();  // Realizar petición
 
      if (httpCode > 0) {
         Serial.printf("[HTTP] GET... code: %d\n", httpCode);
 
         if (httpCode == HTTP_CODE_OK || httpCode == HTTP_CODE_MOVED_PERMANENTLY) {
            String payload = http.getString();   // Obtener respuesta
            Serial.println(payload);   // Mostrar respuesta por serial
         }
      }
      else {
         Serial.printf("[HTTP] GET... failed, error: %s\n", http.errorToString(httpCode).c_str());
      }
 
      http.end();
   }
   else {
      Serial.printf("[HTTP} Unable to connect\n");
   }

   if (http.begin(client, url1)) //Iniciar conexión
   {
      Serial.print("[HTTP] POST...\n");
      int httpCode = http.POST("api_key=F7HDSCILVRXVAEOL");  // Realizar petición
      http.addHeader("Content-Type", "text/plain");
 
      if (httpCode > 0) {
         Serial.printf("[HTTP] POST... code: %d\n", httpCode);
 
         if (httpCode == HTTP_CODE_OK || httpCode == HTTP_CODE_MOVED_PERMANENTLY) {
            String json = http.getString();   // Obtener respuesta
            JsonObject& root = jsonBuffer.parseObject(json);
            const char* command = root["command_string"];
            Serial.print(String(command));
            if(String(command) == "encender"){
              Serial.print("ENCENDIENDO");
              digitalWrite(ledPin, HIGH);   
            }
            else if (String(command) == "apagar"){
              Serial.print("APAGANDO");
              digitalWrite(ledPin, LOW);  
            }
         }
      }
      else {
         Serial.printf("[HTTP] POST... failed, error: %s\n", http.errorToString(httpCode).c_str());
      }
 
      http.end();
   }
   else {
      Serial.printf("[HTTP} Unable to connect\n");
   }
 
   delay(20000);
}
