#include "myspace.h"
#include "vt100.h"
#include "timer.h"
#include "big_monsters.h"
#include "little_monster.h"
#include "moove_perso.h"
#include "constants.h"
#include "serial.h"
#include "shoots.h"

static bool tab_dbigm[14] =
{ true, true, true, true, true, true, true, true, true, true, true, true, true,
true }; //true = big monster vivant
static bool tab_dlittlem[10] =
{ true, true, true, true, true, true, true, true, true, true }; //false = little monster mort

void set_dbm(uint8_t id, bool val)
{
	tab_dbigm[id] = val;
}

bool get_dbm(uint8_t id)
{
	return tab_dbigm[id];
}

void set_lbm(uint8_t id, bool val)
{
	tab_dlittlem[id] = val;
}

bool get_lbm(uint8_t id)
{
	return tab_dlittlem[id];
}

static uint8_t tab_shoot[2] =
{ 0, 0 };

void set_shoot(uint8_t coo, uint8_t val)
{
	tab_shoot[coo] = val;
}

uint8_t get_shoot(uint8_t coo)
{
	return tab_shoot[coo];
}
void shoot_myspace(void)
{

	if (get_shoot(0) == 0)
	{
		set_shoot(0, get_myspace(0) + 2); //pour que le shoot parte du milieu de vaisseau
		set_shoot(1, get_myspace(1));
	}
	vt100_move(get_shoot(0), get_shoot(1) - 1);
	serial_putchar('|');
	sleep(10);
	vt100_move(get_shoot(0), get_shoot(1) - 1);
	serial_puts("  ");
	sleep(10);
	set_shoot(1, get_shoot(1) - 1);
	if (get_shoot(1) == 2)
	{
		set_shoot(0, 0);
		set_shoot(1, get_myspace(1));
	}

//	uint8_t x_shoot = get_shoot(0);
//	for (uint8_t id_bm = 0; id_bm < 11; id_bm++)
//	{
//		uint8_t c = coordonnees_bigm(id_bm, get_shoot(0));
//		if ((c >= x_shoot) && (x_shoot <= c + 8))
//		{
//			delete_onebm(id_bm);
//			tab_dbigm[id_bm] = false;
//			break;
//		}
//	}
//	for (uint8_t id_lm = 0; id_lm < 11; id_lm++)
//	{
//		uint8_t c = coordonnees_littlem(id_lm, x_shoot);
//		if ((c <= x_shoot) && (x_shoot <= c + 4))
//		{
//			delete_onelm(id_lm);
//			tab_dlittlem[id_lm] = false;
//			break;
//		}
//	}
	}


