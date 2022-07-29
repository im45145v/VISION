//IMPORTING LIBS
#include <WTV020SD16P.h>
#include<WiFi.h>
#include<HardwareSerial.h>
#include<TinyGPS++.h>
#include <BlynkSimpleEsp32.h>
//STARTING SOME FUNCTIONS OF ESP32
WiFiServer server(80);
HardwareSerial SerialGPS(1);
TinyGPSPlus gps;
//ANNOUNCING FEW CONSTANTS
const char* ssid="WIFI_NAME";
const char* pass="WIFI_PASS";
