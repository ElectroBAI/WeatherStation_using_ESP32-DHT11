/*
* ESP32 DHT11 Temperature & Humidity Monitor
 * Serial Command Interface
 * 
 * LIBRARY REQUIREMENTS:
 * Install "DHT sensor library" by Adafruit via Arduino Library Manager
 * Also install "Adafruit Unified Sensor" dependency
 * 
 * WIRING INSTRUCTIONS:
 * DHT11 Sensor -> ESP32
 * ----------------
 * VCC (Pin 1)  -> 3.3V
 * DATA (Pin 2) -> GPIO 4 (can be changed below)
 * NC (Pin 3)   -> Not connected
 * GND (Pin 4)  -> GND
 * 
 * Note: A 10K pull-up resistor between DATA and VCC is recommended
 * (many DHT11 modules have this built-in)
 * 
 * SERIAL COMMANDS:
 * - Type "temperature" to get only Celsius temperature
 * - Type "humidity" to get only humidity percentage
 * - Type "both" to get both readings
 */

#include <DHT.h>

// DHT11 Configuration
#define DHTPIN 4          // GPIO pin connected to DHT11 data pin
#define DHTTYPE DHT11     // DHT sensor type

DHT dht(DHTPIN, DHTTYPE);

void setup() {
  // Initialize serial communication
  Serial.begin(115200);
  
  // Wait for serial port to connect
  delay(1000);
  
  Serial.println("ESP32 DHT11 Serial Control");
  Serial.println("===========================");
  Serial.println("Commands:");
  Serial.println("  temperature - Read temperature only");
  Serial.println("  humidity    - Read humidity only");
  Serial.println("  both        - Read both values");
  Serial.println();
  
  // Initialize DHT sensor
  dht.begin();
  
  Serial.println("DHT11 sensor initialized. Ready for commands.");
  Serial.println();
}

void loop() {
  // Check if data is available on serial port
  if (Serial.available() > 0) {
    // Read the incoming command
    String command = Serial.readStringUntil('\n');
    command.trim();  // Remove whitespace and newline characters
    command.toLowerCase();  // Convert to lowercase for case-insensitive matching
    
    // Read sensor data
    float h = dht.readHumidity();
    float t = dht.readTemperature();  // Celsius by default
    
    // Check if readings failed
    if (isnan(h) || isnan(t)) {
      Serial.println("Error: Failed to read from DHT sensor!");
      return;
    }
    
    // Process command
    if (command == "temperature") {
      Serial.println(t);
    } 
    else if (command == "humidity") {
      Serial.println(h);
    } 
    else if (command == "both") {
      Serial.print(t);
      Serial.print(",");
      Serial.println(h);
    } 
    else {
      Serial.println("Error: Unknown command. Use 'temperature', 'humidity', or 'both'");
    }
  }
  
  // Small delay to prevent overwhelming the sensor
  delay(100);
}
