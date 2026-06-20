#include <WiFi.h>
#include "time.h" 
#include <Wire.h>
#include <DS3231.h>

// --- Configuration ---
const char* ssid     = "rock-bottom";
const char* password = "milkshakes24-7";

// NTP Server
const char* ntpServer = "pool.ntp.org";

// FULL POSIX TIMEZONE for US Mountain Time:
// MST7MDT,M3.2.0,M11.1.0 means:
// - Standard time is MST (offset 7 hours behind UTC)
// - Daylight time is MDT
// - DST starts 2nd Monday of March (M3.2.0)
// - DST ends 1st Sunday of November (M11.1.0)
const char* timeZoneString = "MST7MDT,M3.2.0,M11.1.0"; 

DS3231 myRTC;

void setup() {
  Serial.begin(115200);
  Wire.begin();
  delay(500);
  
  Serial.println("\n--- ESP32 RTC & NTP Sync (Local Time) ---");

  WiFi.begin(ssid, password);
  Serial.print("Connecting to WiFi...");
  
  unsigned long startAttemptTime = millis();
  while (WiFi.status() != WL_CONNECTED && millis() - startAttemptTime < 10000) {
    delay(500);
    Serial.print(".");
  }

  if (WiFi.status() == WL_CONNECTED) {
    Serial.println("\nWiFi Connected!");
    configTzTime(timeZoneString, ntpServer);
    
    Serial.print("Waiting for NTP time...");
    startAttemptTime = millis();
    struct tm timeinfo;
    
    // getLocalTime() is the magic function here. 
    // It converts the UTC network time into your Local Time based on timeZoneString.
    while (!getLocalTime(&timeinfo) && (millis() - startAttemptTime < 5000)) {
      delay(500);
      Serial.print(".");
    }

    if (getLocalTime(&timeinfo)) {
      Serial.println("\nNTP Sync Successful!");
      updateRTCtoLocalTime(&timeinfo);
    } else {
      Serial.println("\nNTP timeout: Using existing RTC.");
    }
  } else {
    Serial.println("\nWiFi failed: Falling back to RTC.");
  }
}

void loop() {
  delay(1000);

  bool centuryBit, h12, hPM;

  byte year   = myRTC.getYear(); 
  byte month  = myRTC.getMonth(centuryBit); 
  byte date   = myRTC.getDate();         
  byte hour   = myRTC.getHour(h12, hPM); 
  byte minute = myRTC.getMinute();
  byte second = myRTC.getSecond();

  Serial.print("Local Date: 20"); 
  Serial.print(year); Serial.print('/');
  Serial.print(month); Serial.print('/');
  Serial.print(date); 
  
  Serial.print(" Time: ");
  // Logic to print in 24h format regardless of RTC hardware mode
  if (h12) {
    int displayHour = hour;
    if (hPM && displayHour != 12) displayHour += 12;
    if (!hPM && displayHour == 12) displayHour = 0;
    if (displayHour < 10) Serial.print('0');
    Serial.print(displayHour);
  } else {
    if (hour < 10) Serial.print('0');
    Serial.print(hour);
  }

  Serial.print(':');
  if (minute < 10) Serial.print('0');
  Serial.print(minute);
  Serial.print(':');
  if (second < 10) Serial.print('0');
  Serial.println(second);
}

// This function takes the LOCAL time structure and writes it to hardware registers
void updateRTCtoLocalTime(struct tm* timeinfo) {
  Serial.println("Writing Local Time to RTC Hardware...");
  
  myRTC.setClockMode(false); // Set to 24h mode for easier writing

  // timeinfo->tm_year is years since 1900 (e.g., 124 for 2024)
  // Your library wants offset from 2000 (e.g., 24)
  myRTC.setYear(timeinfo->tm_year - 100); 
  
  // tm_mon is 0-11, your lib wants 1-12
  myRTC.setMonth(timeinfo->tm_mon + 1);    
  
  myRTC.setDate(timeinfo->tm_mday);
  myRTC.setDoW(timeinfo->tm_wday == 0 ? 7 : timeinfo->tm_wday); // Convert Sunday 0 to 7 if needed
  myRTC.setHour(timeinfo->tm_hour);
  myRTC.setMinute(timeinfo->tm_min);
  myRTC.setSecond(timeinfo->tm_sec);
  
  Serial.println("RTC updated with Local Time.");
}