#include <WiFi.h>

const char* routerSSID = "ARUSHA_SCIENCE.";      // Router SSID
const char* routerPassword = "@sc!3nc3.";        // Router password

const char* hotspotSSID = "ESP32";               // Hotspot SSID
const char* hotspotPassword = "12345678";        // Hotspot password

void setup() {
  Serial.begin(115200);
  
  // First, connect to the router as a Wi-Fi client
  WiFi.begin(routerSSID, routerPassword);
  Serial.println();
  Serial.print("Connecting to Wi-Fi");
  
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.print(".");
  }
  
  Serial.println();
  Serial.print("Connected to Wi-Fi network! IP Address: ");
  Serial.println(WiFi.localIP());
  
  // Switch to Access Point mode
  WiFi.softAP(hotspotSSID, hotspotPassword);
  Serial.println();
  Serial.print("Hotspot started with IP: ");
  Serial.println(WiFi.softAPIP());

  // Enable NAT (Network Address Translation)
  enableInternetSharing();
}

void loop() {
  // Keep the ESP32 running
}

// Enable the sharing of the internet connection via the ESP32 hotspot
void enableInternetSharing() {
  Serial.println("Enabling internet sharing...");
  
  // Here, we'd be setting up a network routing mechanism, but full routing (like a real router) is not available directly.
  // Instead, we'll have to rely on external routing solutions like configuring routing on the WiFi library or the use of external libraries to handle routing and NAT.

  // Unfortunately, the ESP32 library doesn't have direct full routing/NAT capabilities, but by using the IP routing and specific routing software on a device connected to the ESP32, we can bridge traffic.
}
