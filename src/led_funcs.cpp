// Auto PC Locker - HID Keyboard Shorcut based PC locker using Ultrasonic distance sensor
// Copyright: Jeevas Vasudevan (Free to use for anyone who needs it :))
// License: GPL
// BoM: ATTINY85 based Digistump clone, Ultrasound Distance sensor, Usb cable, Buzzer(Optional)
// Cost: All together < $10

#include <led.h>

void init_led() {
    pinMode(DIGI_LED, OUTPUT);
}

char led_status() {
  if ( digitalRead(DIGI_LED) == HIGH )
    return(ON);
  else
    return(OFF);
}

void turn_on_led() {
  digitalWrite(DIGI_LED, HIGH);
}

void turn_off_led() {
  digitalWrite(DIGI_LED, LOW);
}

void toggle_led() {
  if ( led_status() == ON )
    turn_off_led();
  else
    turn_on_led();
}

