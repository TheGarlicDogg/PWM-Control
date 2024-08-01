#include <WiFi.h>
#include <stdio.h>
#include <cstring>
#include "esp_wifi.h"
#include "driver/ledc.h"
#define LED_PIN          0             // Номер IO
#define LEDC_CHANNEL      0             // От 0 до 5
#define LEDC_TIMER_RESOLUTION   12            // От 0 до 4095  (макс 14)
#define LEDC_BASE_FREQ          200           // Гц

String output;
const char* ssid = "garlicdogg_laptop";
const char* password = "gar123lic";
WiFiClient client;
int config[3];

void setup() {
  Serial.begin(9600);
  esp_wifi_set_ps (WIFI_PS_NONE);
  WiFi.begin(ssid,password);
  while(WiFi.status() != WL_CONNECTED){
    delay(500);
    Serial.print(".");
  }
  Serial.print("connected to wi-fi!");
  
  ledcSetup(LEDC_CHANNEL, LEDC_BASE_FREQ, LEDC_TIMER_RESOLUTION);
  ledcAttachPin(LED_PIN, LEDC_CHANNEL);
}

void loop() {
  while(!client.connect("192.168.137.1", 8080)){
    delay(500);
    Serial.print(".");
  }
  Serial.print("connected to server!");
  String data = "";
  String tok;
  bool rdyToProcess = 0;
  bool rdyToExecute = 0;
  while (client.connected()) {            
      while (client.available()) {           
        char c = client.read();   
        if(c == 'c'){
          c = client.read();
          if (c=='e') return;
        } else{
          if(c == '\n'){
            rdyToProcess = 1;
            break;
          }
          data += c;
        }
      }
      if(rdyToProcess){
        tok = strtok(const_cast<char*>(data.c_str()), " ");
        int i = 0;
        while (tok != 0) {
          config[i] = tok.toInt();
          tok = strtok(0, " ");
          i++;
        }
        rdyToProcess = 0;
        rdyToExecute = 1;
      }
      if (rdyToExecute){
        data = "";
        int curFreq = ledcChangeFrequency(0, config[0], 12);
        if(curFreq == 0) Serial.println("Invalid frequency");
        ledcWrite(LEDC_CHANNEL, double(config[1]*4096/100)-1);
        rdyToExecute = 0;
        unsigned long startTime = millis();
        bool flag = 0;
        while(millis()-startTime < config[2]*1000){
          while(client.available()){
            char c = client.read();  
            if(c == 'c'){
              c = client.read();
              if (c=='s'){
                flag = 1;
                break;
              }
              if (c=='e') return;
            } else  client.flush();
          }
          if (flag) break; 
        }
        ledcWrite(LEDC_CHANNEL, 0);
      }
  }
}