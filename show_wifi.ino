#include <WiFi.h>

//name of the network
const char* ssid = "Patient";
float oldDistance = - 100;
int state = 1; //1 = forward, 2 = backward, 3 = left, 4 = right
 
void setup() {
  //setup
  Serial.begin(115200);

  WiFi.mode(WIFI_STA);
  WiFi.disconnect();
  delay(100);

  Serial.println("Setup done");

}

// calculate strength of signal by getting average of 5 measurements
float signalStrength(){
  int n = WiFi.scanNetworks();
  for (int i = 0; i < n; ++i) {
    if(WiFi.SSID(i) == ssid){
      return WiFi.RSSI(i);
    }
  }
}

void goDir(int dir) {
  switch (dir)
  {
    case 1: 
      Serial.println("forward");
      break;
    case 2:
      Serial.println("back");
      break;
    case 3:
      Serial.println("turn");
      Serial.println("forward");
      break;
    case 4:
      Serial.println("turn");
      Serial.println("forward");
      break;
  }
}

void loop() {
  
  //scanning netwroks and printing strength of 'ssid' netwrok
  float strength = signalStrength();

  if(strength>oldDistance){
    state = 1;
  }else{
    if(state==1){
      state=3;
    }
  }
  goDir(state);
  Serial.println(strength);
  oldDistance = strength;
}