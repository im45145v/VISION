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
 void
handleJpg()
{
 if (!esp32cam::Camera.changeResolution(hiRes)) {
Serial.println("SET-HI-RES FAIL");
 }
serveJpg();
}
void setup(){
//main setup
Serial.begin(115200);
Serial.println();{
 using namespace esp32cam;
 Config cfg;
cfg.setPins(pins::AiThinker);
cfg.setResolution(hiRes);
cfg.setBufferCount(2);
cfg.setJpeg(80);
 bool ok = Camera.begin(cfg);
Serial.println(ok ? "CAMERA IS OK" : "CAMERA FAILED");//camera update
 }
WiFi.persistent(false);
WiFi.mode(WIFI_STA);
WiFi.begin(WIFI_SSID, WIFI_PASS);
 while (WiFi.status() != WL_CONNECTED) {
delay(500);//delay for half sec
 }
Serial.print("http://");
Serial.println(WiFi.localIP());
Serial.println(" /cam.jpg");
server.on("/cam.jpg", handleJpg);
server.begin();
}
void loop(){
server.handleClient();
}//loop to handle the device
