# 🪖 Integrated Soldier Support System

![Viewers](https://hits.sh/github.com/saipreethamsanda/solidersupport.svg?style=flat-square&label=Viewers)

---

## 📌 Overview
The **Integrated Soldier Support System** is a wireless embedded solution designed to enhance the safety, monitoring, and communication of soldiers in critical environments.

The system uses the **ESP32 microcontroller** to monitor:
- Body Temperature (LM35)
- Heart Rate (HW827)
- GPS Location (NEO-6M)

All data is transmitted wirelessly via the **HC-12 module** to a base station, enabling real-time tracking and quick decision-making.

An emergency push button allows soldiers to instantly send alerts when assistance is required.

---

## 🎯 Key Features
- Real-time health monitoring  
- GPS-based location tracking  
- Long-range wireless communication  
- Emergency alert system  
- Low-cost and scalable design  

---

## 🏗️ System Architecture

### Transmitter Unit (Soldier Side)
LM35 Temperature Sensor  
HW827 Heart Rate Sensor  
GPS Module (NEO-6M)  
Push Button  
↓  
ESP32  
↓  
HC-12 Wireless Module  
↓  
Wireless Transmission  

### Receiver Unit (Base Station)
Wireless Transmission  
↓  
HC-12 Wireless Module  
↓  
ESP32  
↓  
Serial Monitor / Display  

### Overall Flow
LM35 + HW827 + GPS + Button → ESP32 → HC-12 → HC-12 → ESP32 → Base Station
---

## 🔩 Components

| Category        | Component                     | Quantity |
|----------------|-----------------------------|----------|
| Microcontroller | ESP32                        | 2        |
| Temperature     | LM35                         | 1        |
| Heart Rate      | HW827                        | 1        |
| Communication   | HC-12 Module                 | 2        |
| GPS             | NEO-6M                       | 1        |
| Display         | 16x2 LCD (I2C)               | 1        |
| Input           | Push Button                  | 1        |
| Misc            | Breadboard, Wires, USB Cable | —        |

---

## 🔌 Circuit Connections

### 📡 Transmitter (Soldier Unit)

**HC-12 Module**
- VCC → 5V (VIN)  
- GND → GND  
- TX → GPIO16  
- RX → GPIO17 (use voltage divider)  

**LM35 Temperature Sensor**
- VCC → 3.3V  
- GND → GND  
- OUT → GPIO34  

**Heart Rate Sensor**
- VCC → 3.3V  
- GND → GND  
- OUT → GPIO35  

**GPS Module (NEO-6M)**
- VCC → 3.3V / 5V  
- GND → GND  
- TX → GPIO4  
- RX → GPIO5  

**LCD (I2C)**
- SDA → GPIO21  
- SCL → GPIO22  

**Push Button**
- GPIO13 → Button → GND  

---

### 📡 Receiver (Base Station)

**HC-12 Module**
- VCC → 5V  
- GND → GND  
- TX → GPIO16  
- RX → GPIO17 

---

## ⚙️ Working
1. Sensors collect health data  
2. GPS provides location  
3. ESP32 processes the data  
4. HC-12 transmits data wirelessly  
5. Base station receives and displays data  
6. Emergency button sends alert signal  

---
