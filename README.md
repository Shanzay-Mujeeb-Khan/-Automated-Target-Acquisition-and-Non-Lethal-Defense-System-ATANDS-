# ATANDS — Automated Target Acquisition and Non-Lethal Defense System
**ATANDS (Automated Target Acquisition and Non-Lethal Defense System)** is an Arduino-powered semi-automated defense turret project. It continuously scans a 180-degree field of view using an ultrasonic sensor mounted on a servo motor. When a target enters the 40 cm threshold, the system locks onto the angle, displays target information on an I2C LCD, sounds a buzzer alarm, and prompts the operator for a manual launch.
---
## 🛠️ Features
* **180° Area Radar Scan:** Smooth sweep using an SG90 Servo Motor.
* **Real-time Target Tracking:** HC-SR04 Ultrasonic Sensor measures real-time distance.
* **Target Lock Alarm:** Audio alert via Buzzer when a target is within 40 cm.
* **Live HUD Display:** 16x2 I2C LCD shows current angle, distance, and lock status.
* **Clean Two-Layer Enclosure:** Internal wiring hidden inside a custom base box for a neat presentation.
---
## 📌 Hardware Components
* **Microcontroller:** Arduino Uno
* **Range Sensor:** HC-SR04 Ultrasonic Sensor
* **Actuator:** SG90 Servo Motor
* **Display:** 16x2 LCD Display with I2C Module
* **Alert Unit:** Buzzer Module
* **Launcher:** Custom T-shape manual foam dart launcher
* **Power & Wiring:** Breadboard, Jumper Wires (M-M, M-F), USB Cable
---
## 🔌 Pin Mapping

| Component | Pin / Connection | Arduino Uno Pin |
| :--- | :--- | :--- |
| **HC-SR04 Ultrasonic** | Trigger Pin | Digital Pin 10 |
|  | Echo Pin | Digital Pin 11 |
|  | VCC / GND | 5V / GND |
| **SG90 Servo Motor** | Signal Pin | Digital Pin 9 |
|  | VCC / GND | 5V / GND |
| **16x2 LCD (I2C)** | SDA | Analog Pin A4 |
|  | SCL | Analog Pin A5 |
|  | VCC / GND | 5V / GND |
| **Buzzer** | Positive (+) | Digital Pin 4 |
|  | Negative (-) | GND |

---
## 💻 Software & Libraries Needed
* **Arduino IDE** (v2.0 or higher recommended)
* Required Libraries:
  * `<Wire.h>` (Built-in)
  * `<Servo.h>` (Built-in)
  * `<LiquidCrystal_I2C.h>`
---
## 🚀 How to Run
1. Clone this repository or download the `.ino` sketch file.
2. Connect hardware according to the **Pin Mapping** table.
3. Open `ATANDS_ino.ino` in Arduino IDE.
4. Select **Arduino Uno** under `Tools > Board` and set the correct **COM Port**.
5. Upload the code to your Arduino Uno.
---
## 👩‍💻 Author
Developed as an academic hardware prototyping project focusing on embedded systems, sensor integration, and structural design.
