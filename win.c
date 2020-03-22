#include "serial.h"
#include "vt100.h"
#include "timer.h"
#include "menu.h"

void win(void){
	planet();
	vt100_move(40, 9);
	serial_puts("WIN");
}



