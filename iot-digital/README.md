# 🤖 IoT & Environmental Automation Firmware — Digital Layer

This folder contains the firmware, pinouts, and logic control loops for the automated environmental management systems of **SARL B.A. LAB**.

The digital layer is built on the ESP32 microcontroller (Dual-Core 240MHz, Wi-Fi/BLE), managing closed-loop actuation for microclimate regulation in incubation rooms, greenhouses, and temporary immersion bioreactors without blocking execution loops.

---

## 1. System Architecture & Pin Mapping

The architecture follows a deterministic closed-loop pattern:  
**Sensors ➔ Threshold Processing ➔ Relay Actuation**.

| Component | Type | Connection / Protocol | ESP32 Target Pin | Functional Role |
| :--- | :--- | :--- | :--- | :--- |
| **SCD4x / SCD30** | Sensor | I2C (SDA / SCL) | GPIO 21 / GPIO 22 | NDIR CO₂ Concentration, Ambient Temp & RH% |
| **Soil Moisture Sensor** | Sensor | Analog (ADC1) | GPIO 34 | Substrate / Technosoil Moisture Level |
| **Relay Module 1** | Actuator | Digital Output | GPIO 25 | Solenoid Valve / 12V Water Pump |
| **Relay Module 2** | Actuator | Digital Output | GPIO 26 | High-CFM Extraction Fan (CO₂ Purge) |

---

## 2. Firmware Architecture & Logic

The core code (`/firmware/src/main.cpp`) relies strictly on **non-blocking time execution** (`millis()`) to ensure sensor sampling intervals and actuator pulses execute independently without locking the processor thread.

### Control Loops:
* **Dynamic Irrigation:** Activates the water solenoid/pump if substrate moisture drops below defined operational thresholds.
* **CO₂ Purge Routine:** Triggers air extraction fans when CO₂ concentration exceeds thresholds to prevent fruiting body deformation in fungal culture or stagnation in plant chambers.

---

## 3. Core Source Code (`src/main.cpp`)

```cpp
// ==========================================================================
// SARL B.A. LAB — Core Environmental Automation Firmware (v1.0.0)
// Target Hardware: ESP32 DevKitC v4
// ==========================================================================

#include <Arduino.h>

// --- Configuration Constants ---
const unsigned long SENSOR_INTERVAL = 5000;    // Sample sensors every 5000 ms
const int SOIL_MOISTURE_THRESHOLD = 45;         // Minimum moisture (%)
const int CO2_HIGH_THRESHOLD = 1200;           // Trigger extraction above this PPM

// --- Pin Definitions ---
const int PIN_SOIL_MOISTURE = 34;
const int PIN_RELAY_PUMP = 25;
const int PIN_RELAY_FAN = 26;

// --- State Variables ---
unsigned long lastSensorReadTime = 0;
bool isIrrigating = false;
bool isVentilating = false;

// --- Function Declarations ---
void readSensorsAndAction();
int getSoilMoisturePercent();
int getCO2Levels();

void setup() {
    Serial.begin(115200);
    
    pinMode(PIN_RELAY_PUMP, OUTPUT);
    pinMode(PIN_RELAY_FAN, OUTPUT);
    pinMode(PIN_SOIL_MOISTURE, INPUT);

    // Initial Relay State (OFF - Active LOW/HIGH dependent on module)
    digitalWrite(PIN_RELAY_PUMP, LOW);
    digitalWrite(PIN_RELAY_FAN, LOW);

    Serial.println(F("[INFO] SARL B.A. LAB IoT Node Initialized successfully."));
}

void loop() {
    unsigned long currentMillis = millis();

    // Non-blocking timer check
    if (currentMillis - lastSensorReadTime >= SENSOR_INTERVAL) {
        lastSensorReadTime = currentMillis;
        readSensorsAndAction();
    }
}

void readSensorsAndAction() {
    int moisture = getSoilMoisturePercent();
    int co2 = getCO2Levels();

    Serial.printf("[DATA] Substrate Moisture: %d%% | CO2 Level: %d PPM\n", moisture, co2);

    // Irrigation Control Logic
    if (moisture < SOIL_MOISTURE_THRESHOLD) {
        digitalWrite(PIN_RELAY_PUMP, HIGH);
        isIrrigating = true;
        Serial.println(F("[ACTION] Soil Moisture Low -> Water Pump STARTED"));
    } else {
        digitalWrite(PIN_RELAY_PUMP, LOW);
        isIrrigating = false;
    }

    // CO2 Purge Logic
    if (co2 > CO2_HIGH_THRESHOLD) {
        digitalWrite(PIN_RELAY_FAN, HIGH);
        isVentilating = true;
        Serial.println(F("[ACTION] High CO2 Level -> Extraction Fan STARTED"));
    } else {
        digitalWrite(PIN_RELAY_FAN, LOW);
        isVentilating = false;
    }
}

int getSoilMoisturePercent() {
    int rawAnalog = analogRead(PIN_SOIL_MOISTURE);
    // Calibration map: rawAnalog 4095 (dry) -> 0%, 1500 (wet) -> 100%
    int percentage = map(rawAnalog, 4095, 1500, 0, 100);
    return constrain(percentage, 0, 100);
}

int getCO2Levels() {
    // Simulated/Placeholder read - Replace with SCD30/SCD4x I2C library call
    return 800; 
}
```

---

## 4. Build & Deployment

### Recommended Toolchain
* **Framework:** PlatformIO / VS Code Extension
* **Board Profile:** `esp32dev`
* **Upload Speed:** `921600`
* **Monitor Speed:** `115200`

### Quick Flash Command
```bash
# Compile and flash via PlatformIO CLI
pio run --target upload --environment esp32dev
```
