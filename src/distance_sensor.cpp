// Auto PC Locker - HID Keyboard Shorcut based PC locker using Ultrasonic distance sensor
// Copyright: Jeevas Vasudevan (Free to use for anyone who needs it :))
// License: GPL
// BoM: ATTINY85 based Digistump clone, Ultrasound Distance sensor, Usb cable, Buzzer(Optional)
// Cost: All together < $10

#include <Arduino.h>
#include <distance_sensor.h>

void init_distance_sensor() {

  pinMode(TRIG_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);

}

float get_target_distance_cm() {

  float duration_us, distance_cm;

  // generate 10-microsecond pulse to TRIG pin
  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN, LOW);

  // Measure duration of pulse from ECHO pin
  duration_us = pulseIn(ECHO_PIN, HIGH);

  // Calculate the distance
  distance_cm = SOUND_SPEED_CONST_10US * duration_us;

  return (distance_cm);

}
