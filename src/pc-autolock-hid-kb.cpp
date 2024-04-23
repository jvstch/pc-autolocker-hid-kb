// Auto PC Locker - HID Keyboard Shorcut based PC locker using Ultrasonic distance sensor
// Copyright: Jeevas Vasudevan (Free to use for anyone who needs it :))
// License: GPL
// BoM: ATTINY85 based Digistump clone, Ultrasound Distance sensor, Usb cable, Buzzer(Optional)
// Cost: All together < $10
#include <led.h>
#include <buzzer.h>
#include <pc-autolock-hid-kb.h>



// Hardware setup
void initialize_peripherals() {
   init_led();
   init_buzzer();
   init_distance_sensor();
}


void play_startup_anim() {
  
  char i;
 
  for (i=0;i<5;i++) {
    toggle_led();
    toggle_buzzer();

    if (i % 2)
      DigiKeyboard.delay(80);
    else
      DigiKeyboard.delay(8);
  }
  
  turn_off_buzzer();

  for (i=0;i<3;i++){
    toggle_led();
    DigiKeyboard.delay(100);
  }

  turn_off_led();

}

void play_lock_sound() {

  char i;

  for (i=0;i<3;i++) {

    toggle_buzzer();
    if (i % 2) 
      DigiKeyboard.delay(150);
    else
      DigiKeyboard.delay(15);

  }
  
  turn_off_buzzer();

}

// Startup routine
void setup() {
  initialize_peripherals();
  DigiKeyboard.delay(2200); // Wait some time before first run, to give target time to initialize
  play_startup_anim();
}




// Main routine loop
void loop() {

  static int check_delay_ms = CHECK_DELAY_NEAR; 
  float target_distance_cm;

  target_distance_cm = get_target_distance_cm();

#ifdef DEBUG
 
  // Print the value to test
  DigiKeyboard.print("distance: ");
  DigiKeyboard.print(target_distance_cm);
  DigiKeyboard.println(" cm");

#else

  if (target_distance_cm > AUTOLOCK_DISTANCE ){
    DigiKeyboard.sendKeyStroke(KEY_Q, MOD_CONTROL_LEFT | MOD_GUI_LEFT); // Mac lock shortcut  (control + command + Q)
    DigiKeyboard.sendKeyStroke(KEY_L, MOD_GUI_LEFT); // Linux/Windows lock shortcut  (windows logo key + L)
    if (check_delay_ms == CHECK_DELAY_NEAR ) play_lock_sound(); // If moving away play the lock sound
    check_delay_ms = CHECK_DELAY_FAR; // Once locked reduce check delay to 20 secs to reduce key strokes
    
  }
  else
    check_delay_ms = CHECK_DELAY_NEAR; //Reset check delay to 2 secs on proximity

#endif

  DigiKeyboard.delay(check_delay_ms);

}
