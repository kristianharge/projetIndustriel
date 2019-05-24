#include "kilolib.h"

void setup() {
    // put your setup code here, will be run once at the beginning
}

void loop() {
}

int main() {
    kilo_init();
    kilo_start(setup, loop);

    return 0;
}
