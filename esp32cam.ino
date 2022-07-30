//importing libs
#include <WebServer.h>
#include <WiFi.h>
#include <esp32cam.h>
//wifi constants
const char* WIFI_SSID = "WIFI_SSID";
const char* WIFI_PASS = "WIFI_PASS";
WebServerserver(80);
static auto loRes = esp32cam::Resolution::find(320, 240);
static auto hiRes = esp32cam::Resolution::find(800, 600);
void
serveJpg(){
 auto frame = esp32cam::capture();
 if (frame == nullptr) {
Serial.println("CAPTURE FAIL");
server.send(503, "", "");
 return;
 }
 
