#include "serial.h"
#include "vt100.h"

void planet(void)
{
	vt100_move(2, 2);
	serial_puts("         ,MMM8&&&.");
	vt100_move(2, 3);
	serial_puts("    _...MMMMM88&&&&..._");
	vt100_move(2, 4);
	serial_puts(" .::'''MMMMM88&&&&&&'''::.");
	vt100_move(2, 5);
	serial_puts("::     MMMMM88&&&&&&     ::");
	vt100_move(2, 6);
	serial_puts("'::....MMMMM88&&&&&&....::'");
	vt100_move(2, 7);
	serial_puts("   `''''MMMMM88&&&&''''`");
	vt100_move(2, 8);
	serial_puts("   jgs   'MMM8&&&'");

}

