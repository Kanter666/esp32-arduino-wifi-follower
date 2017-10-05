#include <WiFi.h>

//name of the network
const char* ssid = "Why is Bill an idiot";
 
void setup() {
  //setup
  Serial.begin(115200);

  WiFi.mode(WIFI_STA);
  WiFi.disconnect();
  delay(100);

  Serial.println("Setup done");
 
}
 
void loop() {
  //scanning netwroks and printing strength of 'ssid' netwrok
  int n = WiFi.scanNetworks();
  for (int i = 0; i < n; ++i) {
    if(WiFi.SSID(i) == ssid){
      Serial.println(WiFi.RSSI(i));
    }
  }
  delay(1);
}
