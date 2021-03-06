#include "vt100.h"
#include "big_monsters.h"
#include "constants.h"
#include "serial.h"


void contour()
{

	for (uint8_t i = 1; i < 81; i++)
	{
		vt100_move(i, VT100_SCREEN_YMIN);
		serial_puts("#");
		vt100_move(i, VT100_SCREEN_YMAX);
		serial_puts("#");

	}
	for (uint8_t i = 1; i < 25; i++)
	{
		vt100_move(VT100_SCREEN_XMIN, i);
		serial_puts("#");
		vt100_move(VT100_SCREEN_XMAX, i);
		serial_puts("#");
	}
}
