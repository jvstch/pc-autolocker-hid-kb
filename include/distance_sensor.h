#include <common.h>

// UltraSonic sensor pins
#define TRIG_PIN 0    // TRIG pin
#define ECHO_PIN 2    // ECHO pin

#define SOUND_SPEED_CONST_10US 0.017 // 340m/sec 0.034 cm/us half of that 0.017

void init_distance_sensor();
float get_target_distance_cm();