#include "kilolib.h"

void setup() {
    // put your setup code here, will be run once at the beginning
}

void loop() {
	//test of getting a message direction
	if(get_direction() == NORTH)
		set_color(RGB(1,0,0));
}

int main() {
    kilo_init();
    kilo_start(setup, loop);

    return 0;
}
