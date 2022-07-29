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

int cleint(){
  //WIFI INITIALIZATION
 WiFiClient client = server.available(); 
 if (client){ 
 String currentLine = ""; 
 while (client.connected()){ 
 if (client.available()){ 
 char c = client.read(); 
 if (c == '\n') { 
 if (currentLine.length() == 0) {
 client.println("HTTP/1.1 200 OK");
 client.println("Content-type:text/html");
 client.println();
 break;
 } 
 else 
 currentLine = "";
 }
 else if (c != '\r') 
 currentLine += c; 
 if (currentLine.endsWith("GET /S"))
 return 1;
 if (currentLine.endsWith("GET /C"))
 return 2; 
 if (currentLine.endsWith("GET /D"))
 return 3; 
 }
 }
