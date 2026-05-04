# ESP32 DHT11 Sensor Monitor

A lightweight Serial interface for real-time temperature and humidity monitoring using an **ESP32**. 

---

## Features
*   **Simple Command Interface**: Get data on-demand by typing `temperature`, `humidity`, or `both`.
*   **Error Handling**: Built-in validation to detect if the sensor is disconnected or failing to read.
*   **Case-Insensitive Parsing**: Commands work regardless of capitalization.
*   **Comma-Separated Values (CSV)**: The `both` command outputs data in a format ready for data logging or spreadsheet import.

---

## Hardware Requirements
This project utilizes hardware common in the **IoT & Low-Power** sector, which often features small-form-factor boards with wireless capabilities.

*   **Microcontroller**: ESP32 (38-pin or 30-pin variant).
*   **Sensor**: DHT11 Temperature & Humidity Sensor.
*   **Resistor**: 10K Ohm pull-up resistor (if not using a pre-mounted module).

### Wiring Diagram
| DHT11 Pin | Connection | ESP32 Pin |
| :--- | :--- | :--- |
| **VCC (1)** | Power | 3.3V |
| **DATA (2)** | Signal | GPIO 4 |
| **NC (3)** | No Connect | N/A |
| **GND (4)** | Ground | GND |

---

## Software Setup
1.  **Libraries**: Install the following via the Arduino Library Manager:
    *   `DHT sensor library` by Adafruit.
    *   `Adafruit Unified Sensor` (dependency).
2.  **Serial Monitor**: Set your baud rate to `115200`.

---

## Command Syntax
Type these commands into your Serial Monitor to interact with the ESP32:

| Command | Output Example | Description |
| :--- | :--- | :--- |
| `temperature` | `24.50` | Returns current temperature in Celsius. |
| `humidity` | `45.00` | Returns current humidity percentage. |
| `both` | `24.50,45.00` | Returns Temperature and Humidity separated by a comma. |

---
