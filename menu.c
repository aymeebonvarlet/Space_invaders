#include "serial.h"
#include "vt100.h"
#include "timer.h"

void planet(void)
{
	vt100_move(2, 17);
	serial_puts("         ,MMM8&&&.");
	vt100_move(2, 18);
	serial_puts("    _...MMMMM88&&&&..._");
	vt100_move(2, 19);
	serial_puts(" .::'''MMMMM88&&&&&&'''::.");
	vt100_move(2, 20);
	serial_puts("::     MMMMM88&&&&&&     ::");
	vt100_move(2, 21);
	serial_puts("'::....MMMMM88&&&&&&....::'");
	vt100_move(2, 22);
	serial_puts("   `''''MMMMM88&&&&''''`");
	vt100_move(2, 23);
	serial_puts("   jgs   'MMM8&&&'");

}

void message(void){
	vt100_move(29, 9);
	serial_puts("WELCOME TO SPACE_INVADERS");
	vt100_move(22, 12);
	serial_puts("Press the space key to start the game");
	sleep(24);
	vt100_move(22, 12);
	serial_puts("                                        ");
	sleep(24);
}

void menu(void){
	message();
	planet();
}

