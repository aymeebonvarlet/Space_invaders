#include "myspace.h"
#include "vt100.h"
#include "timer.h"
#include "big_monsters.h"
#include "moove_perso.h"
#include "constants.h"
#include "serial.h"
#include "random.h"
#include "scores.h"

//les monstres
static bool tab_dbigm[14] =
{ true, true, true, true, true, true, true, true, true, true, true, true, true,
true }; //true = big monster vivant


//gettes et setter de la mort des big_m
void set_dbm(uint8_t id, bool val)
{
	tab_dbigm[id] = val;
}

bool get_dbm(uint8_t id)
{
	return tab_dbigm[id];
}


//le shoot du vaisseau

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

//les shoots des monstres

static float tab_shootbm[2] =
{ 0.0, 0.0 };

void set_shootbm(uint8_t coo, float val)
{
	tab_shootbm[coo] = val;
}

uint8_t get_shootbm(uint8_t coo)
{
	return tab_shootbm[coo];
}

//pour vour si tous les bm sont morts on créer la fonction nb modifiable que dans ce fichier

static uint8_t nb_kill_bm = 0;

void set_nb_kill_bm(uint8_t val){
	nb_kill_bm=val;
}

uint8_t get_nb_kill_bm(void){
	return nb_kill_bm;
}





//on créait un pointeur pour trouver l’id random du big_m qui tire
static uint8_t variable=0;
static uint8_t *p_id_ramdom=&variable;

uint8_t get_p_id_random(void){
	return *p_id_ramdom;
}

void set_p_id_random(uint8_t new){
	*p_id_ramdom=new;
}

//fonction qui fait tirer mon héro
void shoot_myspace(void)
{

	if (get_shoot(0) == 0)
	{
		set_shoot(0, get_myspace(0) + 2); //pour que le shoot parte du milieu de vaisseau
		set_shoot(1, get_myspace(1));
	}
	set_shoot(1, get_shoot(1) - 1);
	vt100_move(get_shoot(0), get_shoot(1));
	serial_putchar('|');
	sleep(2);
	vt100_move(get_shoot(0), get_shoot(1));
	serial_puts(" ");
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
			set_nb_kill_bm(get_nb_kill_bm()+1);
			delete_onebm(i);
			set_score(1);
			//si le big monster est tué on arrête le tir en réinitialisant les coordonnées du tir puisque c’est la condition dans le main
			set_shoot(0, 0);
			set_shoot(1, get_myspace(1));
			// on ne peut tuer qu’un big monster à la fois du coup on sort de la boucle for
			break;
		}
	}
}
//fonction qui fait tirer au hasard un des bigmonster vivants
void shoot_bigmonster(uint8_t id_bigm)
{

	//on vérifie que le monstre est encore vivant sinon en relance la fonction
	while (!tab_dbigm[id_bigm])
	{
		set_p_id_random(rand() % 10);
		id_bigm=get_p_id_random();

	}

	//on initialise le shoot
	if (get_shootbm(0) == 0)
	{
		set_shootbm(0, get_bigm(id_bigm, 0) + 4); // + 4 pour que le shoot parte au milieu du monstre
		set_shootbm(1, get_bigm(id_bigm, 1) + 1);
	}

	set_shootbm(1, get_shootbm(1) + 1);
	for (uint8_t i=0; i < 10; i++)
	{
		if (get_shootbm(1) == get_bigm(i, 1) && get_shootbm(0) >= get_bigm(i, 0)
				&& get_shootbm(0) <= (get_bigm(i, 0) + 8) && tab_dbigm[i]==true)
		{
			set_shootbm(1, get_shootbm(1) + 1);
		}
	}
	vt100_move(get_shootbm(0), get_shootbm(1));
	serial_putchar('|');
	sleep(2);
	vt100_move(get_shootbm(0), get_shootbm(1));
	serial_puts(" ");
	//on vérifie de ne pas écrater un bigmonster


	//réinitialise le x et y du shoot à la fin
	if (get_shootbm(1) == 23)
	{
		set_shootbm(0, 0);
		set_shootbm(1, get_bigm(id_bigm, 1));
	}
	//si le shoot a touché notre vaisseau
	if (get_shootbm(1) == get_myspace(1) && get_shootbm(0) >= get_myspace(0)
			&& get_shootbm(0) <= (get_myspace(0) + 4))
	{
		death_myspace();
		set_life_myspace(-1);
		if (get_life_myspace() == 0)
		{
			set_play(false);
		}
	}
}



