//IMPORTING LIBS                                             //
#include <WTV020SD16P.h>                                     //
#include<WiFi.h>                                             //
#include<HardwareSerial.h>                                   //
#include<TinyGPS++.h>                                        //
#include <BlynkSimpleEsp32.h>                                //
//STARTING SOME FUNCTIONS OF ESP32                           //
WiFiServer server(80);                                       //
HardwareSerial SerialGPS(1);                                 //
TinyGPSPlus gps;                                             //
//ANNOUNCING FEW CONSTANTS                                   //
const char* ssid="WIFI_NAME";                                //
const char* pass="WIFI_PASS";                                //
                                                             //
int cleint(){                                                //
  //WIFI INITIALIZATION                                      //
 WiFiClient client = server.available();                     //
 if (client){                                                //
 String currentLine = "";                                    //
 while (client.connected()){                                 //
 if (client.available()){                                    //
 char c = client.read();                                     //
 if (c == '\n') {                                            //
 if (currentLine.length() == 0) {                            //
 client.println("HTTP/1.1 200 OK");                          //
 client.println("Content-type:text/html");                   //
 client.println();                                           //
 break;                                                      //
 }                                                           //
 else                                                        //
 currentLine = "";                                           //
 }                                                           //
 else if (c != '\r')                                         //
 currentLine += c;                                           //
 if (currentLine.endsWith("GET /S"))                         //
 return 1;                                                   //
 if (currentLine.endsWith("GET /C"))                         //
 return 2;                                                   //
 if (currentLine.endsWith("GET /D"))                         //
 return 3;                                                   //
 }                                                           //
 }                                                           //
 client.stop();                                              //
}}                                                           //
int Distance(){                                              //
 digitalWrite(Trig, LOW);                                    //
 delayMicroseconds(2);                                       //
 digitalWrite(Trig, HIGH);                                   //
 delayMicroseconds(10);                                      //
 digitalWrite(Trig, LOW);                                    //
 int timee = pulseIn(Echo, HIGH);                            //
 int d=timee*0.034/2;                                        //
 //distance and other functions                              //
 if(d<30)                                                    //
 return 1;                                                   //
                                                             //
 else                                                        //
 return 0;                                                   //
}                                                            //
                                                             //
void Sound(int a,int b)                                      //
  //sound and voice functions setup                          //
 if(b==1)                                                    //
 wtv.playVoice(a);                                           //
                                                             //
 else                                                        //
 return;                                                     //
}                                                            //
void LOCATION(){                                             //
 Blynk.run();                                                //
 while (SerialGPS.available() > 0)//gps thing                //
 {                                                           //
 if (gps.encode(SerialGPS.read()))                           //
 {                                                           //
 if (gps.location.isValid())                                 //
 {                                                           //
 latitude = gps.location.lat();                              //
 lat_str = String(latitude , 6);                             //
 longitude = gps.location.lng();                             //
 lng_str = String(longitude , 6);                            //
 Blynk.virtualWrite(V0, 1, latitude, longitude, "Location"); //
   //location function                                       //
 }                                                           //
 }                                                           //
 }                                                           //
}                                                            //
void setup()                                                 //
{                                                            //
  //main setup for project                                   //
 Serial.begin(115200);//data transfer rate                   //
 delay(4000);//4 secs lag                                    //
 WiFi.begin(ssid,pass);                                      //
 while(WiFi.status()!=WL_CONNECTED)                          //
 {                                                           //
 delay(1000);                                                //
 Serial.println("connecting to wifi..");                     //
 }                                                           //
 Serial.println("connected");                                //
 Serial.println("IP address: ");                             //
 Serial.println(WiFi.localIP());                             //
 server.begin();                                             //
 SerialGPS.begin(9600, SERIAL_8N1, 16, 17);                  //
 Blynk.begin(auth, ssid, pass);                              //
 Blynk.virtualWrite(V0, "clr");                              //
 wtv.reset();                                                //
}//wifi or network thing                                     //
void loop()                                                  //
{                                                            //
 obstacle=cleint();                                          //
 distance=Distance();                                        //
 Sound(obstacle,distance);                                   //
 LOCATION();                                                 //
}//looping func                                              //
                                                             //
