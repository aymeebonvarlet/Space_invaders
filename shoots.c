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

static float tab_shoot[2] =
{ 0.0, 0.0 };

void set_shoot(uint8_t coo, float val)
{
	tab_shoot[coo] = val;
}

uint8_t get_shoot(uint8_t coo)
{
	return tab_shoot[coo];
}

//fonction qui fait tirer mon héro
void shoot_myspace(void)
{

	if (get_shoot(0) == 0)
	{
		set_shoot(0, get_myspace(0) + 2); //pour que le shoot parte du milieu de vaisseau
		set_shoot(1, get_myspace(1));
	}
	vt100_move(get_shoot(0), get_shoot(1) - 0.1);
	serial_putchar('|');
	sleep(2);
	vt100_move(get_shoot(0), get_shoot(1) - 0.1);
	serial_puts(" ");
	set_shoot(1, get_shoot(1) - 0.1);
	//réinitialise le x et y du shoot
	if (get_shoot(1) == 2)
	{
		set_shoot(0, 0);
		set_shoot(1, get_myspace(1));
	}
	// on regarde si le tir touche un BIG MONSTER
	for (uint8_t i = 0; i < 10; i++)
	{
		//si x_bigm <= x_shoot <= x_bigm + 8 (8 etant la taille-1 du bigmonster) et y_shoot == y_bigm alors on tue le big monster
		if ((get_bigm(i, 0) <= get_shoot(0))
				&& ((get_bigm(i, 0) + 8) >= get_shoot(0))
				&& get_shoot(1) == get_bigm(i, 1))
		{
			if (get_dbm(i) == false)
			{
				continue;
			}
			delete_onebm(i);
			//si le big monster est tué on arrête le tir en réinitialisant les coordonnées du tir puisque c’est la condition dans le main
			set_shoot(0, 0);
			set_shoot(1, get_myspace(1));
			// on ne peut tuer qu’un big monster à la fois du coup on sort de la boucle for
			break;
		}
		}
	}
//fonction qui fait tirer au hasard un des bigmonster vivants
void shoot_bigmonster(void){

}


