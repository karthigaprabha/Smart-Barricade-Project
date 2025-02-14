# Smart Barricade Project

## Overview
This project aims to develop a Smart Barricade with a GPS module and microcontroller to track its location on Google Maps. The collected GPS data is sent to the cloud (ThingSpeak) and visualized on a user interface.

## Components
- GPS Module (e.g., NEO-6M or NEO-7M)
- Microcontroller (e.g., Arduino, ESP32)
- Wi-Fi Module (e.g., ESP8266 or built-in Wi-Fi of ESP32)
- ThingSpeak Account
- Google Maps API Key

## Steps to Implement
1. **Collect GPS Data**: Use a GPS module and microcontroller to collect location data.
2. **Send Data to ThingSpeak**: Transmit the GPS data to ThingSpeak using Wi-Fi.
3. **Visualize Data**: Display the GPS data on a web interface using Google Maps API.

## Instructions
### 1. Hardware Setup
- Connect the GPS module to the microcontroller.
- Ensure the microcontroller is connected to the internet.

### 2. Software Setup
#### Collect GPS Data
Upload the `SmartBarricade.ino` file to the microcontroller.

#### Send Data to ThingSpeak
Configure the Wi-Fi credentials and ThingSpeak API key in the `SmartBarricade.ino` file.

#### Visualize Data
Open `index.html` in a web browser to visualize the GPS data on Google Maps.

## Files
- `SmartBarricade.ino`: Arduino/ESP32 code to collect GPS data and send it to ThingSpeak.
- `index.html`: Web interface to visualize the GPS data on Google Maps.

## References
- [TinyGPSPlus Library](https://github.com/mikalhart/TinyGPSPlus)
- [ThingSpeak ESP32 Example](https://github.com/mathworks/thingspeak-esp32-example)
- [Google Maps JavaScript API](https://developers.google.com/maps/documentation/javascript/overview)