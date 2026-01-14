/*
  Automatic Hand Sanitizer Dispenser
  ----------------------------------
  Detects a hand using an ultrasonic sensor and dispenses sanitizer
  using a servo motor.
  
  Components:
  - Arduino Uno
  - Ultrasonic Sensor (HC-SR04)
  - Servo Motor (SG90)
  
  Wiring:
  Ultrasonic Sensor:
    VCC -> 5V
    GND -> GND
    Trig -> Pin 9
    Echo -> Pin 10
  Servo Motor:
    VCC -> 5V
    GND -> GND
    Signal -> Pin 6
*/

#include <Servo.h>

Servo dispenserServo;

const int trigPin = 9;
const int echoPin = 10;
const int servoPin = 6;

long duration;
int distance;

void setup() {
  dispenserServo.attach(servoPin); // Attach servo to pin
  dispenserServo.write(0);         // Initial position
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  Serial.begin(9600);              // For debugging
}

void loop() {
  // Trigger the ultrasonic sensor
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  // Read the echo pulse
  duration = pulseIn(echoPin, HIGH);
  distance = duration * 0.034 / 2;  // Convert to cm

  Serial.print("Distance: ");
  Serial.println(distance);

  // If hand is detected within 10 cm
  if (distance > 0 && distance < 10) {
    dispenserServo.write(90);  // Rotate servo to press sanitizer
    delay(1000);               // Keep pressed for 1 second
    dispenserServo.write(0);   // Return servo to initial position
    delay(1000);               // Small delay to avoid multiple triggers
  }
}
