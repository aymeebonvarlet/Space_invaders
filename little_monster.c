#include "vt100.h"
#include "big_monsters.h"

uint8_t** coordonnees_littlem(uint8_t i,uint8_t coo){
	x += i*10; //10 est la distance en x entre chaque little_monster
	y=9; // on initialise y à 3
	if (x==0){ //pour commencer après le contour
		x=1;
	}
	if (x>(80-3)){  // 3 est la taille d’un big_monster, on souhaite tjrs que le monstre soit en entier
		x=1;
		y+=3;
	}
	if (x<80){
		lmonster.tab[i][0]=x;
		lmonster.tab[i][1]=y;
	}
	else {
		x += i*10 - 80; // max x= 80
		lmonster.tab[i][0]=x;
		lmonster.tab[i][1]=y+3; //on ajoute 3 en y pour avoir une séparation
	}
	return lmonster.tab[i][coo];
}

void init_littlem(){
	for (uint8_t i = 0 ; i<10 ; i++){
		vt100_move(coordonnees_littlem(i,0),coordonnees_littlem(i,1));
		serial_puts("\O/");
	}
}

void delete_lm(){
	for (uint8_t i = 0 ; i<10 ; i++){
		vt100_move(coordonnees_bigm(i,0)-1,coordonnees_bigm(i,1)); //on supprime le monstre d’avant
		serial_puts("         ");
	}
}
void delete_onelm(uint8_t id){
	vt100_move(coordonnees_bigm(id,0),coordonnees_bigm(id,1)); //on supprime un monstre
	serial_puts("         ");
}

void changed_lm(uint8_t pas){
	for (uint8_t i = 0 ; i<15 ; i++){
		bmonster.tab[i][0] += pas ; // on ajoute un à la coordonnées en x
		vt100_move(coordonnees_bigm(i,0),coordonnees_bigm(i,1));
		serial_puts("\O/");
		}
}
