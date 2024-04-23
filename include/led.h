#include <common.h>
//Led pin
#define DIGI_LED 0 // Select the pin where the led is attached

void init_led();
char led_status();
void turn_on_led();
void turn_off_led();
void toggle_led();