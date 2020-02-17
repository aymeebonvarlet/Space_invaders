#include "vt100.h"
#include "big_monsters.h"
#include "constants.h"


uint8_t** coordonnees_bigm(uint8_t i,uint8_t coo ){
	x += i*14; //14 est la distance en x entre chaque big_monster
	y=3; // on initialise y à 3
	if (x==0){ //pour commencer après le contour
		x=1;
	}
	if (x>(80-9)){  // 9 est la taille d’un big_monster, on souhaite tjrs que le monstre soit en entier
		x=1;
		y+=3;
	}
	if (x<80){
		bmonster.tab[i][0]=x;
		bmonster.tab[i][1]=y;
	}
	else {
		x += i*14 - 80; // max x= 80, on revient à la ligne
		bmonster.tab[i][0]=x;
		bmonster.tab[i][1]=y+3; //on ajoute 3 en y pour avoir une séparation
	}
	return bmonster.tab[i][coo];
}

void init_bigm(){
	for (uint8_t i = 0 ; i<10 ; i++){
		vt100_move(coordonnees_bigm(i,0),coordonnees_bigm(i,1));
		serial_puts("|===O===|");
	}
}

void changed_bm(uint8_t pas){
	for (uint8_t i = 0 ; i<11 ; i++){
		if (dead_bm.tab[i]){
			bmonster.tab[i][0] += 1 ; // on ajoute un à la coordonnées en x
			vt100_move(coordonnees_bigm(i,0),coordonnees_bigm(i,1));
			serial_puts("|===O===|");
		}
	}
}

void delete_bm(){
	for (uint8_t i = 0 ; i<10 ; i++){
		if (dead_bm.tab[i]){
			vt100_move(coordonnees_bigm(i,0)-1,coordonnees_bigm(i,1)); //on supprime le monstre d’avant
			serial_puts("         ");
		}
	}
}

void delete_onebm(uint8_t id){
	vt100_move(coordonnees_bigm(id,0),coordonnees_bigm(id,1)); //on supprime le monstre d’avant
	serial_puts("         ");
}

void monstre_dead




