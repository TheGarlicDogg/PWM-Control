#include <WiFi.h>
#include <stdio.h>
#include <cstring>
#include "esp_wifi.h"
#include "driver/ledc.h"
#define LED_PIN_1          5
#define LED_PIN_2          6 
#define LED_PIN_3          7              // Номер IO
#define LEDC_CHANNEL_1      0
#define LEDC_CHANNEL_2      2
#define LEDC_CHANNEL_3      4

             // От 0 до 5
#define LEDC_TIMER_RESOLUTION   12            // От 0 до 4095  (макс 14)
#define LEDC_BASE_FREQ          200           // Гц

String output;
const char* ssid = "garlicdogg_laptop";
const char* password = "gar123lic";
WiFiClient client;
int config[9];
IPAddress gateway;

void setup() {
  Serial.begin(9600);
  esp_wifi_set_ps (WIFI_PS_NONE);
  WiFi.begin(ssid,password);
  while(WiFi.status() != WL_CONNECTED){
    delay(500);
    Serial.print(",");
  }
  Serial.print("connected to wi-fi!");
  gateway = WiFi.gatewayIP();
  Serial.print("GATEWAY: ");
  Serial.println(gateway);
  ledcSetup(LEDC_CHANNEL_1, LEDC_BASE_FREQ, LEDC_TIMER_RESOLUTION);
  ledcSetup(LEDC_CHANNEL_2, LEDC_BASE_FREQ, LEDC_TIMER_RESOLUTION);
  ledcSetup(LEDC_CHANNEL_3, LEDC_BASE_FREQ, LEDC_TIMER_RESOLUTION);
  ledcAttachPin(LED_PIN_1, LEDC_CHANNEL_1);
  ledcAttachPin(LED_PIN_2, LEDC_CHANNEL_2);
  ledcAttachPin(LED_PIN_3, LEDC_CHANNEL_3);
  for (int i = 0; i < 3; i++){
    config[i] = 10;
  }
  for (int i = 3; i < 9; i++){
    config[i] = 0;
  }
}

void loop() {
  while(!client.connect(gateway, 8080)){
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
        Serial.print(c);
        if(c == 'c'){
          c = client.read();
          Serial.print(c);
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
        if(config[2] != 0) {
          
          int curFreq1 = ledcChangeFrequency(LEDC_CHANNEL_1, config[0], 12);
          if(curFreq1 == 0) Serial.println("Invalid frequency");
          ledcWrite(LEDC_CHANNEL_1, double(config[1]*4096/100)-1);
        }
        if(config[5] != 0) {
          int curFreq2 = ledcChangeFrequency(LEDC_CHANNEL_2, config[3], 12);
          if(curFreq2 == 0) Serial.println("Invalid frequency");
          ledcWrite(LEDC_CHANNEL_2, double(config[4]*4096/100)-1);
        }
        if(config[8] != 0){   
          int curFreq3 = ledcChangeFrequency(LEDC_CHANNEL_3, config[6], 12);
          if(curFreq3 == 0) Serial.println("Invalid frequency");
          ledcWrite(LEDC_CHANNEL_3, double(config[7]*4096/100)-1);
        }
        rdyToExecute = 0;
        unsigned long startTime = millis();
        bool flag = 0;
        int maxTime = max(config[2],config[5]);
        maxTime = max(maxTime, config[8]);
        while(millis()-startTime < maxTime*1000){
          if(millis()-startTime >= config[2]*1000) ledcWrite(LEDC_CHANNEL_1, 0);
          if(millis()-startTime >= config[5]*1000) ledcWrite(LEDC_CHANNEL_2, 0);
          if(millis()-startTime >= config[8]*1000) ledcWrite(LEDC_CHANNEL_3, 0);
          while(client.available()){
            char c = client.read();  
            if(c == 'c'){
              Serial.print(c);
              c = client.read();
              Serial.print(c);
              if (c=='s'){
                flag = 1;
                break;
              }
              if (c=='e'){
                ledcWrite(LEDC_CHANNEL_1, 0);
                ledcWrite(LEDC_CHANNEL_2, 0);
                ledcWrite(LEDC_CHANNEL_3, 0);
                return;
              }
            } else  client.flush();
          }
          if (flag) break; 
        }
        ledcWrite(LEDC_CHANNEL_1, 0);
        ledcWrite(LEDC_CHANNEL_2, 0);
        ledcWrite(LEDC_CHANNEL_3, 0);
      }
  }
}