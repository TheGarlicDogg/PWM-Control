#include <WiFi.h>
#include <stdio.h>
#include <cstring>
#include "esp_wifi.h"
#include "driver/ledc.h"
#define STATUS_LED_GREEN_PIN 3
#define STATUS_LED_RED_PIN 4
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
bool debugLedStatus = false;
bool rdyToProcess = 0;
bool rdyToExecute = 0;
String data = "";
String tok;

void setup() {
  Serial.begin(9600);
  pinMode(STATUS_LED_GREEN_PIN, OUTPUT);
  pinMode(STATUS_LED_RED_PIN, OUTPUT);
  esp_wifi_set_ps (WIFI_PS_NONE);
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
  digitalWrite(STATUS_LED_GREEN_PIN, HIGH); // Отключен
  digitalWrite(STATUS_LED_RED_PIN, HIGH);
  Serial.println("nothing");
}

void loop() {
  WiFi.begin(ssid,password);
  while(WiFi.status() != WL_CONNECTED){ // Мигает желтым когда идет поключение к вайфай
    Serial.print(",");
    if(!debugLedStatus){
      debugLedStatus = true;
      digitalWrite(STATUS_LED_GREEN_PIN, LOW);
      digitalWrite(STATUS_LED_RED_PIN, LOW);
    } else{
      debugLedStatus = false;
      digitalWrite(STATUS_LED_GREEN_PIN, HIGH);
      digitalWrite(STATUS_LED_RED_PIN, HIGH);
    }
    delay(500);
  }
  Serial.print("connected to wi-fi!");

  digitalWrite(STATUS_LED_GREEN_PIN, LOW); //Горит желтым когда идет подкючение к серверу
  digitalWrite(STATUS_LED_RED_PIN, LOW);

  gateway = WiFi.gatewayIP();
  Serial.print("GATEWAY: ");
  Serial.println(gateway);

  while(!client.connect(gateway, 8080) && (WiFi.status() == WL_CONNECTED)){
    Serial.print(".");
    delay(500);
  }

  if(client.connected()){
    Serial.println("connected to server!");
    digitalWrite(STATUS_LED_RED_PIN, HIGH); //Горит зеленым когда подлючен к вай-фай и серверу
    data = "";
    rdyToProcess = 0;
    rdyToExecute = 0;
  }

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
          if((millis()-startTime)%1000 < 500){
            digitalWrite(STATUS_LED_GREEN_PIN, LOW);
          } else{
            digitalWrite(STATUS_LED_GREEN_PIN, HIGH);
          }
        }
        ledcWrite(LEDC_CHANNEL_1, 0);
        ledcWrite(LEDC_CHANNEL_2, 0);
        ledcWrite(LEDC_CHANNEL_3, 0);
        digitalWrite(STATUS_LED_GREEN_PIN, LOW);
      }
  }
}