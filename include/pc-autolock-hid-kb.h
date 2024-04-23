#define kbd_en_us // Keyboard Layout US
#include <DigiKeyboard.h>

#include <common.h>

#include <led.h>
#include <buzzer.h>
#include <distance_sensor.h>


#define AUTOLOCK_DISTANCE 80.0 // Seating distance from sensor (Adjust this to suit your requirements) (cm)
#define CHECK_DELAY_NEAR 1000 // Checking frequency when target is near(ms)
#define CHECK_DELAY_FAR 30000 // Checking frequency when target is far(ms)