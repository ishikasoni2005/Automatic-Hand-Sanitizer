# 🧴 Automatic Hand Sanitizer Dispenser

## 📌 Overview
This project is an **Arduino-based Automatic Hand Sanitizer Dispenser** that provides a **touchless sanitizing solution**. The system detects a user's hand using an **IR sensor** and automatically activates a **servo motor** to press the sanitizer pump and dispense liquid.

The device helps improve hygiene by **eliminating the need to touch sanitizer bottles**, making it suitable for **public spaces, classrooms, offices, and healthcare environments**.

---

## ✨ Features

- 🤖 **Automatic hand detection** using IR sensor  
- ⚙️ **Servo motor controlled pump mechanism**  
- 🔌 **Simple Arduino-based hardware design**  
- 🧩 **Low-cost and easy to build prototype**  
- 🧼 Promotes **contactless hygiene**

---

## 🧰 Components Required

- Arduino Uno / Arduino Nano  
- IR Sensor Module  
- Servo Motor (SG90 recommended)  
- Breadboard  
- Jumper Wires  
- 5V Power Supply  
- Sanitizer Bottle with Pump  

---

## ⚙️ Working Principle

1. The **IR sensor continuously monitors** the area in front of the dispenser.
2. When a hand is placed near the sensor, it **detects the object** and sends a signal to the Arduino.
3. The **Arduino processes the signal** and activates the servo motor.
4. The **servo motor rotates** to press the sanitizer pump.
5. After dispensing sanitizer, the servo **returns to its initial position**.

---

## 🔌 Circuit Connections

| Component | Arduino Pin |
|-----------|-------------|
| IR Sensor OUT | D2 |
| Servo Signal | D9 |
| IR Sensor VCC | 5V |
| IR Sensor GND | GND |
| Servo VCC | 5V |
| Servo GND | GND |

---

## 💻 Arduino Code

The main logic is implemented in `AutomaticHandSanitizer.ino`.

```cpp
#include <Servo.h>

Servo myServo;
int irSensor = 2;

void setup() {
  pinMode(irSensor, INPUT);
  myServo.attach(9);
  myServo.write(0);
}

void loop() {
  int handDetected = digitalRead(irSensor);

  if(handDetected) {
    myServo.write(90); // Dispense sanitizer
    delay(1000);
    myServo.write(0);  // Return to initial position
  }
}

🚀 How to Run the Project
Connect all hardware components according to the circuit connections.
Install Arduino IDE on your computer.
Upload the file:
AutomaticHandSanitizer.ino
Power the Arduino using USB or a 5V adapter.
Place your hand near the sensor to dispense sanitizer automatically.


🔮 Future Improvements
Add Ultrasonic Sensor for more accurate hand detection
Implement battery-powered portable design
Add LCD display to monitor sanitizer usage
Integrate IoT features to track sanitizer levels remotely

