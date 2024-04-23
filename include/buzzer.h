#include <common.h>

// Buzzer pin
#define BUZZ_PIN 1    // Buzzer

void init_buzzer();
char buzzer_status();
void turn_on_buzzer();
void turn_off_buzzer();
void toggle_buzzer();