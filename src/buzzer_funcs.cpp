// Auto PC Locker - HID Keyboard Shorcut based PC locker using Ultrasonic distance sensor
// Copyright: Jeevas Vasudevan (Free to use for anyone who needs it :))
// License: GPL
// BoM: ATTINY85 based Digistump clone, Ultrasound Distance sensor, Usb cable, Buzzer(Optional)
// Cost: All together < $10

#include <buzzer.h>

void init_buzzer() {

  pinMode(BUZZ_PIN, OUTPUT);

}

char buzzer_status() {
  if ( digitalRead(BUZZ_PIN) == HIGH )
    return(ON);
  else
    return(OFF);
}


void turn_on_buzzer() {
  digitalWrite(BUZZ_PIN, HIGH);
}

void turn_off_buzzer() {
  digitalWrite(BUZZ_PIN, LOW);
}

void toggle_buzzer() {
  if ( buzzer_status() == ON )
    turn_off_buzzer();
  else
    turn_on_buzzer();
}
