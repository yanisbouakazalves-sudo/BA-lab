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
    
    pinMode(PIN_RELAY_PUMP, OUTPUT);
    pinMode(PIN_RELAY_FAN, OUTPUT);
    
    // Initialize Actuators to OFF (Active Low/High depending on relay board)
    digitalWrite(PIN_RELAY_PUMP, LOW);
    digitalWrite(PIN_RELAY_FAN, LOW);
    
    Serial.println("[INIT] SARL B.A. LAB Automation System Online.");
}

void loop() {
    unsigned long currentMillis = millis();
    
    // Non-blocking execution loop
    if (currentMillis - lastSensorReadTime >= SENSOR_INTERVAL) {
        lastSensorReadTime = currentMillis;
        readSensorsAndAction();
    }
}

int getSoilMoisturePercent() {
    int rawAnalog = analogRead(PIN_SOIL_MOISTURE);
    // Map your specific sensor calibration values (Raw Min/Max to 0-100%)
    int percent = map(rawAnalog, 4095, 1500, 0, 100); 
    return constrain(percent, 0, 100);
}

int getCO2Levels() {
    // Placeholder for I2C SCD4x sensor data read
    // Returns simulated value or actual sensor registry read
    return 800; 
}

void readSensorsAndAction() {
    int currentMoisture = getSoilMoisturePercent();
    int currentCO2 = getCO2Levels();
    
    Serial.printf("[DATA] Soil Moisture: %d%% | CO2: %d PPM\n", currentMoisture, currentCO2);
    
    // --- Irrigation Control Loop ---
    if (currentMoisture < SOIL_MOISTURE_THRESHOLD && !isIrrigating) {
        digitalWrite(PIN_RELAY_PUMP, HIGH);
        isIrrigating = true;
        Serial.println("[ACTION] Soil dry. Activating Irrigation Pump.");
    } else if (currentMoisture >= (SOIL_MOISTURE_THRESHOLD + 5) && isIrrigating) {
        // Includes a +5% hysteresis to prevent rapid relay clicking
        digitalWrite(PIN_RELAY_PUMP, LOW);
        isIrrigating = false;
        Serial.println("[ACTION] Target moisture reached. Deactivating Pump.");
    }
    
    // --- Ventilation Control Loop ---
    if (currentCO2 > CO2_HIGH_THRESHOLD && !isVentilating) {
        digitalWrite(PIN_RELAY_FAN, HIGH);
        isVentilating = true;
        Serial.println("[ACTION] Critical CO2 level. Activating Extraction Fan.");
    } else if (currentCO2 <= (CO2_HIGH_THRESHOLD - 200) && isVentilating) {
        digitalWrite(PIN_RELAY_FAN, LOW);
        isVentilating = false;
        Serial.println("[ACTION] CO2 stabilized. Deactivating Fan.");
    }
}
