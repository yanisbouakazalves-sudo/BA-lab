# 🤖 IoT & Automation — Digital Layer

This folder contains the firmware, hardware schematics, and configuration files for the automated environmental control loops of the SARL B.A. LAB platform. 

The digital layer is designed around the **ESP32** microcontroller, chosen for its processing power, dual-core architecture, and low cost, allowing full automation of irrigation, ventilation, and data logging with zero manual intervention.

---

## 1. System Architecture & Pin Mapping

The system operates on a closed-loop feedback mechanism: **Sensors ➔ Threshold Analysis ➔ Actuator Triggering**.

### Hardware Pinout Configuration (ESP32)

| Component | Type | Connection/Protocol | Target Pin (ESP32) | Functional Role |
| :--- | :--- | :--- | :--- | :--- |
| **SCD4x / SCD30** | Sensor | I2C (SDA / SCL) | GPIO 21 / GPIO 22 | CO₂ concentration, Ambient Temp & Humidity |
| **Soil Moisture** | Sensor | Analog | GPIO 34 (ADC1) | Substrate/Technosoil moisture level |
| **Relay 1 (Water)** | Actuator | Digital Output | GPIO 25 | Solenoid Valve / 12V Irrigation Pump |
| **Relay 2 (Air)** | Actuator | Digital Output | GPIO 26 | Extraction Fan (CO₂ purge for fungi/plants) |

---

## 2. Firmware Architecture

The core firmware (`/firmware/src/main.cpp`) utilizes non-blocking timing routines (`millis()`) to ensure sensor sampling and actuator states are managed independently without freezing the microcontroller.

### Core Automation Logic:
1. **Dynamic Irrigation:** Triggers the water valve if soil moisture drops below a critical threshold, maintaining optimal matrix potential.
2. **CO₂ Purge Loop:** Automatically activates extraction fans if CO₂ levels exceed target thresholds (crucial for both fungal fruiting bodies and plant respiration control).

// ==========================================================================
// SARL B.A. LAB — Core Environmental Automation Firmware (v1.0.0)
// Target Hardware: ESP32 DevKitC v4
// ==========================================================================

#include <Arduino.h>

// --- Configuration Constants ---
const unsigned long SENSOR_INTERVAL = 5000; // Sample sensors every 5 seconds
const int SOIL_MOISTURE_THRESHOLD   = 45;   // Target minimum moisture (%)
const int CO2_HIGH_THRESHOLD        = 1200; // Trigger extraction above this PPM

// --- Pin Definitions ---
const int PIN_SOIL_MOISTURE = 34; 
const int PIN_RELAY_PUMP    = 25;
const int PIN_RELAY_FAN     = 26;

// --- State Variables ---
unsigned long lastSensorReadTime = 0;
bool isIrrigating = false;
bool isVentilating = false;

// --- Function Declarations ---
void readSensorsAndAction();
int getSoilMoisturePercent();
int getCO2Levels();

void setup() {
    Serial.begin(111500);
