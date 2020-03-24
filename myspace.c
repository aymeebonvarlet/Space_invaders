#include "vt100.h"
#include "serial.h"
#include "myspace.h"
#include "timer.h"

static uint8_t tab_myspace[2] =
{ }; // tab_myspace[0] = x ; tab_myspace[1] = y

void set_myspace(uint8_t val, uint8_t coo)
{
	tab_myspace[coo] = val;
}

uint8_t get_myspace(uint8_t coo)
{
	return tab_myspace[coo];
}

//fonction permettant de faire bouger mon vaisseau

void moove_myspace(signed char carac)
{ // = pernet de modifier la valeur en x du myspace
	uint8_t pas = 0;
	uint8_t x = get_myspace(0);
	if (x < 75 && carac == 'i')
	{
		vt100_move(get_myspace(0), get_myspace(1));
		serial_puts("     ");
		pas = 1;
		uint8_t new_x = get_myspace(0) + pas;
		set_myspace(new_x, 0); // on modifie la nouvelle valeur de x
		vt100_move(get_myspace(0), get_myspace(1));
		serial_puts("(-O-)");
	}
	else if (x > 2 && carac == 'a')
	{
		vt100_move(get_myspace(0), get_myspace(1));
		serial_puts("     ");
		pas = -1;
		uint8_t new_x = get_myspace(0) + pas;
		set_myspace(new_x, 0); // on modifie la nouvelle valeur de x
		vt100_move(get_myspace(0), get_myspace(1));
		serial_puts("(-O-)");

	}
	sleep(2);

	}

//initialiser mon vaisseau
void init_myspace(void)
{
	set_myspace((VT100_SCREEN_XMIN + VT100_SCREEN_XMAX) / 2, 0);
	set_myspace(VT100_SCREEN_YMAX - 3, 1);
	vt100_move(get_myspace(0), get_myspace(1));
	serial_puts("(-O-)");

}

//quand mon vaisseau est touché par le big_m
void death_myspace(void){
	uint8_t i = 3;
	while (i>0){
		vt100_move(get_myspace(0), get_myspace(1));
		serial_puts("     ");
		sleep(30);
		vt100_move(get_myspace(0), get_myspace(1));
		serial_puts("(-O-)");
		sleep(30);
		i--;
	}
}

