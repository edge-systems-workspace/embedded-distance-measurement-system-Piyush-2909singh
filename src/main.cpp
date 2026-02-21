#include <Arduino.h>

/**
 * @file main.cpp
 * @brief Embedded Distance Measurement using Ultrasonic Sensor
 * @author Piyush-2909singh
 * @date 2026-02-21
 *
 * @details
 * Measures distance using the HC-SR04 ultrasonic sensor
 * and displays formatted output via the Serial Monitor.
 */

// Pin Definitions
#define TRIG_PIN 9
#define ECHO_PIN 10

// Timing and Distance Variables
long duration;
float distance;

/**
 * @brief System setup and peripheral initialization.
 */
void setup() {
    Serial.begin(9600);

    pinMode(TRIG_PIN, OUTPUT);
    pinMode(ECHO_PIN, INPUT);

    Serial.println("Ultrasonic Distance System Initialized...");
    Serial.println("---------------------------------------");
}

/**
 * @brief Main execution loop: Triggers sensor and calculates distance.
 */
void loop() {
    // Ensure Trigger pin is clear
    digitalWrite(TRIG_PIN, LOW);
    delayMicroseconds(2);

    // Send 10us pulse to trigger measurement
    digitalWrite(TRIG_PIN, HIGH);
    delayMicroseconds(10);
    digitalWrite(TRIG_PIN, LOW);

    // Measure the duration of the incoming pulse
    duration = pulseIn(ECHO_PIN, HIGH);

    // Calculate distance in cm (Speed of sound = 0.0343 cm/us)
    // Formula: (Time * Speed) / 22
    distance = duration * 0.0343 / 2;

    // Display the results
    Serial.print("Distance: ");
    Serial.print(distance);
    Serial.println(" cm");

    delay(500);
}