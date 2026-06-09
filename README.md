# 🧴 Automatic Hand Sanitizer Dispenser

An **Arduino-based touchless hand sanitizer dispenser** that detects a user's hand via an IR sensor and activates a servo motor to press the pump automatically — no contact required.

Suitable for **classrooms, offices, public spaces, and healthcare environments**.

---

## ✨ Features

- 🤖 Touchless hand detection via IR sensor
- ⚙️ Servo motor-controlled pump mechanism
- 🔌 Simple Arduino-based hardware design
- 💸 Low-cost, easy-to-build prototype
- 🧼 Promotes contactless hygiene

---

## 🧰 Components Required

| Component | Specification |
|-----------|---------------|
| Microcontroller | Arduino Uno / Nano |
| Sensor | IR Sensor Module |
| Actuator | Servo Motor (SG90) |
| Power | 5V Supply / USB |
| Other | Breadboard, Jumper Wires, Sanitizer Bottle with Pump |

---

## ⚙️ Working Principle

1. IR sensor continuously monitors the area in front of the dispenser
2. Hand detected → signal sent to Arduino
3. Arduino activates servo motor
4. Servo rotates to press the pump → sanitizer dispensed
5. Servo returns to initial position

---

## 🔌 Circuit Connections

| Component | Arduino Pin |
|-----------|-------------|
| IR Sensor OUT | D2 |
| IR Sensor VCC | 5V |
| IR Sensor GND | GND |
| Servo Signal | D9 |
| Servo VCC | 5V |
| Servo GND | GND |

---

## 💻 Code

**File:** `AutomaticHandSanitizer.ino`

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
  if (handDetected) {
    myServo.write(90);  // Press pump
    delay(1000);
    myServo.write(0);   // Return to position
  }
}
```

---

## 🚀 How to Run

1. Wire all components per the circuit table above
2. Open **Arduino IDE** and load `AutomaticHandSanitizer.ino`
3. Upload to Arduino board
4. Power via USB or 5V adapter
5. Place hand near sensor → sanitizer dispensed automatically

---

## 🔮 Future Improvements

- [ ] Ultrasonic sensor for more accurate hand detection
- [ ] Battery-powered portable design
- [ ] LCD display to monitor sanitizer levels
- [ ] IoT integration for remote level tracking
