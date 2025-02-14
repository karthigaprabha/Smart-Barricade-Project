#include <WiFi.h>
#include <TinyGPS++.h>
#include <SoftwareSerial.h>

// Wi-Fi credentials
const char* ssid = "YOUR_WIFI_SSID";
const char* password = "YOUR_WIFI_PASSWORD";

// ThingSpeak settings
const char* server = "api.thingspeak.com";
const String apiKey = "YOUR_THINGSPEAK_API_KEY";

// GPS Module connections
#define GPS_RX 16  // Connect to TX of GPS
#define GPS_TX 17  // Connect to RX of GPS

SoftwareSerial gpsSerial(GPS_RX, GPS_TX); // Create a software serial port for GPS
TinyGPSPlus gps; // Create a TinyGPS++ object

void setup() {
  Serial.begin(115200);
  gpsSerial.begin(9600);

  // Connect to Wi-Fi
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Connecting to WiFi...");
  }
  Serial.println("Connected to WiFi");
}

void loop() {
  while (gpsSerial.available() > 0) {
    gps.encode(gpsSerial.read()); // Feed the GPS data to TinyGPS++
  }

  if (gps.location.isUpdated()) {
    float latitude = gps.location.lat();
    float longitude = gps.location.lng();

    // Send data to ThingSpeak
    if (WiFi.status() == WL_CONNECTED) {
      String url = "/update?api_key=" + apiKey + "&field1=" + String(latitude, 6) + "&field2=" + String(longitude, 6);
      sendToThingSpeak(url);
    }
  }
}

void sendToThingSpeak(String url) {
  WiFiClient client;
  if (client.connect(server, 80)) {
    client.print("GET " + url + " HTTP/1.1\r\n");
    client.print("Host: " + String(server) + "\r\n");
    client.print("Connection: close\r\n\r\n");
    client.stop();
    Serial.println("Data sent to ThingSpeak");
  } else {
    Serial.println("Connection to ThingSpeak failed");
  }
}