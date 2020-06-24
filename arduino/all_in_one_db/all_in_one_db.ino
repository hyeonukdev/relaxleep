// 
// 센서값 전달 순서는 습도, 온도, 이산화탄소, 소리, 심박, 산소포화도 순으로 한다.
//-------------------------------------------------------

bool flag = true;
bool flag2 = true;

// DHT11 온습도 센서
#include "DHT.h"
#define DHTPIN 4
#define DHTTYPE DHT11
DHT dht(DHTPIN, DHTTYPE);
//---------------------------------------------

// MAX9814 소리감지센서
//const int sampleWindow = 50; // Sample window width in mS (50 mS = 20Hz)
const int sampleWindow = 1000;
unsigned int sample;
//-----------------------------------------

// MAX30100 심박,산소포화도 센서
#include <Wire.h>
#include "MAX30100_PulseOximeter.h"
//#define REPORTING_PERIOD_MS     1000
PulseOximeter pox;
uint32_t tsLastReport = 0;

void onBeatDetected()
{
    //Serial.println("Beat!");
}
//----------------------------------------

// 읽기 시간 간격 설정
unsigned long previousMillis = 0;
const long interval = 1000;
//-----------------------------------


void setup()
{

// Switch & LED  
    pinMode(8, OUTPUT);
    pinMode(7, INPUT);
// MAX30100 심박, 산소포화도 센서
    Serial.begin(115200);

    //Serial.print("Initializing pulse oximeter..");

    if (!pox.begin()) {
        //Serial.println("FAILED");
        //for(;;);
    } else {
        //Serial.println("SUCCESS");
    }
    pox.setIRLedCurrent(MAX30100_LED_CURR_7_6MA);
    pox.setOnBeatDetectedCallback(onBeatDetected);
   //-----------------------------------------------------
      
}


void loop()
{
    // Switch & LED
    int readValue = digitalRead(7);  // 스위치 핀
    //Serial.println(readValue);

    if (readValue == HIGH) {
      digitalWrite(8,HIGH);
      flag = false;
      if(flag2)
        setup();
    }
    else {
      digitalWrite(8,LOW);
      flag = true;
    }
  
   if(flag) {  
       flag2 = true;     
       // DHT11 온습도 감지 센서   
       int h = dht.readHumidity();
       int t = dht.readTemperature();
       Serial.print("!");
       //Serial.print("Humidity: ");         // DB 저장 시 주석처리할 것
       Serial.print(h);
       Serial.print(",");
       //Serial.print("Temperature: ");      // DB 저장 시 주석처리할 것
       Serial.print(t);   
       //Serial.print("C");               	// DB 저장 시 주석처리할 것
       Serial.print(",");					
       //Serial.print("\n");					// DB 저장 시 주석처리할 것
       delay(1000);
       //----------------------------------
       
       // MQ135 이산화탄소 센서
        float sensor_volt;
        float R0;
        float RS;
        float ratio; // RS/R0;
        float BAC;
        int sensorValue = analogRead(A1);
        sensor_volt=(float)sensorValue/1024.0*5.0;
        RS = (5.0-sensor_volt)/sensor_volt;
        R0 = 29.03; 
        ratio = RS/R0;    
        BAC = 114.3544*pow(ratio,-2.93599);
        //Serial.print("CO2: ");            // DB 저장 시 주석처리할 것
        Serial.print(BAC); 
        //Serial.print("ppm");             // DB 저장 시 주석처리할 것
        Serial.print(",");
        //Serial.println();   				// DB 저장 시 주석처리할 것
        delay(1000);
       //------------------------------------------
       
       // MAX9814 소리감지센서
        unsigned long startMillis = millis();  
        unsigned int peakToPeak = 0;  
        unsigned int signalMax = 0;
        unsigned int signalMin = 1024;
    
        while (millis() - startMillis < sampleWindow) 
        {
          sample = analogRead(0);
          if (sample < 1024) 
          {
             if (sample > signalMax)
             {
                signalMax = sample; 
             }
             else if (sample < signalMin)
             {
                signalMin = sample; 
             }
          }
        } 
       peakToPeak = signalMax - signalMin; 
       double volts = (peakToPeak * 5.0) / 1024; 
    
       //Serial.print("Sound: ");            // DB 저장 시 주석처리할 것
       Serial.print(volts);
       //Serial.print("V");                   // DB 저장 시 주석처리할 것
       //Serial.print("!");
       //Serial.println();   					// DB 저장 시 주석처리할 것
       //---------------------------------------------------
   }
   else {
       // MAX30100 심박, 산소포화도 센서
       flag2 = false;
       pox.update();
       unsigned long currentMillis = millis();   
       if(currentMillis - previousMillis >= interval) 
       {
          previousMillis = currentMillis;
          Serial.print("@");   
          //Serial.print("Heart rate: ");      // DB 저장 시 주석처리할 것
          Serial.print(pox.getHeartRate());
          //Serial.print("bpm");            // DB 저장 시 주석처리할 것
          Serial.print(",");
          //Serial.print("SpO2: ");            // DB 저장 시 주석처리할 것
          Serial.print(pox.getSpO2());
          //Serial.print("%");            // DB 저장 시 주석처리할 것
          //Serial.print("@");   
          //Serial.println();   				// DB 저장 시 주석처리할 것
       }
   } 
   
}