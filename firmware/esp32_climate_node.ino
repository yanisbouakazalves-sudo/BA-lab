/*
 * ============================================================================
 * Project: SARL B.A. LAB — Environmental & Incubation Climate Node
 * File: firmware/esp32_climate_node.ino
 * Target: ESP32 Dev Module
 * License: MIT License
 * Description: Automated regulation of Temperature, Relative Humidity (RH),
 *              and periodic air purge for incubation chambers & bioprocesses.
 * ============================================================================
 */

#include <WiFi.h>
#include <DHT.h>

// --- Pin Definitions ---
#define DHTPIN 4          // GPIO4 connected to DHT22
#define DHTTYPE DHT22     // Sensor type DHT22 (AM2302)

#define RELAY_HEATER 16   // GPIO16 controls Heating Element
#define RELAY_HUMID 17    // GPIO17 controls Ultrasonic Humidifier
#define RELAY_FAN 18      // GPIO18 controls Fresh Air / Exhaust Fan (CO2 purge)

// --- Environmental Setpoints & Hysteresis ---
const float TEMP_SETPOINT_C = 24.0;   // Target Temperature in °C
const float TEMP_HYSTERESIS  = 0.5;    // Heating threshold tolerance

const float HUMID_SETPOINT  = 85.0;   // Target Relative Humidity %
const float HUMID_HYSTERESIS = 3.0;    // Humidity threshold tolerance

const unsigned long CO2_PURGE_INTERVAL_MS = 300000; // Purge cycle every 5 minutes (300s)
const unsigned long FAN_RUN_DURATION_MS   = 30000;  // Run fan for 30 seconds

// --- Global Variables & Timers ---
DHT dht(DHTPIN, DHTTYPE);
unsigned long lastSensorRead = 0;
unsigned long lastFanPurge   = 0;
const unsigned long SENSOR_INTERVAL = 2000; // Read sensors every 2 seconds

void setup() {
  Serial.begin(115200);
  Serial.println(F("[B.A. LAB] Initializing Environmental Climate Node..."));

  // Initialize Relays (Active LOW for standard relay boards)
  pinMode(RELAY_HEATER, OUTPUT);
  pinMode(RELAY_HUMID, OUTPUT);
  pinMode(RELAY_FAN, OUTPUT);

  digitalWrite(RELAY_HEATER, HIGH); // OFF
  digitalWrite(RELAY_HUMID, HIGH);  // OFF
  digitalWrite(RELAY_FAN, HIGH);    // OFF

  dht.begin();
  Serial.println(F("[B.A. LAB] Sensors and Actuators Initialized successfully."));
}

void loop() {
  unsigned long currentMillis = millis();

  // Periodic Sensor Reading Loop
  if (currentMillis - lastSensorRead >= SENSOR_INTERVAL) {
    lastSensorRead = currentMillis;

    float currentTemp = dht.readTemperature();
    float currentHumid = dht.readHumidity();

    if (isnan(currentTemp) || isnan(currentHumid)) {
      Serial.println(F("[ERROR] Failed to read from DHT sensor!"));
      return;
    }

    Serial.printf("[TELEMETRY] Temp: %.1f °C | RH: %.1f %%\n", currentTemp, currentHumid);

    // Thermal Regulation Control Loop
    if (currentTemp < (TEMP_SETPOINT_C - TEMP_HYSTERESIS)) {
      digitalWrite(RELAY_HEATER, LOW);  // Turn Heater ON
    } else if (currentTemp >= TEMP_SETPOINT_C) {
      digitalWrite(RELAY_HEATER, HIGH); // Turn Heater OFF
    }

    // Humidity Regulation Control Loop
    if (currentHumid < (HUMID_SETPOINT - HUMID_HYSTERESIS)) {
      digitalWrite(RELAY_HUMID, LOW);   // Turn Humidifier ON
    } else if (currentHumid >= HUMID_SETPOINT) {
      digitalWrite(RELAY_HUMID, HIGH);  // Turn Humidifier OFF
    }
  }

  // Periodic Air Purge Loop (CO2 Management)
  if (currentMillis - lastFanPurge >= CO2_PURGE_INTERVAL_MS) {
    Serial.println(F("[ACTION] Triggering Periodic Air Purge Cycle..."));
    digitalWrite(RELAY_FAN, LOW);       // Turn Exhaust Fan ON
    delay(FAN_RUN_DURATION_MS);
    digitalWrite(RELAY_FAN, HIGH);      // Turn Exhaust Fan OFF
    lastFanPurge = millis();
  }
}
