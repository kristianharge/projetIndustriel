#include "kilolib.h"

void setup() {
	set_color(RGB(1,0,0));
	delay(200);
	set_color(RGB(0,1,0));
	delay(200);
	set_color(RGB(0,0,1));
	delay(200);
	set_color(RGB(0,0,0));
	delay(200);

}
/*
void loop(){
	if(flag == 1){
		flag = 0;
		set_color(RGB(0,0,1));
		delay(1000);
		set_color(RGB(0,0,0));
		delay(200);
	}

}
*/
// Flag to keep track of new messages.
int new_message = 0;
int count = 0;
direction message_dir;

void loop()
{
	if(new_message == 1){
		switch(message_dir){
			case SOUTH:
				set_color(RGB(1,0,0));
				break;
			case NORTH_EAST:
				set_color(RGB(0,1,0));
				break;
			case NORTH_WEST:
				set_color(RGB(0,0,1));
				break;
			case NORTH:
					set_color(RGB(1,0,0));
					break;
			case SOUTH_EAST:
					set_color(RGB(0,1,1));
					break;
			case SOUTH_WEST:
					set_color(RGB(0,1,1));
					break;

			default:
				set_color(RGB(1,1,1));
				break;
		}
		delay(200);
		set_color(RGB(0,0,0));
		delay(100);
		new_message = 0;
	}
}

void message_rx(message_t *message, distance_measurement_t *distance, direction *dir)
{
    // Set the flag on message reception.
    new_message = 1;
		message_dir = *dir;
}

int main()
{
    kilo_init();
    // Register the message_rx callback function.
    kilo_message_rx = message_rx;
    kilo_start(setup, loop);

    return 0;
}
