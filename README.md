# Automatic Hand Sanitizer

## Overview
This project is an **Arduino-based automatic hand sanitizer dispenser**. It detects hands using an IR sensor and automatically dispenses sanitizer through a servo-controlled pump. The device is designed for hygiene and convenience, especially in public spaces.

---

## Features
- Automatic hand detection using **IR sensor**
- Controlled dispensing using **servo motor**
- Simple **Arduino-based circuit**
- Compact and easy to build

---

## Components Required
- Arduino Uno / Arduino Nano
- IR Sensor Module
- Servo Motor
- Jumper Wires
- Breadboard
- 5V Power Supply
- Sanitizer bottle with pump

---

## Arduino Code
The Arduino code is included in `AutomaticHandSanitizer.ino`. It detects hands using the IR sensor and rotates the servo motor to dispense sanitizer automatically.

```cpp
// Example snippet from AutomaticHandSanitizer.ino
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
    myServo.write(0);
  }
}
