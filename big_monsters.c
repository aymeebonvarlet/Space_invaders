#include "vt100.h"
#include "big_monsters.h"
#include "constants.h"
#include "serial.h"
#include "myspace.h"
#include "shoots.h"
#include "timer.h"
#include "constants.h"

 // tab[numéro monstre][x,y]
static uint8_t tab_bigm[10][2] =
{
{ 10, 3 },
{	26,3},
{	39,3},
{	52,3},
{	65,3},
{ 10, 6 },
{	26,6},
{	39,6},
{ 52, 6 },
{ 65, 6 } };

void set_bigm (uint8_t id, uint8_t xory , uint8_t new_val){
	tab_bigm[id][xory]=new_val;
}

uint8_t get_bigm (uint8_t id, uint8_t xory){
	return tab_bigm[id][xory];
}


void init_bigm(void)
{
	for (uint8_t i = 0 ; i<10 ; i++){
		vt100_move(get_bigm(i, 0), get_bigm(i, 1));
		serial_puts("|===O===|");
	}
}

void moove_bm(uint8_t pas)
{	//boucle for pour faire bouger les 10 monstre en même temps
	for (uint8_t i = 0; i < 10; i++)
	{
		// on regarde si l'ennemi n’a pas été tué
		if (get_dbm(i)){
			// on efface l’ennemie précédent
			vt100_move(get_bigm(i, 0), get_bigm(i, 1));
			serial_puts("         ");
			// on ajoute le pas à x_ennemi pour qu’il avance
			set_bigm(i, 0, get_bigm(i, 0) + pas);
			// on regarde si x_monster < 70 sinon on ajoute 3 à y_ennemi pour l’écrire sur la ligne suivante
			if (get_bigm(i, 0) >= 70)
			{
				set_bigm(i, 1, get_bigm(i, 1) + 3);
				set_bigm(i, 0, 2);
			}

			// on met le monstre avec les nouvelles coordonnées
			vt100_move(get_bigm(i, 0), get_bigm(i, 1));
			serial_puts("|===O===|");
			// si la nouvelle valeur y_ennemi ==  y_héro on arrête le jeu
			if (get_bigm(i, 1) == get_myspace(1))
			{
				set_play(false);
			}
		else
		{}
	}
		//on efface les big_monster morts
	else
	{
		vt100_move(get_bigm(i, 0), get_bigm(i, 1));
		serial_puts("         ");
	}

	}
}



void delete_onebm(uint8_t id){
	vt100_move(get_bigm(id, 0), get_bigm(id, 1));
	serial_puts("#########");
	sleep(2);
	vt100_move(get_bigm(id, 0), get_bigm(id, 1)); //on supprime le monstre
	serial_puts("         ");
	set_dbm(id, false);
}





